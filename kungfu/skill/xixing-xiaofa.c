#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force)
{
        return 1;
}

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("xixing-xiaofa", 1);
        return lvl * lvl * 15 * 2 / 100 / 200;
}

int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 80)
                return notify_fail("��Ļ����ڹ�����㣬����ѧ�������С����\n");

        if (me->query("gender") == "����" && (int)me->query_skill("xixing-xiaofa", 1) > 99)
                return notify_fail("���޸���������������������������������С����\n");

        if ((int)me->query_skill("force", 1) < (int)me->query_skill("xixing-xiaofa", 1))
                return notify_fail("��Ļ����ڹ�ˮƽ���ޣ���������������������С����\n");

        return ::valid_learn(me);
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp;
        int jiali;

        if ((int) me->query_skill("xixing-xiaofa", 1) < 80 ||
            ! living(me))
                return;

        if ((jiali = ob->query("jiali")) < 1)
                return;

        ap = ob->query_skill("force");
        dp = me->query_skill("force");
        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage" : -damage ]);

                switch (random(3))
                {
                case 0:
                        result += ([ "msg" : HIM "$N" HIM "ֻ��������ԴԴ��к"
                                             "��ת����£����ɵô��һ����\n" NOR ]);
                        break;
                case 1:
                        result += ([ "msg" : HIM "$N" HIM "ֻ���÷�����������"
                                             "��ʯ���󺣣���$n����ת����¡�\n" NOR ]);
                        break;

                default:
                        result += ([ "msg" : HIM "$N" HIM "��ס�߶�����������"
                                             "ֻ����$n���ƺ���������\n" NOR ]);
                        break;
                }
                return result;
        }
}

int practice_skill(object me)
{
        return notify_fail("�������С��ֻ����ѧ(learn)�������������������ȡ�\n");
}

string exert_function_file(string func)
{
        // Ϊ��NPC�������ܹ�ʩչ��������POWERUP�������趨Ϊ������
        return __DIR__"tianhuan-shenjue/" + func;
}
