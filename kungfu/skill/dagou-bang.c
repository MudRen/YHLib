#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$Nʹ��һ�С�����˫Ȯ��������$w���������������$n��$l",
        "force" : 280,
        "attack": 98,
        "dodge" : 120,
        "parry" : 100,
        "damage": 80,
        "damage_type": "����"
]),
([      "action": "$N����$w���һζ���һ�С�����Ѱ�ߡ���$n��$l��ȥ",
        "force" : 300,
        "attack": 100,
        "dodge":  100,
        "parry" : 120,
        "damage": 100,
        "damage_type": "����"
]),
([      "action": "$N����$w���Ӹ�����ʹһ�С���ݾ��ߡ�����$n��$l",
        "force" : 290,
        "attack": 99,
        "dodge":  120,
        "parry" : 100,
        "damage": 70,
        "damage_type": "����"
]),
([      "action": "$Nʩ�����������졹��$w����������$n��ȥ",
        "force" : 310,
        "attack": 105,
        "dodge" : 80,
        "parry" : 140,
        "damage": 90,
        "damage_type": "����"
]),
});

int valid_enable(string usage)
{
        return usage == "staff" || usage == "parry";
}

int valid_learn(object me)
{
        if (me->query("dex") < 26)
                return notify_fail("���������̫��޷�ѧϰ�򹷰�����\n");

        if ((int)me->query("max_neili") < 1500)
                return notify_fail("���������Ϊ���㣬�޷�ѧϰ�򹷰�����\n");

        if ((int)me->query_skill("staff", 1) < 100)
                return notify_fail("��Ļ����ȷ��������޷�ѧϰ�򹷰�����\n");

        if ((int)me->query_skill("staff", 1) < (int)me->query_skill("dagou-bang", 1))
                return notify_fail("��Ļ����ȷ�ˮƽ���ޣ��޷���������Ĵ򹷰�����\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp;

        if ((int) me->query_skill("dagou-bang", 1) < 100
           || ! me->query_temp("feng_zijue")
           || ! (weapon = me->query_temp("weapon"))
           || ! living(me)
           || weapon->query("skill_type") != "staff")
                return;

        mp = ob->query_skill("count", 1);
        ap = ob->query_skill("force") + mp;
        dp = me->query_skill("parry", 1) / 2 +
             me->query_skill("dagou-bang", 1);

        if (ap / 2 + random(ap) < dp * 3 / 4)
        {
                result = ([ "damage": -damage ]);

                switch (random(2))
                {
                case 0:
                        result += (["msg" : HIG "$n" HIG "�����ʩչ�򹷰���" HIY "��"
                                            HIG "���־�������" + weapon->name() + HIG
                                            "����ұգ�ʹ��$N" HIG "�Ĺ���ȫȻ��ա�\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIG "$n" HIG "��ת����" + weapon->name() +
                                            HIG "���򹷰���" HIY "��" HIG "���־�����"
                                            "�����쾡�£��ٽ�$N" HIG "����ʽ�������Ρ�\n" NOR]);
                        break;
                }
                return result;
        } else
        if (mp >= 100)
        {
                switch (random(2))
                {
                case 0:
                        result = HIY "$n" HIY "���ʩչ���򹷰����⡹��"
                                 "��������$N" HIY "��Ҳ������������ֱ"
                                 "�룬��Ϯ$n" HIY "��\n" NOR;
                        break;
                default:
                        result = HIY "$n" HIY "��ת����" + weapon->name() +
                                 HIY "������ұգ�Ȼ��$N" HIY "ȴ�Ǿ���"
                                 "������˿������$n" HIY "���Ի�\n"  NOR;
                        break;
                }
                COMBAT_D->set_bhinfo(result);
        }
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "staff")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 80)
                return notify_fail("��������������򹷰�����\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("��������������򹷰�����\n");

        me->receive_damage("qi", 75);
        me->add("neili", -80);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"dagou-bang/" + action;
}
