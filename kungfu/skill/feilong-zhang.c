inherit SKILL;

mapping *action = ({
([      "action": "$Nб��$w, һ�С�������ʯ����б���������$n��$l",
        "force" : 80,
        "attack": 24,
        "dodge" : -5,
        "parry" : 20,
        "damage": 35,
        "lvl"   : 0,
        "damage_type":"����"
]),
([      "action": "$Nһ����ȣ�ʹ��һ�С�³�������, ����$w���¶���ɨ��$n��$l",
        "force" : 100,
        "attack": 30,
        "dodge" : -10,
        "parry" : 25,
        "damage": 40,
        "lvl"   : 30,
        "damage_type":"����"
]),
([      "action": "$Nʹ��һ�С���������������$w�Ӽ�ͷ˦��������$n��$l",
        "force" : 120,
        "attack": 35,
        "dodge" : -5,
        "parry" : 24,
        "damage": 50,
        "lvl"   : 70,
        "damage_type":"����"
]),
([      "action": "$N����һ�Σ�һ�С�������򡹣�����$w���籩�����$n���",
        "force" : 160,
        "attack": 50,
        "dodge" : -5,
        "parry" : 45,
        "damage": 60,
        "lvl"   : 100,
        "damage_type":"����"
]),
([      "action": "$Nһ��������һ�С����羭�졹, $w����������������$n��$l",
        "force" : 180,
        "attack": 61,
        "dodge" : -5,
        "parry" : 50,
        "damage": 75,
        "lvl"   : 120,
        "damage_type":"����"
]),
([      "action": "$Nһ�С�����һ�֡�, ������$w���ǧ�ٸ����ƣ���������$nȫ�����Ҫ��",
        "force" : 220,
        "attack": 70,
        "dodge" : -5,
        "parry" : 60,
        "damage": 90,
        "lvl"   : 150, 
        "damage_type":"����"
]),
});

int valid_enable(string usage)
{
        return usage == "staff" || usage == "parry";
}

int valid_learn(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "staff")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("max_neili") < 500)
                return notify_fail("���������Ϊ���㣬�������������ȷ���\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("����ڹ���Ϊ�������������������ȷ���\n");

        if ((int)me->query_skill("staff", 1) < 40)
                return notify_fail("��Ļ����ȷ����̫ǳ���������������ȷ���\n");

        if ((int)me->query_skill("staff", 1) < (int)(int)me->query_skill("feilong-zhang", 1))
                return notify_fail("��Ļ����ȷ�ˮƽ���ޣ��޷���������ķ����ȷ���\n");

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
        level = (int) me->query_skill("feilong-zhang", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "staff")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 80)
                return notify_fail("������������������ȷ���\n");

        if ((int)me->query("neili") < 75)
                return notify_fail("������������������ȷ���\n");

        me->receive_damage("qi", 70);
        me->add("neili", -69);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"feilong-zhang/" + action;
}

