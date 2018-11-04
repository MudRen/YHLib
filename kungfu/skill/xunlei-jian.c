inherit SKILL;

mapping *action = ({
([	"action": "$N�������ң�����һ�ܣ�һʽ������ָ·����$wͻȻ��$n��$l��ȥ��",
	"force" : 35,
        "dodge" : -40,
        "parry" : -40,
        "attack": 2,
	"damage": 3,
	"lvl"   : 0,
	"skill_name" : "����ָ·",
	"damage_type":"����"
]),
([	"action": "$Nʹ��һʽ�����ӷ�����������ղ෭��һ�������´̳�",
	"force" : 49,
        "dodge" : -35,
        "parry" : -35,
        "attack": 3,
	"damage": 4,
	"lvl"   : 10,
	"skill_name" : "���ӷ���",
	"damage_type":"����"
]),
([	"action": "$N���ֽ�ָѪָ������$wʹ��һ�С�����Ѱ�롹��������������$n��$l����",
	"force" : 57,
        "dodge" : -23,
        "parry" : -23,
        "attack": 5,
	"damage": 7,
	"lvl"   : 20,
	"skill_name" : "����Ѱ��",
	"damage_type":"����"
]),
([	"action": "$N��������$w�����ڱ��£�һ�С���Գ̽������������������$n��$l",
	"force" : 63,
        "dodge" : -18,
        "parry" : -18,
        "attack": 9,
	"damage": 10,
	"lvl"   : 30,
	"skill_name" : "��Գ̽��",
	"damage_type":"����"
]),
([	"action": "$N̤����ǰ��һʽ������Ѱ�ߡ������г����ڶ����������$n��$l",
	"force" : 67,
        "dodge" : -9,
        "parry" : -9,
        "attack": 11,
	"damage": 12,
	"lvl"   : 40,
	"skill_name" : "����Ѱ��",
	"damage_type":"����"
]),
([	"action": "$Nһ�С�б����֦�������屳ת������$w���Ҽ��Ϸ��������´̳�",
	"force" : 79,
        "dodge" : -5,
        "parry" : -5,
        "attack": 13,
	"damage": 14,
	"lvl"   : 50,
	"skill_name" : "б����֦",
	"damage_type":"����"
]),
([	"action": "$Nһʽ�������׶����������з棬�������ϣ���$n���������ؽ���֮��",
	"force" : 87,
        "dodge" : 5,
        "parry" : 5,
        "attack": 15,
	"damage": 16,
	"lvl"   : 60,
	"skill_name" : "�����׶�",
	"damage_type":"����"
]),
([	"action": "$N��ǰ����һ�С�����Ҿ�֡���$w��Ȼ�����´̳���������������",
	"force" : 90,
        "dodge" : 10,
        "parry" : 10,
        "attack": 18,
	"damage": 20,
	"lvl"   : 70,
	"skill_name" : "����Ҿ��",
	"damage_type":"����"
]),
([	"action": "$N����$w�����һζ���һ�С����������������ֱ��$n������Ҫ��",
	"force" : 105,
        "dodge" : 14,
        "parry" : 14,
        "attack": 20,
	"damage": 24,
	"lvl"   : 80,
	"skill_name" : "�������",
	"damage_type":"����"
]),
([	"action": "$N˫�ֳֽ�����$w������ʹ��һ�С��ٻ����졹���������$n��ǰ�Ϸ���ȥ",
	"force" : 110,
        "dodge" : 18,
        "parry" : 18,
        "attack": 24,
	"damage": 28,
	"lvl"   : 90,
	"skill_name" : "�ٻ�����",
	"damage_type":"����"
]),
([	"action": "$N������$n��ʹ��һ�С�����ն�㡹���Ӷ�����$w��ֱ��$n������·",
	"force" : 120,
        "dodge" : 20,
        "parry" : 20,
        "attack": 26,
	"damage": 30,
	"lvl"   : 100,
	"skill_name" : "����ն��",
	"damage_type":"����"
]),
([	"action": "$N����$w��������һ�С���Ů���롹��$wͻȻ���ִ���$n��$l",
	"force" : 135,
        "dodge" : 24,
        "parry" : 24,
        "attack": 30,
	"damage": 35,
	"lvl"   : 110,
	"skill_name" : "��Ů����",
	"damage_type":"����"
]),
([	"action": "$N������ǰ��������ָ��һ�С���Գ��֦����$w����$n��ͷ��Ҫ��",
	"force" : 140,
        "dodge" : 26,
        "parry" : 26,
        "attack": 31,
	"damage": 36,
	"lvl"   : 120,
	"skill_name" : "��Գ��֦",
	"damage_type":"����"
]),
([	"action": "$Nһ�С�����ӱޡ���$w�����ߣ�����һ����������$nȫ����������",
	"force" : 145,
        "dodge" : 28,
        "parry" : 28,
        "attack": 33,
	"damage": 38,
	"lvl"   : 130,
	"skill_name" : "����ӱ�",
	"damage_type":"����"
]),
([	"action": "$N�������£�һ�С����ƿ�������$w��Ȼ��תֱ�ϣ�������$n������Ҫ������Χס",
	"force" : 150,
        "dodge" : 30,
        "parry" : 30,
        "attack": 35,
	"damage": 40,
	"lvl"   : 140,
	"skill_name" : "���ƿ���",
	"damage_type":"����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 20)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("sword") < 10)
                return notify_fail("��Ļ����������̫ǳ���޷�����Ѹ�׽�����\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("xunlei-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷����������Ѹ�׽�����\n");

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
        level = (int) me->query_skill("xunlei-jian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];

}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("�������������Ѹ�׽�����\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("�������������Ѹ�׽�����\n");

        me->receive_damage("qi", 50);
        me->add("neili", -45);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xunlei-jian/" + action;
}
