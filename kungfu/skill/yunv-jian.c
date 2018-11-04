inherit SKILL;

mapping *action = ({
([      "action" : "$Nһ�С���ҶƮ�ɡ�������б�ɣ�����$w�������$n��$l",
        "force"  : 75,
        "dodge"  : 28,
        "damage" : 12,
        "lvl"    : 0,
        "damage_type" : "����"
]),
([      "action" : "$N��Ծ���𣬡����ƾ��졹��$w��Ȼ�´�",
        "force"  : 70,
        "dodge"  : 15,
        "damage" : 15,
        "lvl"    : 10,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ�����˼����ġ����ӽ�ֱ���������ɵ�",
        "force"  : 90,
        "dodge"  : 25,
        "damage" : 20,
        "lvl"    : 20,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ�������ǿա�һ�����϶��²�����ģ����ֺ�ա�����̵صĹ⾰",
        "force"  : 110,
        "dodge"  : 24,
        "damage" : 27,
        "lvl"    : 30,
        "damage_type" : "����"
]),
([      "action" : "$N����$w���������ʻ���չ���ػ�����ֻ�ϵ�$n�ۻ����ң��벻֪�Ӻι���",
        "force"  : 130,
        "dodge"  : 25,
        "damage" : 32,
        "lvl"    : 45,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ�����˼����ġ��������𣬽�����ָ�����������ƣ�ֱ��$n��$l",
        "force"  : 150,
        "dodge"  : 32,
        "damage" : 40,
        "lvl"    : 60,
        "damage_type" : "����"
]),
([      "action" : "$N����$w��������һ�̣�������������ʹ�������ٰ�������",
        "force"  : 170,
        "dodge"  : 42,
        "damage" : 48,
        "lvl"    : 75,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) 
{ 
        return usage == "sword" || usage == "parry"; 
}

int valid_learn(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query_skill("sword", 1) < 15)
                return notify_fail("��Ļ�������ˮƽ̫�ͣ��޷�ѧϰ��Ů������\n");

        if (me->query_skill("sword", 1) < me->query_skill("suxin-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷������������Ů������\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;  
        level = (int) me->query_skill("yunv-jian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];

}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 35)
                return notify_fail("���������������Ů������\n");

        if ((int)me->query("neili") < 30)
                return notify_fail("�����������������Ů������\n");

        me->receive_damage("qi", 25);
        me->add("neili", -20);

        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"yunv-jian/" + action;
}
