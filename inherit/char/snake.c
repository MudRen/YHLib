// Inherit: snake.c ����
// Update by Vin for Heros.cn
// ���ö��߶���level�Ͷ�Һ����remain/maximum������ÿ��ҧ�ж�
// �������Ὣperhit ָ���Ķ���ע�뵽�Է������ڣ�ÿ��һ��ʱ��
// ���߻��Զ��ָ�supply ���Ķ�Һ��level�����书��force���Ƚϡ�
// ����levelʱ��Ӧ�òο��ڹ��ȼ����������ж�UPDATE_CONDITION
// �Ĵ��������ȣ����ö�����ʱ��Ӧ�òο����;���

#include <ansi.h>
inherit NPC;

int is_snake()
{
	return 1;
}

void setup()
{
        mapping p;

        set("race", "Ұ��");
        set("unit", "��");
        set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }));
        set("verbs", ({ "bite" }));
        set("attitude", "aggressive");

        p = this_object()->query("snake_poison");

        if (! p)
        {
                ::setup();
                return;
        }

        if (! intp(p["level"]))   p["level"]   = 30;
        if (! intp(p["perhit"]))  p["perhit"]  = 10;
        if (! intp(p["maximum"])) p["maximum"] = 20;
        if (! intp(p["remain"]))  p["remain"]  = p["maximum"];
        if (! intp(p["supply"]))  p["supply"]  = 1;
        if (! stringp(p["id"]))   p["id"]      = "nature snake";

        ::setup();
}

void init()
{
        object me, ob;

        ::init();
        if (! interactive(me = this_player()))
                return;

        // �Զ������߶����ɵȼ����ߵ����
        if ((int)me->query_skill("shedu-qiqiao", 1) < 100)
        {
                remove_call_out("kill_ob");
                call_out("kill_ob", 0, me);
        }

        remove_call_out("disappear");
        call_out("disappear", 15);
}

mixed hit_ob(object me, object ob, int damage)
{
        mapping p;
        string  msg;
        int force;
        int dur;

        p = me->query("snake_poison");
        if (! p) return;
        if (damage / 3 + random(damage * 2 / 3) <
            (int)ob->query_temp("apply/armor"))
        {
                // Defeated by armor
                return;
        }

        msg = "";
        dur = p["perhit"];
        if (dur > (int)p["remain"]) dur = p["remain"];
        p["remain"] = (int)p["remain"] - dur;
        this_object()->apply_condition("poison-supply", 1);
        if (! dur) return;

        force = (int)ob->query_skill("force");
        if (random(force / 2) + force / 2 >= (int)p["level"] &&
            ob->query("neili") > damage / 5)
        {
                if (ob->query("qi") < 150)
                {
                        msg = HIR "������˿���Щ���飬��æ�˹����⣬��"
                              "��һʱ������֧������ʩΪ��\n" NOR;
                } else
                if (ob->query("jing") < 60)
                {
                        msg = HIR "������˿���Щ���飬��æ�˹����⣬��"
                              "��һʱ���񲻼ã�����ʩΪ��\n" NOR;
                } else
                if (ob->query("neili") < damage / 5 + 50)
                {
                        msg = HIR "������˿���Щ���飬��æ�˹����⣬��"
                              "��һʱ�������㣬����ʩΪ��\n" NOR;
                } else
                {
                        ob->add("neili", -damage / 5);
                        ob->receive_damage("qi", 20);
                        ob->receive_damage("jing", 10);
                        return HIM "����ñ�ҧ�еĵط���Щ���飬��æ�˹�"
                               "���ⶾ�ԡ�\n" NOR;
                }
        }

        if (ob->affect_by("poison", ([ "level" : (int)p["level"],
                                       "name"  : "�߶�",
                                       "id"    : "nature poison",
                                       "duration" : dur, ])))
        {
                msg += HIR "$n" HIR "��ɫһ�䣬ֻ����ҧ�еĵط�һ����ľ��\n" NOR;
        }
        return msg;
}

void die(object killer)
{
        object me, item;
        object ob = this_object();
        int power, skill;
        string msg;

        message_vision(HIR "\nֻ��$N" HIR "���������ڵ���������"
                       "���£����ˡ�\n\n" NOR, ob);

        if (objectp(me = killer)
           || objectp(me = query_last_damage_from()))
        {
                // ���Ϊ�Լ����������֮
                if (ob->query("owner") == me->query("id")
                   && me->query("combat_exp") <= 500000)
                {
                        // ���������趨�Ĳ��������轱��
                        power = ob->query("power");

                        if (power < 5)
                                power = 5;

                        if (power > 500)
                                power = 500;

                        GIFT_D->delay_bonus(me, ([ "prompt" : "ͨ�������ȡ" + ob->name() +
                                                              HIG "�ľ���",
                                                   "exp"    : random(power) + power,
                                                   "pot"    : random(power / 3) + power / 3,
                                                   "score"  : random(power / 4), ]));
                }
                skill = me->query_skill("hunting", 1);

                // �����Ʒ
                if (ob->query("item1") && random(skill) > 10)
                {
                        item = new(ob->query("item1"));
                        item->move(me, 1);

                        msg = HIC "����ϸ��Ѱ" + ob->name() +
                              HIC "��ʬ�壬�����������һ" +
                              item->query("base_unit") +
                              item->name() + HIC;

                        // һ�����ʻ�ø߼���Ʒ
                        if (ob->query("item3") && random(skill) > 60
                           && random(5) > 3)
                        {
                                item = new(ob->query("item3"));
                                item->move(me, 1);

                                msg += "��һ" + item->query("base_unit") +
                                       item->name() + HIC;
                        } else
                        if (ob->query("item2") && random(skill) > 30
                           && random(4) > 2)
                        {
                                item = new(ob->query("item2"));
                                item->move(me, 1);

                                msg += "��һ" + item->query("base_unit") +
                                       item->name() + HIC;
                        }
                        msg += "��\n\n" NOR;
                        tell_object(me, msg);
                }
        }
        destruct(ob);
}
