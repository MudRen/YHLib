#include <ansi.h>

inherit SKILL;

mapping *action = ({
([   "action" : "$N��¶΢Ц������$wһ����һ�С��ӻ����꡹�������ʱ����������$n��$l",
     "force"  : 50,
     "attack" : 15,
     "dodge"  : 10,
     "parry"  : 25,
     "damage" : 10,
     "lvl"    : 0,
     "skill_name" : "�ӻ�����",
     "damage_type":  "����"
]),
([   "action" : "$N����ͻ�������ж��䣬����$w��һ�����벻���ķ�λб����$n��$l",
     "force"  : 70,
     "attack" : 25,
     "dodge"  : 25,
     "parry"  : 30,
     "damage" : 5,
     "lvl"    : 10,
     "skill_name" : "����էչ",
     "damage_type":  "����"
]),
([   "action" : "$N�������ߣ����׸������������$w��Ȼ���ϣ�����һ�С�����һ���㡹������$n",
     "force"  : 75,
     "attack" : 33,
     "dodge"  : 22,
     "parry"  : 32,
     "damage" : 20,
     "lvl"    : 20,
     "skill_name" : "����һ����",
     "damage_type":  "����"
]),
([   "action" : "$N����һ�Σ����Ӷ��ϣ�һ�С����ƲԹ���������$w����һ������׼$n��$l��������",
     "force"  : 90,
     "attack" : 39,
     "dodge"  : 40,
     "parry"  : 35,
     "damage" : 25,
     "lvl"    : 30,
     "skill_name" : "���ƲԹ�",
     "damage_type":  "����"
]),
([   "action" : "$N��ɫ΢�䣬һ�С����컨�꡹�����ж�ʱ��������ޱȣ�����$w��ƥ��������$n��$l",
     "force"  : 180,
     "attack" : 71,
     "dodge"  : 30,
     "parry"  : 52,
     "damage" : 40,
     "lvl"    : 70,
     "skill_name" : "���컨��",
     "damage_type":  "����"
]),
([   "action" : "$N�������ף�����һ�С����Ϯ�ˡ�������$w�й�ֱ����Ѹ���ޱȵ���$n��$l��ȥ",
     "force"  : 200,
     "attack" : 85,
     "dodge"  : 20,
     "parry"  : 54,
     "damage" : 35,
     "lvl"    : 80,
     "skill_name" : "���Ϯ��",
     "damage_type":  "����"
]),
([   "action" : "$N����ಽ��һ�С����µ����ա�������$w���ּ�����������ৡ���һ����$n��$l��ȥ",
     "force"  : 240,
     "attack" : 91,
     "dodge"  : 65,
     "parry"  : 65,
     "damage" : 58,
     "lvl"    : 100,
     "skill_name" : "���µ�����",
     "damage_type":  "����"
]),
([   "action" : "$N��ؼ���һ�����ֳ�ǰ������һ�С����ǵ�׺��������$w��Ϊһ��������$n��$l��ȥ",
     "force"  : 265,
     "attack" : 93,
     "dodge"  : 40,
     "parry"  : 68,
     "damage" : 72,
     "lvl"    : 110,
     "skill_name" : "���ǵ�׺",
     "damage_type":  "����"
]),
([   "action" : "$N����Ծ��һ�С���ӿ�ķ�����������Ӱ������ȴ�ִӰ���д��£�$wֱ��$n��$l",
     "force"  : 290,
     "attack" : 97,
     "dodge"  : 60,
     "parry"  : 72,
     "damage" : 78,
     "lvl"    : 120,
     "skill_name" : "��ӿ�ķ�",
     "damage_type":  "����"
]),
([   "action" : "$Nһ�С����Ӻ�ա�������$wңָ�Կգ���Ȼ����һ����â����$n��$l��ȥ",
     "force"  : 310,
     "attack" : 100,
     "dodge"  : 45,
     "parry"  : 75,
     "damage" : 86,
     "lvl"    : 130,
     "skill_name" : "���Ӻ��",
     "damage_type":  "����"
]),
([   "action" : "$Nһ�С��������ơ����������������$w�͵����·����𣬼���һ�ɾ��練��$n��$l",
     "force"  : 330,
     "attack" : 105,
     "dodge"  : 50,
     "parry"  : 82,
     "damage" : 95,
     "lvl"    : 140,
     "skill_name" : "��������",
     "damage_type":  "����"
]),
});

int valid_enable(string usage) {return usage == "sword" || usage == "parry";}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 800)
                return notify_fail("���������Ϊ������\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("sword", 1) < 80)
                return notify_fail("��Ļ���������򲻹����޷�ѧϰ���ƽ�����\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("rouyun-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷�������������ƽ�����\n");

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
        level = (int)me->query_skill("rouyun-jian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("�������������ϰ���ƽ�����\n");

        me->add("qi", -50);
        me->add("neili", -62);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"rouyun-jian/" + action;
}
