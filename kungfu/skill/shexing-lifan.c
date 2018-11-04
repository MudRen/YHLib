inherit SKILL;
#include <ansi.h>

string *dodge_msg = ({
        "ֻ��$n��Хһ�����������ϱ�ֱ���������࣬�����$N��һ�С�\n",
        "$n����Ʈ���������ޱȣ��������һ�ݣ����ѱܿ���\n",
        "ֻ��$n��������ת����ͬˮ��һ�㣬ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
        "����$n�ŵ�һ���ͷ�������һ�ã�$N��һ�����˸��ա�\n",
        "ȴ��$n�����ڶ����㲻��أ����Դܿ����ߣ����˿�ȥ��\n",
        "$n����Ծ���ڰ����һ������������һ�Σ��о����յرܿ���$N��һ�С�\n"

});

int valid_enable(string usage) 
{ 
        return (usage == "dodge") || (usage == "move"); 
}

mapping *action = ({
([      "action":"$N���к�������ת������ͬˮ��һ�㣬��������Ծ���ڰ����һ����������ʽ����֮��"
]),
});

mapping query_action(object me, object weapon)
{
        return action[0];
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 150)
                return notify_fail("�������̫���ˣ�������ϰ�����귭��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�������̫���ˣ�������ϰ�����귭��\n");

        me->receive_damage("qi", 100);
        me->add("neili", -150);
        return 1;
}
mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp;

        if ((int)me->query_skill("shexing-lifan", 1) < 100 ||
            ! living(me))
                return;

        mp = ob->query_skill("count", 1);
        ap = ob->query_skill("dodge") + mp;
        dp = me->query_skill("dodge", 1) * 2 / 5 +
             me->query_skill("shexing-lifan", 1);

        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage": -damage ]);

                switch (random(3))
                {
                case 0:
                        result += (["msg" : HIW "$n" HIW "����Ʈ���������ޱȣ�$N" HIW
                                            "�پ���ǰ������ǧ�����о�Ȼ��ա�\n" NOR]);
                        break;
                case 1:
                        result += (["msg" : HIW "$n" HIW "��Ȼ����Ծ���ڰ����һ��������"
                                            "���ܿ���$N" HIW "���С�\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIW "$N" HIW "һ�й�����$n" HIW "������ת����"
                                            "������һ�㣬���ɵرܿ���$N" HIW "���У���$N" HIW 
                                            "������ĥ��\n" NOR]);
                        break;
                }
                return result;
        } else
        if (mp >= 100)
        {
                switch (random(4))
                {
                case 0:
                        result = HIY "����$n" HIY "����Ʈ�������������ޱȣ�"
                                 "��ʱ����������Ӱ�������ۻ����ҡ�����$N"
                                 HIY "��ʽȴ�Ǻ���ͣ�ͣ�����ʩչ��\n" NOR;
                        break;
                case 1:
                        result = HIY "$n" HIY "��Ȼ����Ծ���ڰ����һ��������Ȼ��$N"
                                 HIY "���ѿ���������ʵ����ʽ��ת��Ϯ��$n" HIY "��\n" NOR;
                        break;

                default:
                        result = HIY "����$n" HIY "������ת����������һ�㣬����������ĥ��$N"
                                 HIY "΢΢һЦ����ʽ��Ȼ�ӿ졣\n" NOR;
                        break;
                }
                COMBAT_D->set_bhinfo(result);
        }
}



string perform_action_file(string action)
{
        return __DIR__"shexing-lifan/" + action;
}
