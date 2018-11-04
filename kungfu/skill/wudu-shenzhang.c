inherit SKILL;

mapping *action = ({
([	"action" : "$Nһ�С�б����·�������Ƶ�������֮�ϣ�����$n",
	"force" : 80,
        "attack": 2,
	"dodge" : 30,
        "parry" : 1,
	"damage": 5,
	"lvl"   : 0,
	"skill_name" : "б����·",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�ǧɽ��ɾ�������ɫ���أ�˫����ƮƮ������$n",
	"force" : 100,
        "attack": 8,
	"dodge" : 25,
        "parry" : 3,
	"damage": 30,
	"lvl"   : 20,
	"skill_name" : "ǧɽ��ɾ�",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�������������˫�ƻû�һƬ��Ӱ����$n�������ڡ�",
	"force" : 130,
        "attack": 12,
	"dodge" : 43,
        "parry" : 4,
	"damage": 35,
	"lvl"   : 30,
	"skill_name" : "��������",
	"damage_type" : "����"
]),

([	"action" : "$Nһ�С���ˮǧɽ������$n��$l��������",
	"force" : 150,
        "attack": 15,
	"dodge" : 55,
        "parry" : 8,
	"damage": 50,
	"lvl"   : 40,
	"skill_name" : "��ˮǧɽ",
        "damage_type" : "����"
]),
([	"action" : "$Nһ�С��������𡹣�ֻ��һƬ��Ӱ����$n",
	"force" : 180,
        "attack": 22,
	"dodge" : 52,
        "parry" : 0,
	"damage": 30,
	"lvl"   : 60,
	"skill_name" : "��������",
	"damage_type" : "����"
]),

([	"action" : "$N˫��ƽ�ӣ�һ�С�����ն��������$n",
	"force" : 230,
        "attack": 23,
	"dodge" : 65,
        "parry" : 11,
	"damage": 50,
	"lvl"   : 80,
	"skill_name" : "����ն��",
        "damage_type" : "����"
]),
([	"action" : "$Nһ�С��������¡���ֻ��һƬ��Ӱ����$n",
	"force" : 260,
        "attack": 28,
	"dodge" : 63,
        "parry" : 5,
	"damage": 80,
	"lvl"   : 100,
	"skill_name" : "��������",
	"damage_type" : "����"
]),

([	"action" : "$Nʩ������ɽ��ˮ�������ֺ�ɨ$n��$l�����ֹ���$n���ؿ�",
	"force" : 280,
        "attack": 25,
	"dodge" : 77,
	"damage": 90,
        "parry" : 12,
	"lvl"   : 120,
	"skill_name" : "��ɽ��ˮ",
        "damage_type" : "����"
]),
([	"action" : "$N������Σ�����һ�ǡ�Ϧ�����¡�����$n��ͷ��",
	"force" : 320,
        "attack": 31,
	"dodge" : 80,
        "parry" : 15,
	"damage": 100,
	"lvl"   : 140,
	"skill_name" : "Ϧ������",
        "damage_type" : "����"
]),
([	"action" : "$Nʩ���������塹��˫��ͬʱ����$n��$l",
	"force" : 360,
        "attack": 32,
	"dodge" : 81,
        "parry" : 10,
	"damage": 130,
	"lvl"   : 160,
	"skill_name" : "������",
        "damage_type" : "����"
])
});

int valid_enable(string usage)
{
	return usage == "parry" || usage == "strike";
}

int valid_learn(object me)
{
       if (me->query("character") != "�ĺ�����") 
                return notify_fail("���嶾���Ʊ���Ҫ�ĺ��������ҿ���������û�������\n"); 

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���嶾���Ʊ�����֡�\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻹����޷����嶾���ơ�\n");

	if ((int)me->query("max_neili") < 1200)
		return notify_fail("�������̫�����޷����嶾���ơ�\n");

        if ((int)me->query_skill("strike", 1) < 120)
                return notify_fail("��Ļ����Ʒ���򲻹����޷����嶾���ơ�\n");

	if ((int)me->query_skill("strike", 1) < (int)me->query_skill("wudu-shenzhang", 1))
		return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷�����������嶾���ơ�\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("wudu-shenzhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 90)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 80)
		return notify_fail("��������������嶾���ơ�\n");

	me->receive_damage("qi", 81);
	me->add("neili", -73);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"wudu-shenzhang/" + action;
}
