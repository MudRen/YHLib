inherit SKILL;

mapping *action = ({
([	"action" : "$Nһ����ȣ����Ƶ�������֮�ϣ�����$n",
	"force" : 100,
        "attack": 2,
	"dodge" : 30,
        "parry" : 1,
	"damage": 15,
	"lvl"   : 0,
	"damage_type" : "����"
]),
([	"action" : "$N��ɫ���أ�˫���ᶶ��Ʈ������������$n",
	"force" : 130,
        "attack": 8,
	"dodge" : 25,
        "parry" : 3,
	"damage": 30,
	"lvl"   : 20,
	"damage_type" : "����"
]),
([	"action" : "$N�������˫�ƻû�һƬ��Ӱ����$n�������ڡ�",
	"force" : 160,
        "attack": 12,
	"dodge" : 43,
        "parry" : 4,
	"damage": 35,
	"lvl"   : 40,
	"damage_type" : "����"
]),
([	"action" : "$N��ǰһ���������й�ֱ������$n��$l��������",
	"force" : 210,
        "attack": 15,
	"dodge" : 55,
        "parry" : 8,
	"damage": 50,
	"lvl"   : 60,
        "damage_type" : "����"
]),
([	"action" : "$N������������˫�ƣ���ʱֻ��һƬ��Ӱ����$n",
	"force" : 250,
        "attack": 22,
	"dodge" : 52,
        "parry" : 0,
	"damage": 30,
	"lvl"   : 80,
	"damage_type" : "����"
]),
([	"action" : "$N˫��ƽ�ӣ��ͻ���$n��$l�����ް�㻨�ɿ���",
	"force" : 300,
        "attack": 23,
	"dodge" : 65,
        "parry" : 11,
	"damage": 50,
	"lvl"   : 100,
        "damage_type" : "����"
]),
([	"action" : "$N���������ŷ���˫���ͷ��ĳ�����ʱһƬ��Ӱ����$n",
	"force" : 310,
        "attack": 28,
	"dodge" : 63,
        "parry" : 5,
	"damage": 80,
	"lvl"   : 120,
	"damage_type" : "����"
]),
([	"action" : "$N������Σ�����Я��ǧ��֮����Ȼ��$n��ͷ������",
	"force" : 330,
        "attack": 25,
	"dodge" : 77,
	"damage": 90,
        "parry" : 12,
	"lvl"   : 140,
        "damage_type" : "����"
]),
([	"action" : "$N������ĺ��ƣ����ֺ�ɨ$n��$l�����ֹ���$n���ؿ�",
	"force" : 360,
        "attack": 31,
	"dodge" : 80,
        "parry" : 15,
	"damage": 100,
	"lvl"   : 160,
        "damage_type" : "����"
]),
([	"action" : "$N��Ȼһ�����ȣ������ŷ���˫��ͬʱ����$n��$l",
	"force" : 400,
        "attack": 32,
	"dodge" : 81,
        "parry" : 10,
	"damage": 130,
	"lvl"   : 180,
        "damage_type" : "����"
])
});

int valid_enable(string usage)
{
	return usage == "parry" || usage == "strike";
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����׾�Ʒ�������֡�\n");

        if (me->query("str") < 26)
                return notify_fail("�������������㣬�޷�ѧϰ����Ĺ�׾�Ʒ���\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻹����޷�����׾�Ʒ���\n");

	if ((int)me->query("max_neili") < 1500)
		return notify_fail("�������̫�����޷�����׾�Ʒ���\n");

        if ((int)me->query_skill("strike", 1) < 100)
                return notify_fail("��Ļ����Ʒ���򲻹����޷�����׾�Ʒ���\n");

	if ((int)me->query_skill("strike", 1) < (int)me->query_skill("guzhuo-zhang", 1))
		return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷���������Ĺ�׾�Ʒ���\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("guzhuo-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 90)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 80)
		return notify_fail("���������������׾�Ʒ���\n");

	me->receive_damage("qi", 81);
	me->add("neili", -73);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"guzhuo-zhang/" + action;
}
