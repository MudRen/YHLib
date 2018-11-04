inherit SKILL;

mapping *action = ({
([      "action":"$N������ס�ȶˣ�һ�С����ϵ��¡������ƾ���һ��������ƾ���Ե���$n�ļ�ͷ",
        "force" : 65,
        "attack": 12,
        "dodge" : -10,
        "parry" : 5,
        "damage": 35,
        "lvl"   : 0,
        "damage_type":"����"
]),
([      "action":"$N˫�۷��죬������$w���ǧ�ٸ����ƣ���������$nȫ�����Ҫ��",
        "force" : 89,
        "attack": 20,
        "dodge" : -10,
        "parry" : 8,
        "damage": 44,
        "lvl"   : 30,
        "damage_type":"����"
]),
([      "action":"$N�첽���������ƽ��$w�����������ȶˣ�����$n���ؿ�",
        "force" : 128,
        "attack": 35,
        "dodge" : -5,
        "parry" : 10,
        "damage": 52,
        "lvl"   : 60,
        "damage_type":"����"
]),
([      "action":"$N���һ��������$w�������������Ծ����ֱ��$n���ؿڴ���",
        "force" : 200,
        "attack": 34,
        "dodge" : -5,
        "parry" : 12,
        "damage": 66,
        "lvl"   : 80,
        "damage_type":"����"
]),
([      "action":"$N���$w���ȶ˻���������ԲȦ�����ͳ��أ���$n��������",
        "force" : 250,
        "attack": 46,
        "dodge" : -15,
        "parry" : 18,
        "damage": 70,
        "lvl"   : 100,
        "damage_type":"����"
]),
([      "action":"���$w��һ�С��������¡����ȶ˻���������ԲȦ�����ͳ��أ���$n��������",
        "force" : 280,
        "attack": 67,
        "dodge" : 5,
        "parry" : 22,
        "damage": 78,
        "lvl"   : 120,
        "damage_type":"����"
]),
([      "action":"$Nȫ�������$w�̵غ�ɣ�ͻ��һ�С��������졹����Ӱ��$n��������",
        "force" : 320,
        "attack": 89,
        "dodge" : -5,
        "parry" : 28,
        "damage": 100,
        "lvl"   : 140,
        "damage_type":"����"
]),
([      "action":"$N���ȶ�����$w���ǧ�ٸ����ƣ���������$nȫ�����Ҫ��",
        "force" : 360,
        "attack": 102,
        "dodge" : -5,
        "parry" : 35,
        "damage": 120,
        "lvl"   : 160,
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

        if ((int)me->query("max_neili") < 200)
                return notify_fail("���������Ϊ���㣬�޷�ѧϰ�����ȷ���\n");

        if ((int)me->query_skill("force", 1) < 140)
                return notify_fail("����ڹ����̫ǳ���޷�ѧϰ�����ȷ���\n");

        if ((int)me->query_skill("staff", 1) < 60)
                return notify_fail("��Ļ����ȷ�̫ǳ���޷�ѧϰ�����ȷ���\n");

        if ((int)me->query_skill("staff", 1) < (int)me->query_skill("yinhu-zhang", 1))
                return notify_fail("��Ļ����ȷ�ˮƽ���ޣ��޷���������������ȷ���\n");

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
        level = (int)me->query_skill("yinhu-zhang", 1);

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
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

        if ((int)me->query("neili") < 80)
                return notify_fail("������������������ȷ���\n");

        me->receive_damage("qi", 75);
        me->add("neili", -78);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yinhu-zhang/" + action;
}
