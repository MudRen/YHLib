#include <ansi.h>
inherit SKILL;

mapping *action = ({
([     "action" : "$N��צǰ�죬����˿˿����������һʽ��Ԫ����ϡ����͵���$n�Ķ��Ų���",
       "force" : 150,
       "damage" : 30,
       "dodge" : 5,
       "lvl" : 0,
       "weapon" : "��ָ",
       "damage_type" : "ץ��"
]),
([     "action" : "$N˫�����ģ�����һ����ǽ����$n����Ȼһצ�����ȴ��ġ�������ǽֱ��$n��$l",
       "force" : 160,
       "dodge" : 10,
       "damage": 30,
       "lvl" : 0,
       "weapon" : "ָ��",
       "damage_type" : "����"
]),
([     "action" : "$Nʹ����Ѫ������˫צ����$n��ס$l��������������������һ������Ҫ��$n�����Ƭ",
       "force" : 170,
       "dodge" : 0,
       "damage": 40,
       "lvl" : 20,
       "weapon" : "ָ��",
       "damage_type" : "����"
]),
([     "action" : "$N˫צ£ס$n��ʹһʽ�����������������ڹ���צ��͸��$n���ڣ�ֱϮ����ؽ�",
       "force" : 180,
       "dodge" : 5,
       "damage": 60,
       "lvl" : 30,
       "damage_type" : "����"
]),
([     "action" : "$N��͸ָ�⣬��$n����ʵʵ��ץʮ��צ��������Ϯ�塹��������������ס$n",
       "force" : 200,
       "dodge" : 15,
       "damage": 60,
       "weapon" : "����",
       "lvl" : 40,
       "damage_type" : "����"
]),
([     "action" : "$Nһʽ���������֡�����צ���·����γ�����צӰ���ұ�һ�죬���Ȱ�ץ��$n��$l",
       "force" : 240,
       "dodge" : 5,
       "damage": 67,
       "weapon" : "��ץ",
       "lvl" : 50,
       "damage_type" : "ץ��"
]),
([     "action" : "$N̽����ǰ��˳��$n���ֱ���Եֱ�ϣ�����Ϊצ��һ�С��»�Ԧħ��ץ��$n��$l",
       "force" : 260,
       "dodge" : 5,
       "damage": 70,
       "lvl"   : 70,
       "weapon": "��צ",
       "damage_type" : "ץ��"
]),
});

int valid_enable(string usage)
{
	return usage == "claw" ||  usage == "parry";
}

int valid_combine(string combo)
{
	return combo == "tianchan-zhang";
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("����ʥ��צ������֡�\n");

        if ((int)me->query("max_neili") < 200)
            return notify_fail("�������̫�����޷�����ʥ��צ��\n");

	if ((int)me->query_skill("claw", 1) < (int)me->query_skill("wusheng-zhao", 1))
	    return notify_fail("��Ļ���צ��ˮƽ���ޣ��޷������������ʥ��צ��\n");

	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("wusheng-zhao",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 5, level/5)];

}

int practice_skill(object me)
{
	object* ob;
	int i,skill,damage;

	skill = me->query_skill("wusheng-zhao",1);
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫���ˡ�\n");

	if ((int)me->query("neili") < 40)
		return notify_fail("���������������ʥ��צ��\n");

	me->receive_damage("qi", 30);
        me->add("neili", -31);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"wusheng-zhao/" + action;
}
