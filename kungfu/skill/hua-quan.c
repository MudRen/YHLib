inherit SKILL;

mapping *action = ({
([      "action": "ֻ��$N����һ�����������һ����б�����Ų����š���׼$n������ȥ",
        "force" : 60,
        "attack": 20,
        "dodge" : 40,
        "parry" : 5,
        "damage": 4,
        "lvl"   : 0,
        "skill_name" : "б�����Ų�����",
        "damage_type":  "����"
]),
([      "action": "$N����һ�֣���ȭ������һ�С����ǵ�ͷ����ȭ������$n��$l�к���ȥ",
        "force" : 80,
        "attack": 25,
        "dodge" : 43,
        "parry" : 6,
        "damage": 7,
        "lvl"   : 30,
        "skill_name" : "���ǵ�ͷ����ȭ",
        "damage_type":  "����"
]),
([      "action": "$N��ȭ��$n����һ�Σ�����ʹ�˸������ƿ绢����������$n����һȭ",
        "force" : 100,
        "attack": 28,
        "dodge" : 45,
        "parry" : 8,
        "damage": 10,
        "lvl"   : 60,
        "skill_name" : "���ƿ绢������",
        "damage_type":  "ץ��"
]),
([      "action": "$N��ȭ��������ȭ���磬һ�С�����չ��ͥ��վ���Ʋ��ɵ��ػ���$n",
        "force" : 120,
        "attack": 35,
        "dodge" : 47,
        "parry" : 11,
        "damage": 17,
        "lvl"   : 80,
        "skill_name" : "����չ��ͥ��վ",
        "damage_type":  "����"
]),
([      "action": "ֻ��$N������ʽ��һ�С�Τ���ױ�����ǰ��ʹ��������ȴ����$n��$l",
        "force" : 140,
        "attack": 40,
        "dodge" : 49,
        "parry" : 13,
        "damage": 20,
        "lvl"   : 100,
        "skill_name" : "Τ���ױ�����ǰ",
        "damage_type":  "����"
]),
([      "action": "$N������$n���һ����һ�С��ѱ����ź����š�����$n������ȥ",
        "force" : 160,
        "attack": 45,
        "dodge" : 52,
        "parry" : 16,
        "damage": 22,
        "lvl"   : 120,
        "skill_name" : "�ѱ����ź�����",
        "damage_type":  "����"
]),
([      "action": "$N�����󹭲���˫��ʹ�˸���������������������$n��$l����һ��",
        "force" : 200,
        "attack": 48,
        "dodge" : 54,
        "parry" : 18,
        "damage": 28,
        "lvl"   : 140,
        "skill_name" : "��������������",
        "damage_type":  "����"
]),
([      "action": "ֻ��$N��������ʹ�������ƿ绢����������������ȭ��ȫ������$n��$l",
        "force" : 220,
        "attack": 51,
        "dodge" : 57,
        "parry" : 20,
        "damage": 32,
        "lvl"   : 160,
        "skill_name" : "���ƿ绢������",
        "damage_type":  "����"
]),
([      "action": "$N����һ�ݣ�����ʹ�˸�����Գ͵�Ұ���ͥ��������ɨ��$n��$l",
        "force" : 260,
        "attack": 55,
        "dodge" : 61,
        "parry" : 21,
        "damage": 35,
        "lvl"   : 180,
        "skill_name" : "��Գ͵�Ұ���ͥ",
        "damage_type":  "����"
]),
([      "action": "$Nһ��ת�����ƻ��أ����Ʒ���ʹ�˸��������Խ�����ש����$n��ͷ����",
        "force" : 280,
        "attack": 60,
        "dodge" : 63,
        "parry" : 23,
        "damage": 37,
        "lvl"   : 200,
        "skill_name" : "�����Խ�����ש",
        "damage_type":  "����"
]),
([      "action": "$N����Ծ��һ�С�������һ���̡�������$n���ţ��漴˫ȭ�ѵ�$n$l",
        "force" : 300,
        "attack": 62,
        "dodge" : 65,
        "parry" : 25,
        "damage": 40,
        "lvl"   : 220,
        "skill_name" : "������һ����",
        "damage_type":  "����"
]),
});

int valid_enable(string usage)
{
        return usage == "cuff" || usage == "parry";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��������ȭ������֡�\n");

        if (me->query("max_neili") < 200)
                return notify_fail("��������������޷���ϰ������ȭ��\n");

        if ((int)me->query_skill("cuff", 1) < 40)
                return notify_fail("��Ļ���ȭ�����̫ǳ��\n");

        if ((int)me->query_skill("cuff", 1) < (int)me->query_skill("hua-quan", 1))
                return notify_fail("��Ļ���ȭ��������ޣ��޷����������������ȭ��\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("hua-quan", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70 )
                return notify_fail("����������������Ϣһ�������ɡ�\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("�������������ϰ������ȭ��\n");

        me->receive_damage("qi", 65);
        me->add("neili", -40);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"hua-quan/" + action;
}
