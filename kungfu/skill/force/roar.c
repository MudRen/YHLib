// roar.c
// By Vin for heros.cn

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int f, i, skill, damage;
        string msg;

        f = me->query_skill_mapped("force");
        skill = me->query_skill("force");

        if (me->query_skill_mapped("force") != "longxiang-gong"
           && me->query_skill_mapped("force") != "tianhuan-shenjue"
           && me->query_skill_mapped("force") != "huntian-qigong"
           && me->query_skill_mapped("force") != "jiuyang-shengong"
           && me->query_skill_mapped("force") != "jiuyin-shengong"
           && me->query_skill_mapped("force") != "kuihua-mogong"
           && me->query_skill_mapped("force") != "xixing-dafa"
           && me->query_skill_mapped("force") != "zhanshen-xinjing"
           && me->query_skill_mapped("force") != "yijinjing"
           && me->query_skill_mapped("force") != "hunyuan-gong")
                return notify_fail("����ѧ���ڹ���û�����ֹ��ܡ�\n");

        if (skill < 180)
                return notify_fail("����ڹ���Ϊ������\n");

        if (environment(me)->query("no_fight"))
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

        // ִ��������������ⷿ���ֹ�����жϾ��顣
        if (environment(me)->query("skybook"))
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

        if ((int)me->query("neili") < 800)
                return notify_fail("�������������\n");

        me->add("neili", -300);

        me->start_busy(5);

        switch (f)
        {
        case "longxiang-gong" :
                msg = HIW "$N" HIW "��ת���������ޱ��飬�������󳪰�"
                      "�������˶��С�\n" NOR;
                break;

        case "huntian-qigong" :
                msg = HIY "$N" HIY "��������һ������������������һ��"
                      "��Х�����������������\n" NOR;
                break;

        case "jiuyang-shengong" :
                msg = HIY "$N" HIY "���쳤Х�������಴�����������޲�"
                      "�����ĳ���ҡ��\n" NOR;
                break;

        case "jiuyin-shengong" :
                msg = HIY "$N" HIY "���������Ȼһ���Ϻȣ�����ԶԶ"
                      "�Ĵ��˿�ȥ��������ֹ��\n" NOR;
                break;

        case "kuihua-mogong" :
                msg = HIY "$N" HIY "��ؼ�˻��������������֮��������"
                      "ë���Ȼ��\n" NOR;
                break;

        case "yijinjing" :
        case "hunyuan-gong" :
                msg = HIY "$N" HIY "��������һ��������������ʨ�Ӻ�"
                      "���������춯�ص�һ���޺�\n" NOR;
                break;

        default:
                msg = HIY "$N" HIY "��������һ����������" + to_chinese(f) +
                      HIY "��������ŷ�����Ȼһ����Х��\n" NOR;
                break;
        }
        msg += "\n";
        message_combatd(msg, me);

        ob = all_inventory(environment(me));

        for (i = 0; i < sizeof(ob); i++)
        {

                if (! living(ob[i]) || ob[i] == me)
                        continue;

                if (skill / 2 + random(skill / 2) < (int)ob[i]->query("con") * 2)
                        continue;

                // ��������������Ҳ����˺�
                if ((int)ob[i]->query_condition("die_guard"))
                        continue;

                damage = skill - ((int)ob[i]->query("max_neili") / 10);

                if (damage > 0)
                {
                        ob[i]->receive_damage("jing", damage * 2, me);

                        if ((int)ob[i]->query("neili") < skill * 2)
                                ob[i]->receive_wound("jing", damage, me);

                        tell_object(ob[i], HIR "ͻȻ����ֻ������һ���������ǰ��"
                                           "����ð������ͷ����Ҫ�ѿ�һ�㡣\n" NOR);

                        switch (random(3))
        		{
        		case 0 :
                		msg = WHT "ͻȻֻ��" + ob[i]->name() + WHT "����"
                                      "��ͷ��˫Ŀ͹������Ƿ���Щ���ĭ����������"
                                      "���졣\n" NOR;
                		break;

		        case 1 :
                		msg = WHT "��ʱ����" + ob[i]->name() + WHT "һ��"
                                      "�ҽУ����۷�ֱ��ȫ��ס���������Ż��һ��"
                                      "��Ѫ��\n" NOR;
                		break;

		        default :
                		msg = WHT "ȴ��" + ob[i]->name() + WHT "��ˤ����"
                                      "�أ���������������˫Ŀ˫�����ǿ׾�����˿˿"
                                      "��Ѫ��\n" NOR;
                		break;
        		}
                        message("vision", msg, environment(ob[i]), ({ob[i]}));

                        if ((int)ob[i]->query("jing") < 1
                           || (int)ob[i]->query("eff_jing") < 1)
                                ob[i]->unconcious(me);

                        if (objectp(ob[i]) && ! living(ob[i]))
                        {
                                ob[i]->add("jing", 10);
                                ob[i]->add("eff_jing", 10);
                        }
                }
                me->want_kill(ob[i]);
                me->fight_ob(ob[i]);
                ob[i]->kill_ob(me);
        }
        return 1;
}
