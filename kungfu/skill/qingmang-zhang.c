inherit SKILL;

mapping *action = ({
([      "action": "$Nǰ���߳������Ƚż��أ�һʽ����ճ�����������ֱ��������$n"
                  "����������·",
        "force" : 120,
        "attack": 17,
        "dodge" : 5,
        "parry" : 12,
        "damage": 5,
        "lvl"   : 0,
        "damage_type" : "����",
]),
([      "action": "$N���ƻ�һ��Բ��һʽ��������ա�������б������������$n����ǰ"
                  "��Ѩ",
        "force" : 150,
        "attack": 25,
        "dodge" : 5,
        "parry" : 18,
        "damage": 10,
        "lvl"   : 10,
        "damage_type" : "����",
]),
([      "action": "$Nʹһʽ���ƶ����롹�����������������ɺ����һ��˦����ն��$n"
                  "��$l",
        "force" : 170,
        "attack": 32,
        "dodge" : 6,
        "parry" : 22,
        "damage": 10,
        "lvl"   : 20,
        "damage_type" : "����",
]),
([      "action": "$N���ƻ��أ���ȭ�����󷢣�һʽ����������������������$n��$l",
        "force" : 190,
        "attack": 38,
        "dodge" : -5,
        "parry" : 32,
        "damage": 10,
        "lvl"   : 40,
        "damage_type" : "����",
]),
([      "action": "$Nʹһʽ������ء���ȫ�������ת��˫��һǰһ���͵�����$n"
                  "���ؿ�",
        "force" : 210,
        "attack": 51,
        "dodge" : 10,
        "parry" : 27,
        "damage": 15,
        "lvl"   : 70,
        "damage_type" : "����",
]),
([      "action": "$N���Ʊ�������һ������һʽ�����б��¡���˫�Ƽ�����$n�ļ�ͷ",
        "force" : 250,
        "attack": 52,
        "dodge" : 5,
        "parry" : 38,
        "damage": 15,
        "lvl"   : 90,
        "damage_type" : "����",
]),
([      "action": "$N���ϸ߸�Ծ��һʽ����ɽ��ˮ�����Ӹ����£���������$n��ȫ��",
        "force" : 280,
        "attack": 62,
        "dodge" : 20,
        "parry" : 56,
        "damage": 15,
        "lvl"   : 110,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }  

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����ç�Ʊ�����֡�\n");

        if ((int)me->query_skill("force") < 20)
                return notify_fail("����ڹ��ķ���򲻹����޷�������ç�ơ�\n");

        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷�����ç�ơ�\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("qingmang-zhang", 1))
                return notify_fail("��Ļ����Ʒ�������ޣ��޷������������ç�ơ�\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i - 1]["lvl"])
                        return action[i - 1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("qingmang-zhang", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i - 1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 40)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 40)
                return notify_fail("���������������ç�ơ�\n");

        me->receive_damage("qi", 30);
        me->add("neili", -30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"qingmang-zhang/" + action;
}
