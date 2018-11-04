// ruanhong-zhusuo.c �������
// by Vin 2000

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N����������һʽ��������˿����������̧��$w�������裬���������Ҳ�ɨ��$n",
        "force" : 98,
        "attack": 41,
        "dodge" : -5,
        "parry" : 15,
        "damage": 32,
        "lvl"   : 0,
        "damage_type": "����"
]),
([      "action": "$Nһʽ����˿������$w���ñ�ֱ�������ڡ��ƿ�������$n���̶�ȥ",
        "force" : 187,
        "attack": 48,
        "dodge" : -20,
        "parry" : 36,
        "damage": 47,
        "lvl"   : 80,
        "damage_type": "����"
]),
([      "action": "$N�ھ���������$w����ת������ԲȦ��һʽ�������ʳ�����Ӱ������$n����",
        "force" : 231,
        "attack": 65,
        "dodge" : -10,
        "parry" : 55,
        "damage": 93,
        "lvl"   : 100,
        "damage_type": "����"
]),
([	"action": "$N����������һʽ������֯�졹��$w��$n��ǰ����������ʽ����Ȼ��$l����������",
        "force" : 263,
        "attack": 70,
	"dodge" : 5,
        "parry" : 60,
	"damage": 102,
	"lvl"   : 120,
	"damage_type": "����"
]),
([	"action": "$Nһ���ߺȣ�ʹ��������׽������$w����ת������Ӱ�ݺᣬ�����ƻã�����$n",
        "force" : 301,
        "attack": 77,
	"dodge" : 6,
        "parry" : 65,
	"damage": 121,
	"lvl"   : 140,
	"damage_type": "����"
]),
([	"action": "$N���ذα���һʽ�������������������鶯���ͣ�����������˷���$n��ѹ��ȥ",
        "force" : 331,
        "attack": 85,
	"dodge" : 12,
        "parry" : 70,
	"damage": 142,
	"lvl"   : 160,
	"damage_type": "����"
]),
([	"action":"$N������ң�һ�С�����ܲ���������$w��������Ӱ����ɽ������ɨ��$nȫ��",
        "force" : 373,
        "attack": 91,
	"dodge" : 17,
        "parry" : 75,
	"damage": 163,
	"lvl"   : 180,
	"damage_type": "����"
]),
([	"action":"$N������ң�һ�С���ز�ʳ��������$w��������Ӱ����ɽ������ɨ��$nȫ��",
        "force" : 401,
        "attack": 98,
	"dodge" : 20,
        "parry" : 85,
	"damage": 189,
	"lvl"   : 200,
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage == "whip" || usage == "parry"; }

int valid_learn(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "whip")
                return notify_fail("���������һ�����Ӳ��������������\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("����������㣬û�а취���������������Щ���������ɡ�\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ����̫ǳ��û�а취�����������\n");

        if ((int)me->query_skill("whip", 1) < 100)
                return notify_fail("��Ļ����޷����̫ǳ��û�а취�����������\n");

        if ((int)me->query_skill("whip", 1) < (int)me->query_skill("ruanhong-zhusuo", 1))
                return notify_fail("��Ļ����޷�ˮƽ���������޷�������������������\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("ruanhong-zhusuo",1);
        for(i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 80)
                return notify_fail("����������������������\n");

        if ((int)me->query("neili") < 90)
                return notify_fail("����������������������\n");

        me->receive_damage("qi", 75);
        me->add("neili", -85);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"ruanhong-zhusuo/" + action;
}
