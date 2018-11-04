inherit SKILL;

mapping *action = ({
([      "action" : "$N�ص����գ�һ�С��̺����졹���������¶��ϻ��˸��뻡����$n��$l��ȥ",
        "force" : 10,
        "attack": 18,
        "dodge" : 1,
        "parry" : 5,
        "damage": 10,
        "lvl" : 0,
        "skill_name" : "�̺�����",
        "damage_type" : "����"
]),
([      "action" : "$N�����������⣬һ�С������ġ�������$w��ֱ����$n��$l",
        "force" : 30,
        "attack": 16,
        "dodge" : 3,
        "parry" : 7,
        "damage": 12,
        "lvl" : 20,
        "skill_name" : "������",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С������翡���$w�ƾ�������ˢ��һ�����϶�����$n����",
        "force" : 53,
        "attack": 19,
        "dodge" : 2,
        "parry" : 13,
        "damage": 17,
        "lvl" : 40,
        "skill_name" : "������",
        "damage_type" : "����"
]),
([      "action" : "$N���ַ�ִ������һ�С��̱�����������һ����$wֱ��$n�ľ���նȥ",
        "force" : 61,
        "attack": 27,
        "dodge" : 5,
        "parry" : 19,
        "damage": 25,
        "lvl" : 60,
        "skill_name" : "�̱�����",
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С�������ɢ�����������⻯����㷱�ǣ���$n��$l��ȥ",
        "force" : 80,
        "attack": 52,
        "dodge" : 10,
        "parry" : 11,
        "damage": 30,
        "lvl" : 80,
        "skill_name" : "������ɢ",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("force") < 50)
                return notify_fail("����ڹ���򲻵����޷�ѧϰ���̵�����\n");

        if (me->query("max_neili") < 350)
                return notify_fail("�������̫��޷�ѧϰ���̵�����\n");

        if ((int)me->query_skill("blade", 1) < 30)
                return notify_fail("��Ļ����������̫ǳ���޷�ѧϰ���̵�����\n");

        if (me->query_skill("blade", 1) < me->query_skill("biyan-dao", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������ı��̵�����\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action) - 1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("biyan-dao", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon")) || 
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 40)
                return notify_fail("����������������̵�����\n");

        if ((int)me->query("neili") < 30)
                return notify_fail("����������������̵�����\n");

        me->receive_damage("qi", 35);
        me->add("neili", -20);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"biyan-dao/" + action;
}
