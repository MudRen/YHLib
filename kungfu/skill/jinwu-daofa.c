inherit SKILL;

mapping *action = ({
([      "action" : "$N�ص����գ�һ�С�����鮵������������¶��ϻ��˸��뻡����$n��$l��ȥ",
        "force" : 20,
        "attack": 28,
        "dodge" : 1,
        "parry" : 5,
        "damage": 10,
        "lvl" : 0,
        "skill_name" : "����鮵�",
        "damage_type" : "����"
]),
([      "action" : "$N�����������⣬һ�С�÷ѩ���ġ�������$w��ֱ����$n��$l",
        "force" : 30,
        "attack": 36,
        "dodge" : 3,
        "parry" : 10,
        "damage": 15,
        "lvl" : 20,
        "skill_name" : "÷ѩ����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�ǧ��ѹ�ա���$w�ƾ�������ˢ��һ�����϶�����$n����",
        "force" : 40,
        "attack": 43,
        "dodge" : 2,
        "parry" : 13,
        "damage": 20,
        "lvl" : 40,
        "skill_name" : "ǧ��ѹ��",
        "damage_type" : "����"
]),
([      "action" : "$N���ַ�ִ������һ�С����ս�ġ�����һ����$wֱ��$n�ľ���նȥ",
        "force" : 60,
        "attack": 47,
        "dodge" : 5,
        "parry" : 19,
        "damage": 25,
        "lvl" : 60,
        "skill_name" : "���ս��",
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С��������ء����������⻯����㷱�ǣ���$n��$l��ȥ",
        "force" : 80,
        "attack": 52,
        "dodge" : 10,
        "parry" : 11,
        "damage": 30,
        "lvl" : 80,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ֺ�ִ$w��һ�С�����֮������š��ת������ֱ����$n��˫��",
        "force" : 110,
        "attack": 59,
        "dodge" : 15,
        "parry" : 15,
        "damage": 35,
        "lvl" : 100,
        "skill_name" : "����֮��",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����ò����������$w����һ����ƽʮ�֣���$n�ݺ���ȥ",
        "force" : 140,
        "attack": 63,
        "dodge" : 15,
        "parry" : 15,
        "damage": 40,
        "lvl" : 120,
        "skill_name" : "���ò��",
        "damage_type" : "����"
]),
([      "action" : "$N��ת�����׼�Լ���һ�С�������֦����ȫ��һ��������$w��$n����նȥ",
        "force" : 180,
        "attack": 71,
        "dodge" : 20,
        "parry" : 10,
        "damage": 50,
        "lvl" : 140,
        "skill_name" : "������֦",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��������ס���$w�ĵ���·𻯳�һ�ش����棬��$n����Χ��",
        "force" : 220,
        "attack": 78,
        "dodge" : 10,
        "parry" : 20,
        "damage": 55,
        "lvl" : 160,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N����ƽָ��һ�С��󺣳�ɳ����һƬƬ�йǵ�����쫷�����$n��ȫ��",
        "force" : 270,
        "attack": 85,
        "dodge" : 5,
        "parry" : 25,
        "damage": 60,
        "lvl" : 180,
        "skill_name" : "�󺣳�ɳ",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ���򲻵����޷�ѧϰ���ڵ�����\n");

        if (me->query("max_neili") < 1000)
                return notify_fail("�������̫��޷�ѧϰ���ڵ�����\n");

        if ((int)me->query_skill("blade", 1) < 30)
                return notify_fail("��Ļ����������̫ǳ���޷�ѧϰ���ڵ�����\n");

        if (me->query_skill("blade", 1) < me->query_skill("jinwu-daofa", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������Ľ��ڵ�����\n");

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
        level = (int) me->query_skill("jinwu-daofa", 1);
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

        if ((int)me->query("qi") < 80)
                return notify_fail("����������������ڵ�����\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("����������������ڵ�����\n");

        me->receive_damage("qi", 65);
        me->add("neili", -70);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jinwu-daofa/" + action;
}
