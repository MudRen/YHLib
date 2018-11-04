inherit SKILL;

mapping *action = ({
([      "action" : "$N�ص����գ��������¶��ϻ��˸��뻡����$n��$l��ȥ",
        "force" : 193,
        "dodge" : 3,
        "parry" : 5,
        "damage": 61,
        "attack": 33,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N�����������⣬����$w��ֱ����$n��$l",
        "force" : 217,
        "dodge" : 9,
        "parry" : 7,
        "damage": 68,
        "attack": 37,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$N����$w�ƾ�������ˢ��һ�����϶�����$n����",
        "force" : 225,
        "dodge" : 13,
        "parry" : 7,
        "damage": 73,
        "attack": 38,
        "lvl" : 40,
        "damage_type" : "����"
]),
([      "action" : "$N���ַ�ִ��������һ����$wֱ��$n�ľ���նȥ",
        "force" : 239,
        "dodge" : 11,
        "parry" : 9,
        "damage": 79,
        "attack": 41,
        "lvl" : 60,
        "damage_type" : "����"
]),
([      "action" : "$N����$w�ó��������⣬������㷱�ǣ���$n��$l��ȥ",
        "force" : 257,
        "dodge" : 11,
        "parry" : 13,
        "damage": 83,
        "attack": 48,
        "lvl" : 80,
        "damage_type" : "����"
]),
([      "action" : "$N˫�ֺ�ִ$w��š��ת������ֱ����$n��˫��",
        "force" : 276,
        "dodge" : 19,
        "parry" : 23,
        "damage": 89,
        "attack": 53,
        "lvl" : 100,
        "damage_type" : "����"
]),
([      "action" : "$N����$w����һ����ƽʮ�֣���$n�ݺ���ȥ",
        "force" : 312,
        "dodge" : 17,
        "parry" : 13,
        "damage": 97,
        "attack": 59,
        "lvl" : 120,
        "damage_type" : "����"
]),
([      "action" : "$N��ת�����׼�Լ���ȫ��һ��������$w��$n����նȥ",
        "force" : 297,
        "dodge" : 18,
        "parry" : 21,
        "damage": 113,
        "attack": 68,
        "lvl" : 140,
        "damage_type" : "����"
]),
([      "action" : "$N����$w�ĵ���·𻯳�һ�ش����棬��$n����Χ��",
        "force" : 323,
        "dodge" : 29,
        "parry" : 23,
        "damage": 117,
        "attack": 69,
        "lvl" : 170,
        "damage_type" : "����"
]),
([      "action" : "$N����ƽָ��һƬƬ�йǵ�����쫷�����$n��ȫ��",
        "force" : 317,
        "dodge" : 31,
        "parry" : 25,
        "damage": 121,
        "attack": 78,
        "lvl" : 200,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "blade") || (usage == "parry")
; }

int valid_learn(object me)
{
        if (me->query("character") != "�ĺ�����")
                return notify_fail("�������Ե�����ʵ�ڹ��ںݶ����Լ�ίʵѧ���ᡣ\n");

        if ((int)me->query("max_neili") < 2000)
                return notify_fail("����������㣬û�а취���Ե�����������Щ���������ɡ�\n");

        if ((int)me->query_skill("blade", 1) < 180)
                return notify_fail("��Ļ����������̫ǳ��û�а취���Ե�������\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ����̫ǳ��û�а취���Ե�������\n");

        if ((int)me->query_skill("blade", 1) < (int)me->query_skill("badao-daofa", 1))
                return notify_fail("��Ļ�������ˮƽ���������޷���������İԵ�������\n");

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
        level   = (int) me->query_skill("badao-daofa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 80)
                return notify_fail("��������������Ե�������\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("��������������Ե�������\n");

        me->receive_damage("qi", 60);
        me->add("neili", -60);
        return 1;
}

