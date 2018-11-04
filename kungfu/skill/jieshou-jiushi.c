inherit SKILL;

mapping *action = ({
([	"action" : "$N���ƽ�������ǰ̽��һ�С���ʽ�ֽ𡹣��Ʒ�ֱ����$n��$l",
        "force" : 120,
        "attack": 10,
        "dodge" : 5,
        "parry" : 5,
        "damage": 35,
        "lvl"   : 0,
	"skill_name" : "��ʽ�ֽ�",
	"damage_type" : "����"
]),
([	"action" : "$N���ж�ת��һ�С�������ɽ�������ֻ��⣬����ֱ��$nǰ��",
        "force" : 140,
        "attack": 15,
        "dodge" : 7,
        "parry" : 7,
        "damage": 38,
        "lvl"   : 20,
	"skill_name" : "������ɽ",
	"damage_type" : "ץ��"
]),
([	"action" : "$N���һ����һ�С�˳ˮ���ۡ������в��䣬������Ѹ�仯�ƣ�б��$n�ĺ�����",
        "force" : 170,
        "attack": 21,
        "dodge" : 11,
        "parry" : 11,
        "damage": 43,
        "lvl"   : 40,
	"skill_name" : "˳ˮ����",
	"damage_type" : "����",
]),
([	"action" : "$N˫�������������룬һ�С������Ὥ����ȥ����죬��$n��$l��ȥ��",
        "force" : 190,
        "attack": 25,
        "dodge" : 13,
        "parry" : 13,
        "damage": 45,
        "lvl"   : 70,
	"skill_name" : "�����Ὥ",
	"damage_type" : "����"
]),
([	"action" : "$N�������,�����Ϸ⣬������ѹ������������$n��$l",
        "force" : 220,
        "attack": 35,
        "dodge" : 15,
        "parry" : 15,
        "damage": 51,
        "lvl"   : 100,
	"skill_name" : "����С��",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�����������������ǰһ��͵�������ֻ�����ǰ����,����˳�Ʒ���$n������",
        "force" : 240,
        "attack": 55,
        "dodge" : 18,
        "parry" : 18,
        "damage": 55,
        "lvl"   : 130,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([	"action" : "$N�Ų����ţ���ȻԾ��$n������,һ�С�����ãã�������ִ���$n��$l",
        "force" : 270,
        "attack": 61,
        "dodge" : 25,
        "parry" : 25,
        "damage": 58,
        "lvl"   : 160,
	"skill_name" : "����ãã",
	"damage_type" : "����"
]),
([	"action" : "$N��ָ΢΢���죬һ�С���ɽ��ˮ������Ӱ������ٰ㽫$n����������",
        "force" : 310,
        "attack": 75,
        "dodge" : 25,
        "parry" : 25,
        "damage": 65,
        "lvl"   : 200,
	"skill_name" : "��ɽ��ˮ",
	"damage_type" : "����"
]),
([	"action" : "$NͻȻ��ü��������̬��ɢ�����ַ��飬$n��һ���ȣ���Ȼ�е�һ����ɽ�������Ʒ�Ϯ��",
        "force" : 340,
        "attack": 85,
        "dodge" : 30,
        "parry" : 30,
        "damage": 71,
        "lvl"   : 250,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="hand" ||  usage=="parry"; }

int valid_combine(string combo) { return combo == "jinding-zhang" || combo == "tiangang-zhi"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�����־�ʽ������֡�\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���򲻹����޷�ѧ���־�ʽ��\n");

        if ((int)me->query("max_neili") < 500)
                return notify_fail("�������̫�����޷������־�ʽ��\n");

        if (me->query_skill("hand", 1) < me->query_skill("jieshou-jiushi", 1))
                return notify_fail("��Ļ���ָ��̫��޷���������Ľ��־�ʽ��\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action) - 1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("jieshou-jiushi", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("�������̫���ˣ��޷������־�ʽ��\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("��������������޷������־�ʽ��\n");

        me->receive_damage("qi", 55);
        me->add("neili", -51);
        return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jieshou-jiushi/" + action;
}
