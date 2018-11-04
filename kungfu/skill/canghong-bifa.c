inherit SKILL;

mapping *action = ({
([      "action":"$N��������һ�С������־���$w���������£���$n�׺�Ѩ��ȥ",
        "force" : 130,
        "attack": 30,
        "dodge" : -10,
        "parry" : 30,
        "damage": 30,
        "lvl"   : 0,
        "skill_name" : "���־�",
        "damage_type" : "����"
]),
([      "action":"$N��ǰ����һ�����������ս�⣬ʹ���������־�������$n�ĵز�Ѩ",
        "force" : 170,
        "attack": 40,
        "dodge" : 5,
        "parry" : 32,
        "damage": 35,
        "lvl"   : 30,
        "skill_name" : "���־�",
        "damage_type" : "����"
]),
([      "action":"$N���е�$w������ҵ�һ�Σ�ʹ�����ˡ��־����$n������Ѩ",
        "force" : 190,
        "attack": 50,
        "dodge" : 5,
        "parry" : 35,
        "damage": 40,
        "lvl"   : 60,
        "skill_name" : "���־�",
        "damage_type" : "����"
]),
([      "action":"$N����Ծ��һʽ�����־������������Ӱ��$w��$n�����ȥ",
        "force" : 240,
        "attack": 60,
        "dodge" : 10,
        "parry" : 45,
        "damage": 50,
        "lvl"   : 90,
        "skill_name" : "���־�",
        "damage_type" : "����"
]),
([      "action":"$N�������У�$w�Ƴ�����ѩ���ʷ棬��Ȼ�ӳ����롹�־�����$n",
        "force" : 260,
        "attack": 65,
        "dodge" : 5,
        "parry" : 50,
        "damage": 60,
        "lvl"   : 120,
        "skill_name" : "���־�",
        "damage_type" : "����"
]),
([      "action":"$Nʹ��һ�С������־�ͦ���й�ֱ�����ʼ��������;��Ȼת������",
        "force" : 280,
        "attack": 70,
        "dodge" : 5,
        "parry" : 52,
        "damage": 75,
        "lvl"   : 150,
        "skill_name" : "���־�",
        "damage_type" : "����"
]),
([      "action":"$N����б��һ�ʣ�һ�С��ԡ��־�����ź����ʷ磬��$n��Χ����",
        "force" : 310,
        "attack": 75,
        "dodge" : 5,
        "parry" : 64,
        "damage": 90,
        "lvl"   : 180,
        "skill_name" : "���־�",
        "damage_type" : "����"
]),
});


int valid_enable(string usage)
{
	return usage == "dagger" || usage == "parry";
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 500)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("dagger", 1) < 30)
                return notify_fail("��Ļ����̱����̫ǳ��\n");

        if ((int)me->query_skill("dagger", 1) < (int)me->query_skill("canghong-bifa", 1))
                return notify_fail("��Ļ����̱�ˮƽ���ޣ��޷���������ĲԺ�ʷ���\n");

    	return 1;
}

string query_skill_name(int level)
{
        int i;

        for(i = sizeof(action) - 1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;

        level = (int) me->query_skill("canghong-bifa", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "dagger")
                return notify_fail("�����ֵ������޷���ϰ�Ժ�ʷ���\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("��������������Ժ�ʷ���\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("��������������Ժ�ʷ���\n");

        me->receive_damage("qi", 65);
        me->add("neili", -62);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"canghong-bifa/" + action;
}
