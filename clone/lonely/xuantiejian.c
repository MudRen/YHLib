#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(NOR + WHT "�����ؽ�" NOR, ({ "xuantie jian", "xuantie", "jian" }) );
        set_weight(28000);
        if (clonep())
                destruct(this_object());
        else {
                set("long", NOR + WHT "һ�����������ɵ��޷泤�������ֳ����ޱȣ�����ȴ�̲��ż����������\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", NOR + WHT "$N" NOR + WHT "���$n" NOR + WHT"���̽��������������ݣ�������Ȼ�𾴡�\n" NOR);
                set("unwield_msg", NOR + WHT "$N" NOR + WHT "���쳤̾��Ǳ����������$n" NOR + WHT "�ջء�\n" NOR);
                set("stable", 100);
                set("skill", ([
                        "name"         : "xuantie-jian",
                        "exp_required" : 500000,
                        "jing_cost"    : 100,
                        "difficulty"   : 100,
                        "min_skill"    : 0,
                        "max_skill"    : 30,
                ]));
        }
        init_sword(180);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int ap, dp;
        object weapon;
        string msg;

        if (me->query_skill_mapped("sword") != "xuantie-jian" ||
            me->query_skill("xuantie-jian", 1) < 200 ||
            me->query("neili") < 300)
                return damage_bonus / 2;

        ap = me->query_skill("sword");
        dp = victim->query_skill("parry");

        me->start_busy(1 + random(4));

        if (ap / 2 + random(ap) > dp)
        {
                
                victim->receive_damage("qi", ap * 3 / 4, me);
                victim->receive_wound("qi", ap * 3 / 4, me);

                if (! objectp(weapon = victim->query_temp("weapon")) ||
                      weapon->query("skill_type") == "pin" || 
                      (objectp(weapon = victim->query_temp("weapon")) && // ����쾧��ĥ��
                       weapon->is_item_make() && weapon->query("material") == "tian jing"))
                            return HIR "$N" HIR "�߶�����������" + this_object()->name() + HIR
                                   "��������һ�㣬���صؿ���$n" HIR "���ϣ�\n" NOR;

                if (weapon->query("consistence") > 10 ||
                    weapon->is_item_make())
                {
                      msg = HIR "$N" HIR "�߶�����������"+ this_object()->name() + HIR "��������һ"
                            "�㣬��Ȼ��ת�����صؿ���$n" HIR "��" + weapon->name() + HIR
                            "�ϣ�\nֻ���á���~~����һ����" + weapon->name() + HIR "��ʱ��"
                            "���䣬$n" HIR "ֻ�����ؿ���Ѫ���ڲ�Ϣ��\n" NOR;
                      
                      weapon->is_item_make() ? weapon->add("consistence", -1)
                                             : weapon->add("consistence", -10);

                      tell_object(victim, HIG "���" + weapon->name() + HIG "�ܵ������ص����ˣ�\n");
                      
                      return msg;
                    
                }

                // ������������
                msg = HIR "$N" HIR "�߶�����������"+ this_object()->name() + HIR "��������һ"
                "�㣬����$n" HIR "��" + weapon->name() + HIR
                "�ϣ�\nֻ���á���~~����һ����" + weapon->name() + HIR "��ʱ��Ϊ���ء�\n" NOR;

                weapon->set_name("�ϵ���" + weapon->name() + NOR);
                weapon->set("no_wield", 1);
                weapon->move(environment(me));

                return msg;
        }                 
        return damage_bonus;
}
