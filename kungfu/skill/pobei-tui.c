inherit SKILL;

mapping *action = ({
([      "action" : "$N˫����Σ�����͵ط���һʽ����ɽ�ȡ�������$n��$l",
        "force" : 80,
        "attack": 10,
        "dodge" : 15,
        "parry" : 15,
        "damage": 10,
        "lvl"   : 0,
        "damage_type" : "����",
        "skill_name"  : "��ɽ��"
]),
([      "action" : "$N��Ŷٵأ�������ת���ҽ�һʽ�������ȡ�������$n��$l",
        "force" : 100,
        "attack": 20,
        "dodge" : 20,
        "parry" : 20,
        "damage": 15,
        "lvl"   : 30,
        "damage_type" : "����",
        "skill_name"  : "������"
]),
([      "action" : "$N�ҽŷ�һ���߳���������׼��һʽ����ʯ�ȡ��������$n",
        "force" : 140,
        "attack": 30,
        "dodge" : 25,
        "parry" : 25,
        "damage": 18,
        "lvl"   : 60,
        "damage_type" : "����",
        "skill_name"  : "��ʯ��"
]),
([      "action" : "$N˫������Ȧת��һʽ���ѵ��ȡ�������糾������$n��ȫ��",
        "force" : 160,
        "attack": 35,
        "dodge" : 30,
        "parry" : 30,
        "damage": 20,
        "lvl"   : 90,
        "damage_type" : "����",
        "skill_name"  : "�ѵ���"
]),
([      "action" : "$N˫�Ž�������һʽ�������ȡ����ŽŲ���$n����������",
        "force" : 180,
        "attack": 35,
        "dodge" : 40,
        "parry" : 40,
        "damage": 25,
        "lvl"   : 120,
        "damage_type" : "����",
        "skill_name"  : "������"
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; } 

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���Ʊ��ȱ�����֡�\n");

        if ((int)me->query_skill("force") < 40)
                return notify_fail("����ڹ���򲻹����޷�ѧ�Ʊ��ȡ�\n");

        if ((int)me->query_skill("unarmed", 1) < 20)
                return notify_fail("��Ļ���ȭ�Ż�򲻹����޷�ѧ�Ʊ��ȡ�\n");

        if ((int)me->query_skill("unarmed", 1) < (int)me->query_skill("pobei-tui", 1))
                return notify_fail("��Ļ���ȭ��ˮƽ���ޣ��޷�����������Ʊ��ȡ�\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
            if(level >= action[i]["lvl"])
               return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("pobei-tui", 1);
        for(i = sizeof(action); i > 0; i--)
            if(level > action[i-1]["lvl"])
                return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 100)
               return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 80)
               return notify_fail("��������������Ʊ��ȡ�\n");

        me->receive_damage("qi", 80);
        me->add("neili", -60);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"pobei-tui/" + action;
}
