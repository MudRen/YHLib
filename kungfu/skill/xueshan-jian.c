inherit SKILL;

mapping *action = ({
([      "action": "$N����$w���ͣ�ʩ��ѩɽ�������֡������ơ���ǰ�̳�������$n��$l",
        "force" : 153,
        "attack": 39,
        "dodge" : 65,
        "parry" : 67,
        "damage": 41,
        "lvl"   : 0,
        "skill_name" : "������",
        "damage_type": "����"
]),
([      "action": "$N����ٿ�ط��ϣ�����$wб��$n$l������ѩɽ�ɽ����С���֦��б��һ��",
        "force" : 167,
        "attack": 43,
        "dodge" : 68,
        "parry" : 69,
        "damage": 43,
        "lvl"   : 20,
        "skill_name" : "��֦��б",
        "damage_type": "����"
]),
([      "action": "$Nһ�С�ѩ���צ��������һ����$w�й�ֱ����������;ȴ��ת���棬б��$n",
        "force" : 173,
        "attack": 48,
        "dodge" : 71,
        "parry" : 79,
        "damage": 45,
        "lvl"   : 40,
        "skill_name" : "ѩ���צ",
        "damage_type": "����"
]),
([      "action": "$N����$w΢΢������һ�С�˷����𡹣���Ȼ�̳�����ʱһ����������$n��$l",
        "force" : 195,
        "attack": 51,
        "dodge" : 75,
        "parry" : 82,
        "damage": 49,
        "lvl"   : 60,
        "skill_name" : "˷�����",
        "damage_type": "����"
]),
([      "action": "$N���ֽ��ս�ָ������$w������͸��������һʽ������˫÷������ָ����ͬʱ����$n",
        "force" : 218,
        "attack": 57,
        "dodge" : 79,
        "parry" : 83,
        "damage": 53,
        "lvl"   : 80,
        "skill_name" : "����˫÷",
        "damage_type": "����"
]),
([      "action": "$Nһʽ��������������$w����һ�����»��Σ�����������⣬ֱ��$n$l��ȥ",
        "force" : 224,
        "attack": 62,
        "dodge" : 85,
        "parry" : 89,
        "damage": 57,
        "lvl"   : 100,
        "skill_name" : "��������",
        "damage_type": "����"
]),
([      "action": "$N����һת��һ�С�÷ѩ������������$w����$n�͹���������ʽ���棬�����س�",
        "force" : 238,
        "attack": 69,
        "dodge" : 87,
        "parry" : 91,
        "damage": 61,
        "lvl"   : 130,
        "skill_name" : "÷ѩ����",
        "damage_type": "����"
]),
([      "action": "$N���е�$w�������̣�һ�С�������Ӱ�����д���һ�������ӹ�$nȫ��",
        "force" : 257,
        "attack": 75,
        "dodge" : 95,
        "parry" : 99,
        "damage": 68,
        "lvl"   : 160,
        "skill_name" : "������Ӱ",
        "damage_type": "����"
]),
([      "action": "$Nһ�С���ɫ�ƻ衹��ʹ���������ޣ��������ʣ�$wбб������ֱȡ$n$l",
        "force" : 270,
        "attack": 81,
        "dodge" : 107,
        "parry" : 109,
        "damage": 73,
        "lvl"   : 190,
        "skill_name" : "��ɫ�ƻ�",
        "damage_type": "����"
]),
([      "action": "$N��Хһ����һ�С��׷ɾ��졹������$w�������ţ������ʱ�ų�������������$n",
        "force" : 285,
        "attack": 85,
        "dodge" : 115,
        "parry" : 115,
        "damage": 77,
        "lvl"   : 220,
        "skill_name" : "�׷ɾ���",
        "damage_type": "����"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻵����޷�ѧϰѩɽ������\n");

        if (me->query("max_neili") < 1200)
                return notify_fail("�������̫��޷�ѧϰѩɽ������\n");

        if ((int)me->query_skill("sword", 1) < 100)
                return notify_fail("��Ļ����������̫ǳ���޷�ѧϰѩɽ������\n");

        if (me->query_skill("sword", 1) < me->query_skill("xueshan-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷����������ѩɽ������\n");

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
        level = (int) me->query_skill("xueshan-jian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon")) || 
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 80)
                return notify_fail("�������������ѩɽ������\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("�������������ѩɽ������\n");

        me->receive_damage("qi", 65);
        me->add("neili", -70);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xueshan-jian/" + action;
}
