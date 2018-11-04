inherit SKILL;

mapping *action = ({
([      "action": "$N˫�ֲ�ס�غ���������ֱ۹ؽڿ������죬����һ��������ž��һ�³�$n$l��ȥ",
        "force" : 100,
        "attack": 18,
        "dodge" : 30,
        "parry" : 15,
        "damage": 40,
        "lvl"   : 0,
        "damage_type": "����"
]),
([      "action": "$N���δ춯���������������ų�$n�������ƣ�һ�ƿ���һ�ƣ�һ������һ��",
        "force" : 200,
        "attack": 25,
        "dodge" : 40,
        "parry" : 30,
        "damage": 45,
        "lvl"   : 30,
        "damage_type": "����"
]),
([      "action": "$N���ر�צΪ�ƣ����Ӳ������ұ۶�����Ǳ��������һ�Ƴ�$n$l��ȥ",
        "force" : 250,
        "attack": 35,
        "dodge" : 50,
        "parry" : 55,
        "damage": 45,
        "lvl"   : 60,
        "damage_type": "����"
]),
([      "action": "$Nһ����Х������Ʈ�磬����������е�ֿ������$n����δ������������Ѹ���Ѽ�",
        "force" : 290,
        "attack": 42,
        "dodge" : 70,
        "parry" : 75,
        "damage": 43,
        "lvl"   : 90,
        "damage_type": "����"
]),
});

int valid_enable(string usage)
{
	return usage == "strike" || usage == "parry";
}

int valid_combine(string combo)
{
	return combo == "wusheng-zhao";
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("tianchan-zhang", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������Ʊ�����֡�\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("����ڹ���򲻹����޷�������ơ�\n");

        if ((int)me->query("max_neili") < 450)
                return notify_fail("�������̫�����޷�������ơ�\n");

        if (me->query_skill("strike", 1) < me->query_skill("tianchan-zhang", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷��������������ơ�\n");

        return 1;
}


int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("�������̫���ˣ�����Ϣһ�°ɡ�\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("�����������������ơ�\n");

        if (me->query_skill("tianchan-zhang", 1) < 50)
                me->receive_damage("qi", 30);
        else
                me->receive_damage("qi", 35);

        me->add("neili", -54);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tianchan-zhang/" + action;
}

