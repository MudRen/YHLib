inherit SKILL;

mapping *action = ({
([	"action":"$Nһʽ��˳ˮ���ۡ���$N����$wָ���Լ����ؿڣ�����бб�����⣬��������$n��$l",
	"force" : 85,
        "dodge" : 35,
        "parry" : 35,
        "attack": 31,
	"damage": 23,
	"lvl"   : 0,
	"skill_name" : "˳ˮ����",
	"damage_type":"����"
]),
([	"action":"$N����΢�࣬���ֺ�ڣ�����$wһ�С���ɨǧ������ֱ��$n�������ȥ",
	"force" : 109,
        "dodge" : 41,
        "parry" : 43,
        "attack": 33,
	"damage": 24,
	"lvl"   : 20,
	"skill_name" : "��ɨǧ��",
	"damage_type":"����"
]),
([	"action":"$N�����ǰ��$w��Ȼ���䵯�������ⱬ����һ�С��ͱڶ��ơ����͵ش���$n���ؿ�",
	"force" : 121,
        "dodge" : 43,
        "parry" : 45,
        "attack": 35,
	"damage": 27,
	"lvl"   : 40,
	"skill_name" : "�ͱڶ���",
	"damage_type":"����"
]),
([	"action":"$N�������������ƽ�ƶ�������ָ���������ֽ����첻����һ�С�����ָ·��������$n",
	"force" : 135,
        "dodge" : 48,
        "parry" : 47,
        "attack": 37,
	"damage": 31,
	"lvl"   : 60,
	"skill_name" : "����ָ·",
	"damage_type":"����"
]),
([	"action":"$N���к��䣬ʹ��һ�С����ɻ�����ȫ��б�ƣ����߰���б����ż����Ю��һ�����ƣ����˼���׽��",
	"force" : 143,
        "dodge" : 57,
        "parry" : 59,
        "attack": 41,
	"damage": 32,
	"lvl"   : 80,
	"skill_name" : "���ɻ�",
	"damage_type":"����"
]),
([	"action":"$N����$w�������𣬷�����£�һ�С���Įƽɳ�������ߵ��ƣ�����$n��$l",
	"force" : 153,
        "dodge" : 63,
        "parry" : 68,
        "attack": 43,
	"damage": 34,
	"lvl"   : 100,
	"skill_name" : "��Įƽɳ",
	"damage_type":"����"
]),
([	"action":"$Nһ�С�ľҶ��������$N����$w������бָ���죬���϶��£�����$n��$l",
	"force" : 167,
        "dodge" : 69,
        "parry" : 71,
        "attack": 45,
	"damage": 36,
	"lvl"   : 120,
	"skill_name" : "ľҶ����",
	"damage_type":"����"
]),
([	"action":"$N��ǰһ����$w΢΢�����������㣬һ�С����Ӳ��ߡ����ն���ʼ�����಻������$n",
	"force" : 185,
        "dodge" : 73,
        "parry" : 78,
        "attack": 48,
	"damage": 37,
	"lvl"   : 140,
	"skill_name" : "���Ӳ���",
	"damage_type":"����"
]),
([	"action":"$N���ֽ���һ�٣�������ʯ�⣬һ�С��������ơ����ý�����ס$n���б�����$wֱָ$n���ʺ�",
	"force" : 205,
        "dodge" : 78,
        "parry" : 85,
        "attack": 49,
	"damage": 38,
	"lvl"   : 160,
	"skill_name" : "��������",
	"damage_type":"����"
]),
([	"action":"$N����ؽ�������б����һ�С����ɷ��١�������Ӱ����ֱк��������ס$n�Ϸ�",
	"force" : 243,
        "dodge" : 82,
        "parry" : 91,
        "attack": 51,
	"damage": 39,
	"lvl"   : 180,
	"skill_name" : "���ɷ���",
	"damage_type":"����"
]),
([	"action":"$Nһʽ��ѩӵ���š���$N���н������ţ�һ����������������$n",
	"force" : 271,
        "dodge" : 87,
        "parry" : 95,
        "attack": 53,
	"damage": 41,
	"lvl"   : 200,
	"skill_name" : "ѩӵ����",
	"damage_type":"����"
]),
([	"action":"$N�ڿն���ͻȻʹ��һ�С���Ȼ��������������Ϣ�ؼ���$n�ı�����ȥ",
	"force" : 285,
        "dodge" : 95,
        "parry" : 107,
        "attack": 57,
	"damage": 43,
	"lvl"   : 220,
	"skill_name" : "��Ȼ����",
	"damage_type":"����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 800)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force", 1) < 50)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("sword") < 50)
                return notify_fail("��Ļ����������̫ǳ���޷����������ǽ�����\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("zhengliangyi-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������������ǽ�����\n");

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
        level = (int) me->query_skill("zhengliangyi-jian", 1);
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

        if ((int)me->query("qi") < 80)
                return notify_fail("������������������ǽ�����\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("������������������ǽ�����\n");

        me->receive_damage("qi", 65);
        me->add("neili", -75);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"zhengliangyi-jian/" + action;
}
