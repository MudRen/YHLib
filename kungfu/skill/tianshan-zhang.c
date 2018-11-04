// tianshan-zhang.c, based on dagou-bang.c
// by yucao
// Modified by Hop 97.01.05
// Added by Yzuo 97.04.08

inherit SKILL;

mapping *action = ({
([	"action": "$Nʹ��һ�С����ӿ�����������$w�󿪴���ɨ��$n��$l",
	"force" : 110,
	"dodge": -3,
	"damage": 5,
	"lvl" : 0,
	"damage_type": "����"
]),
([	"action": "$N����$w������죬һ�С�ɽ����������$n��$l��ȥ",
	"force" : 110,
	"dodge": -5,
	"damage": 10,
	"lvl" : 13,
	"damage_type": "����"
]),
([	"action": "$N����$w���Ӹ�����ʹһ�С���ɽѩ��������$n��$l",
	"force" : 120,
	"dodge": -10,
	"damage": 20,
	"lvl" : 30,
	"damage_type": "����"
]),
([	"action": "$Nһ�С�������ѩ��������Ʈ�����ߣ�����$w����$n��$l",
	"force" : 130,
	"dodge": -30,
	"damage": 20,
	"lvl" : 45,
	"damage_type": "����"
]),
([	"action": "$Nʹһ�С��ع�õ硹������$w��һ���������$n��$l",
	"force" : 140,
	"dodge": -20,
	"damage": 30,
	"lvl" : 60,
	"damage_type": "����"
]),
([	"action": "$Nʹ���ġ���˪��Ӱ����$w������Ӱ��������$n��$l",
	"force" : 140,
	"dodge": -20,
	"damage": 30,
	"lvl" : 75,
	"damage_type": "����"
]),
([	"action": "$N��$wƾ��һָ��һ�С���ʯ���̡�����$n��$l",
	"force" : 150,
	"dodge": 20,
	"damage": 40,
	"lvl" : 90,
	"damage_type": "����"
]),
([	"action": "$N����һԾ������$wһ�С�������������׼$n��$lɨȥ",
	"force" : 160,
	"dodge": -40,
	"damage": 50,
	"lvl" : 105,
	"damage_type": "����"
]),
([	"action": "$N����$w�й�ֱ����һʽ�����ȳ��硹��׼$n��$l��ȥ",
	"force" : 180,
	"dodge": -40,
	"damage": 60,
	"lvl" : 120,
	"damage_type": "����"
]),
([	"action": "$Nһ�С����·ת����$w�����ػ���$n��$l��ȥ",
	"force" : 210,
	"dodge": -5,
	"damage": 80,
	"lvl" :  145,
	"damage_type": "����"
]),
});

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("tianshan-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
        if (me->query_skill("force") < 30)
                return notify_fail("����ڹ���򲻹�������ѧϰ��ɽ�ȷ���\n");

        if (me->query("max_neili") < 100)
                return notify_fail("�����������������ѧϰ��ɽ�ȷ���\n");

	if ((int)me->query_skill("staff", 1) < (int)me->query_skill("tianshan-zhang", 1))
		return notify_fail("��Ļ����ȷ�ˮƽ���ޣ��޷������������ɽ�ȷ���\n");

        return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (! objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query("qi") < 50)
		return notify_fail("���������������ɽ�ȷ���\n");

	if ((int)me->query("neili") < 40)
		return notify_fail("���������������ɽ�ȷ���\n");

	me->receive_damage("qi", 42);
        me->add("neili", -26);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tianshan-zhang/" + action;
}

