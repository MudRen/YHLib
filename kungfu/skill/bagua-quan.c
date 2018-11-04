inherit SKILL;

mapping *action=({
([	"action" : "$N˫��һ��ʹ����Ǭ�־�����˫ȭһ��һ�¶�׼$n��$l��������",
        "force" : 60,
        "attack": 20,
        "dodge" : 40,
        "parry" : 5,
        "damage": 4,
        "lvl"   : 0,
	"skill_name" : "Ǭ�־�",
	"damage_type" : "����"
]),
([	"action" : "$N����$nһת���������ߣ�ȭ����磬���಻���ػ���$n�����ǰ���ȭ�еġ����־���",
        "force" : 80,
        "attack": 25,
        "dodge" : 43,
        "parry" : 6,
        "damage": 7,
        "lvl"   : 20,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$Nʹ��һ�С����־�������ȭ���$n��ǰ�أ�һ������ȭѸ�ٺ�ɨ$n��̫��Ѩ",
        "force" : 100,
        "attack": 28,
        "dodge" : 45,
        "parry" : 8,
        "damage": 10,
        "lvl"   : 40,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$Nʹһ�С����־�����ȭ������������ʽʹ�ϣ���ȭ�Ѵ���ȭ֮�״�������׼$n��$l��������һȭ",
        "force" : 120,
        "attack": 35,
        "dodge" : 47,
        "parry" : 11,
        "damage": 17,
        "lvl"   : 60,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$Nʹ��һ�С����־���������һ�ͣ����ֻ�����������Ѹ�ײ����ڶ���һȭ����$n���ɲ�",
        "force" : 140,
        "attack": 40,
        "dodge" : 49,
        "parry" : 13,
        "damage": 20,
        "lvl"   : 90,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$N��ȭͻȻ�ſ���ȭ�����ƣ�ֱ����Ϊ��ɨ��һ�С����־�������$n��$l�к���ȥ",
        "force" : 200,
        "attack": 48,
        "dodge" : 54,
        "parry" : 18,
        "damage": 28,
        "lvl"   : 120,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С����־�������ʱ�ó�����ȭӰ��������磬����ǵ�Ϯ��$nȫ��",
        "force" : 280,
        "attack": 60,
        "dodge" : 63,
        "parry" : 23,
        "damage": 37,
        "lvl"   : 150,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$N΢΢һЦ���������־���������Ծ�𣬰����һ������$n���ţ�ȴ�Ǹ����С�\n"
	           "˵ʱ����ʱ�죬ֻ��$Nһ��������˫ȭ�ѵ���$n��$l",
        "force" : 290,
        "attack": 62,
        "dodge" : 65,
        "parry" : 25,
        "damage": 40,
        "lvl"   : 180,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
});

int valid_enable(string usage)
{
	return usage == "cuff" || usage == "parry";
}

int valid_combine(string combo)
{
	return combo == "bagua-zhang";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ȭ������֡�\n");

        if (me->query("max_neili") < 150)
                return notify_fail("��������������޷���ϰ����ȭ��\n");

        if ((int)me->query_skill("cuff", 1) < (int)me->query_skill("bagua-quan", 1))
                return notify_fail("��Ļ���ȭ��������ޣ��޷���������İ���ȭ��\n");

        return 1;
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
        level = (int)me->query_skill("bagua-quan", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70 )
                return notify_fail("����������������Ϣһ�������ɡ�\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("������������ˡ�\n");

        me->receive_damage("qi", 65);
        me->add("neili", -40);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"bagua-quan/" + action;
}
