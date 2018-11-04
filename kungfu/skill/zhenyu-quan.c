inherit SKILL;

mapping *action = ({
([      "action" : "$Nվ�����ɣ�һʽ����ɽ¾�ǡ�������ȭ����������������$n��$l",
        "force"  : 40,
        "attack" : 8,
        "parry"  : 3,
        "dodge"  : 2,
        "damage" : 5,
        "lvl"    : 0,
        "skill_name"  : "��ɽ¾��",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ���𺣷��ġ�����ȭ�»�����ȭ���ֱ�壬�������",
        "force"  : 55,
        "attack" : 9,
        "parry"  : 1,
        "dodge"  : 2,
        "damage" : 7,
        "lvl"    : 10,
    	"skill_name"  : "�𺣷���",
    	"damage_type" : "����"
]),
([  	"action" : "$N�ڿշ���һʽ�����졹��ȭʽ�������߳���$n��æ����",    
        "force"  : 64,
        "attack" : 12,
        "parry"  : 5,
        "dodge"  : 3,
        "damage" : 9,
        "lvl"    : 30,
    	"skill_name"  : "����",
    	"damage_type" : "����"
]),
([  	"action" : "$N˫ȭ����������ͻ��һʽ����꡹����$n����",
        "force"  : 71,
        "attack" : 13,
        "parry"  : 4,
        "dodge"  : 6,
        "damage" : 11,
        "lvl"    : 50,
    	"skill_name"  : "���",
    	"damage_type" : "����"
]),
([  	"action" : "$N���ۺ�չ��ȭ�б��ƣ�һʽ��������������$n��Ҵ����Ѩ",    
        "force"  : 84,
        "attack" : 18,
        "parry"  : 13,
        "dodge"  : 12,
        "damage" : 15,
        "lvl"    : 70,
    	"skill_name"  : "����",
    	"damage_type" : "����"
]),
([  	"action" : "$N��ǰһ����ʩһʽ��������������ȭ��ָ������$n����ǰ��Ѩ",
        "force"  : 93,
        "attack" : 21,
        "parry"  : 7,
        "dodge"  : 9,
        "damage" : 19,
        "lvl"    : 90,
    	"skill_name"  : "��������",
    	"damage_type" : "����"
]),
([  	"action" : "$N���䲻�⣬���϶��£�һʽ�������ɢ�������ܿ�����������ͻ����",
        "force"  : 101,
        "attack" : 24,
        "parry"  : 8,
        "dodge"  : 12,
        "damage" : 25,
        "lvl"    : 120,
    	"skill_name"  : "�����ɢ",
   	"damage_type" : "����"
]),
([  	"action" : "$N��üһ�壬˫ȭ�����뷢��һʽ����ɽ����������$n��ͷ��",
        "force"  : 140,
        "attack" : 28,
        "parry"  : 13,
        "dodge"  : 12,
        "damage" : 27,
        "lvl"    : 150,
    	"skill_name"  : "��ɽ��",
    	"damage_type" : "����"
])
});

int valid_enable(string usage)
{
	return usage == "cuff" || usage == "parry";
}

int valid_combine(string combo)
{
        return combo == "poyue-zhao";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ȭ��������֡�\n");

        if ((int)me->query_skill("force") < 20)
                return notify_fail("����ڹ���򲻹����޷�ѧ����ȭ����\n");

        if ((int)me->query("max_neili") < 200)
                return notify_fail("���������Ϊ̫ǳ���޷�������ȭ����\n");

        if ((int)me->query_skill("cuff", 1) < 10)
                return notify_fail("��Ļ���ȭ�����̫ǳ���޷�������ȭ����\n");

        if ((int)me->query_skill("cuff", 1) < (int)me->query_skill("zhenyu-quan", 1))
                return notify_fail("��Ļ���ȭ��ˮƽ���ޣ��޷��������������ȭ����\n");

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
        level = (int) me->query_skill("zhenyu-quan", 1);
        for (i = sizeof(action); i > 0; i--)
            if (level > action[i-1]["lvl"])
                return action[NewRandom(i, 5, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("�����������������ȭ����\n");

        me->receive_damage("qi", 45);
        me->add("neili", -25);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"zhenyu-quan/" + action;
}
