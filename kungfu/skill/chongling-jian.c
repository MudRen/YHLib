// ���齣��
// Modified by rcwiz Oct.1997
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "name"  : "��÷�綹",
        "action": "$N����$wһ����һ�С���÷�綹��ʹ��������������ǧ����$n��$l��ȥ",
        "force" : 70,
	"attack": 10,
	"parry" : 5,
        "dodge" : 10,
        "damage": 30,
        "lvl"   : 0,
        "damage_type":  "����"
]),
([      "name"  : "���г���",
        "action": "$N�����죬һ�С����г�������ʹ������$wֱָ$n$l",
        "force" : 120,
	"attack": 20,
	"parry" : 15,
        "dodge" : 20,
        "damage": 40,
        "lvl"   : 20,
        "damage_type":  "����"
]),
([      "name"  : "���է��",
        "action": "$N����$w��ת�������ƹ��ǹ���������ͻת������$n�������ƺ�������ǧ�п�",
        "force" : 160,
	"attack": 25,
	"parry" : 20,
        "dodge" : 30,
        "damage": 45,
        "lvl"   : 40,
        "damage_type":  "����"
]),
([      "name"  : "ͬ������",
        "action": "$N��̾һ�����粽��ǰ��ʹһ�С�ͬ��������������$wб�̶��������ز������Ľ�������֮����",
        "force" : 280,
	"attack": 60,
	"parry" : 10,
        "dodge" : 10,
        "damage": 50,
        "lvl"   : 60,
        "damage_type":  "����"
]),
});

int valid_learn(object me)
{
    object ob;

    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������û�а취�����齣����\n");

    if (me->query_skill("huashan-jian", 1) < 100)
        return notify_fail("�㻪ɽ������򲻹����޷������齣����\n");

    if (! (ob = me->query_temp("weapon"))
    ||  (string)ob->query("skill_type") != "sword" )
        return notify_fail("���������һ�ѽ�����ѧϰ���齣����\n");

    if (me->query_skill("sword", 1) < me->query_skill("chongling-jian", 1))
	return notify_fail("��Ļ�������������ޣ��޷���������ĳ��齣����\n");

    return 1;
}

int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level = (int) me->query_skill("chongling-jian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 60)
        return notify_fail("�������̫�ͣ�û�а취��ϰ���齣����\n");

    if (me->query_skill("huashan-jian", 1) < 100)
        return notify_fail("�㻪ɽ������򲻹����޷������齣����\n");
                
    if ((int)me->query("neili") < 40)
        return notify_fail("�������������û�а취��ϰ���齣����\n");

    me->receive_damage("qi", 50);
    me->add("neili", -31);
    return 1;
}
