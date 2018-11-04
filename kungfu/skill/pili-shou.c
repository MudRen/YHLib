// pili-shou.c ��Ԫ������
// create by rcwiz 2003

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһʽ����ָ���ġ�������ֱȡ$n��$l",
	"force" : 100,
        "dodge" : 15,
        "parry" : 20,
	"damage": 10,
	"lvl"   : 0,
	"skill_name" : "��ָ����",
        "damage_type" : "����"
]),
([	"action" : "$N���һ����һʽ��������ͷ����˫�������ۻ��ޱȣ���������$n��$l",
	"force" : 130,
        "dodge" : 10,
        "parry" : 15,
	"damage": 20,
	"lvl"   : 30,
	"skill_name" : "������ͷ",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһʽ����Ԫ�޼ʡ������������������Ȼ������ֱȡ$n��$l",
	"force" : 160,
        "dodge" : 20,
        "parry" : 20,
	"damage": 25,
	"lvl"   : 60,
	"skill_name" : "��Ԫ�޼�",
        "damage_type" : "����"
]),
([	"action" : "$N����һ�֣�һʽ��������������������з���֮�ƣ���$n��ȥ",
	"force" : 180,
        "dodge" : 20,
        "parry" : 30,
	"damage": 30,
	"lvl"   : 80,
	"skill_name" : "�������",
        "damage_type" : "����"
]),
([	"action" : "$N����һת��ʹ��һʽ����Ԫ����������$N��������һ������ֱ�£�����$n",
	"force" : 210,
        "dodge" : 25,
        "parry" : 20,
	"damage": 35,
	"lvl"   : 100,
	"skill_name" : "��Ԫ��",
        "damage_type" : "����"
]),
([	"action" : "$NͻȻ�������ʹ��һʽ�������꡹��˫���������������籩�������$nȫ��",
	"force" : 250,
        "dodge" : 25,
        "parry" : 25,
	"damage": 40,
	"lvl"   : 120,
	"skill_name" : "������",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһʽ����������˫��һ�֣��͵�����$n��$l",
	"force" : 290,
        "dodge" : 30,
        "parry" : 30,
	"damage": 55,
	"lvl"   : 140,
	"skill_name" : "�������",
        "damage_type" : "����"
]),
([	"action" : "$Nһ�С����׷ɿա���˫�ƴ�����ɪ������֮��������$n��$l",
	"force" : 330,
        "dodge" : 30,
        "parry" : 35,
	"damage": 70,
	"lvl"   : 150,
	"skill_name" : "���׷ɿ�",
        "damage_type" : "����"
]),
([	"action" : "$N����Ȼһ�䣬ʹ��һʽ������ʽ������Ӱǧ����ã���$n�޷�����",
	"force" : 350,
        "dodge" : 40,
        "parry" : 45,
	"damage": 80,
	"lvl"   : 160,
	"skill_name" : "����ʽ",
        "damage_type" : "����"
]),
([	"action" : "$N��Хһ����һʽ�����������˫�ƻ��裬���ƷǷ�������$n��$l",
	"force" : 380,
        "dodge" : 45,
        "parry" : 50,
	"damage": 130,
	"lvl"   : 180,
	"skill_name" : "��������",
        "damage_type" : "����"
])
});

int valid_enable(string usage)
{
	return usage=="strike" || usage=="parry";
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����Ԫ�����ֱ�����֡�\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ���򲻹����޷�����Ԫ�����֡�\n");

	if ((int)me->query("max_neili") < 900)
		return notify_fail("�������̫�����޷�����Ԫ�����֡�\n");

        if ((int)me->query_skill("hand", 1) < 80)
		return notify_fail("��Ļ����ַ���򲻹����޷�����Ԫ�����֡�\n");

        if ((int)me->query_skill("hand", 1) < (int)me->query_skill("pili-shou", 1))
		return notify_fail("��Ļ����ַ�ˮƽ���ޣ��޷���������Ļ�Ԫ�����֡�\n");

	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("pili-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 80)
		return notify_fail("�������̫���ˡ�\n");

	if ((int)me->query("neili") < 80)
		return notify_fail("���������������Ԫ�����֡�\n");

	me->receive_damage("qi", 6);
	me->add("neili", -64);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"pili-shou/" + action;
}
