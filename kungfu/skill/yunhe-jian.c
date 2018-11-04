inherit SKILL;

mapping *action = ({
([	"action": "$N�������ң�����һ�ܣ�һʽ���ٺ���������$wͻȻ��$n��$l��ȥ��",
	"force" : 35,
        "dodge" : -40,
        "parry" : -40,
        "attack": 2,
	"damage": 3,
	"lvl"   : 0,
	"skill_name" : "�ٺ�����",
	"damage_type":"����"
]),
([	"action": "$Nʹ��һʽ���ɺ���������������ղ෭��һ�������´̳�",
	"force" : 59,
        "dodge" : -35,
        "parry" : -35,
        "attack": 3,
	"damage": 4,
	"lvl"   : 20,
	"skill_name" : "�ɺ�����",
	"damage_type":"����"
]),
([	"action": "$N���ֽ�ָѪָ������$wʹ��һ�С��˺׶��项��������������$n��$l����",
	"force" : 77,
        "dodge" : -23,
        "parry" : -23,
        "attack": 5,
	"damage": 7,
	"lvl"   : 40,
	"skill_name" : "�˺׶���",
	"damage_type":"����"
]),
([	"action": "$N��������$w�����ڱ��£�һ�С�һ�׳�������������������$n��$l",
	"force" : 83,
        "dodge" : -18,
        "parry" : -18,
        "attack": 9,
	"damage": 10,
	"lvl"   : 60,
	"skill_name" : "һ�׳���",
	"damage_type":"����"
]),
([	"action": "$N̤����ǰ��һʽ���ױ������������г����ڶ����������$n��$l",
	"force" : 127,
        "dodge" : -9,
        "parry" : -9,
        "attack": 11,
	"damage": 12,
	"lvl"   : 80,
	"skill_name" : "�ױ�����",
	"damage_type":"����"
]),
([	"action": "$Nһ�С��ƺ����衹�����屳ת������$w���Ҽ��Ϸ��������´̳�",
	"force" : 179,
        "dodge" : -5,
        "parry" : -5,
        "attack": 31,
	"damage": 44,
	"lvl"   : 100,
	"skill_name" : "�ƺ�����",
	"damage_type":"����"
]),
([	"action": "$Nһʽ���ƺ����衹�������з棬�������ϣ���$n���������ؽ���֮��",
	"force" : 217,
        "dodge" : 5,
        "parry" : 5,
        "attack": 35,
	"damage": 56,
	"lvl"   : 130,
	"skill_name" : "�ƺ�����",
	"damage_type":"����"
]),
([	"action": "$N��ǰ����һ�С��ƺ׾��衹��$w��Ȼ�����´̳���������������",
	"force" : 260,
        "dodge" : 10,
        "parry" : 10,
        "attack": 48,
	"damage": 72,
	"lvl"   : 160,
	"skill_name" : "�ƺ׾���",
	"damage_type":"����"
]),
([	"action": "$N����$w�����һζ���һ�С�����ʮ���졹������ֱ��$n������Ҫ��",
	"force" : 305,
        "dodge" : 14,
        "parry" : 14,
        "attack": 51,
	"damage": 84,
	"lvl"   : 200,
	"skill_name" : "����ʮ����",
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

        if ((int)me->query_skill("sword") < 30)
                return notify_fail("��Ļ����������̫ǳ���޷������ƺ��߽���\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("yunhe-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷�����������ƺ��߽���\n");

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
        level = (int) me->query_skill("yunhe-jian", 1);
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
                return notify_fail("��������������ƺ��߽���\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("��������������ƺ��߽���\n");

        me->receive_damage("qi", 50);
        me->add("neili", -45);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yunhe-jian/" + action;
}
