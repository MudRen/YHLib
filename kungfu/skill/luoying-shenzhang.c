inherit SKILL;

mapping *action = ({
([      "action" : "$N˫��ƽ�죬�����ӳ���һʽ������էչ����ָ�����ᷴ��$n��$l",
        "force"  : 68,
        "attack" : 12,
        "dodge"  : 4,
        "parry"  : 5,
        "damage" : 2,
        "lvl"    : 0,
        "damage_type" : "����",
        "skill_name"  : "����էչ"
]),
([      "action" : "$N������ָ����һ�գ�һʽ���ط����������ָ��Ȼ����$n�崦��Ѩ",
        "force"  : 80,
        "attack" : 14,
        "dodge"  : 7,
        "parry"  : 8,
        "damage" : 5,
        "lvl"    : 20,
        "damage_type" : "����",
        "skill_name"  : "�ط����"
]),
([      "action" : "$N��Ȼһ������ת���������䣬һʽ�����Ƿɻ���������$n��ͷ��",
        "force"  : 91,
        "attack" : 17,
        "dodge"  : 10,
        "parry"  : 13,
        "damage" : 9,
        "lvl"    : 40,
        "damage_type" : "����",
        "skill_name"  : "���Ƿɻ�"
]),
([      "action" : "$NͻȻԾ��˫�������������罣��һʽ���꼱��񡹣�����$n��ȫ��",
        "force"  : 108,
        "attack" : 22,
        "dodge"  : 17,
        "parry"  : 15,
        "damage" : 12,
        "lvl"    : 60,
        "damage_type" : "����",
        "skill_name"  : "�꼱���"
]),
([      "action" : "$N������ֲ�£ʳָ��ָ�����������һʽ���Ǻ����졹��ֱָ$n����",
        "force"  : 138,
        "attack" : 29,
        "dodge"  : 20,
        "parry"  : 25,
        "damage" : 23,
        "lvl"    : 80,
        "damage_type" : "����",
        "skill_name"  : "�Ǻ�����"
]),
([      "action" : "$NͻȻ������ˣ�һʽ�������׷ɡ���ƽ�����˫����$n��������",
        "force"  : 180,
        "attack" : 33,
        "dodge"  : 13,
        "parry"  : 16,
        "damage" : 28,
        "lvl"    : 100,
        "damage_type" : "����",
        "skill_name"  : "�����׷�"
]),
([      "action" : "$NͻȻ����Ծ�����Ʒ�����һʽ������׷�¡���������ǰ��$n��$l��ȥ",
        "force"  : 210,
        "attack" : 38,
        "dodge"  : 30,
        "parry"  : 25,
        "damage" : 33,
        "lvl"    : 120,
        "damage_type" : "����",
        "skill_name"  : "����׷��"
]),
([      "action" : "$Nʹһʽ�������®����ȫ�������ת��˫�ƺ�ǰ�����͵�����$n���ؿ�",
        "force"  : 260,
        "attack" : 44,
        "dodge"  : 34,
        "parry"  : 26,
        "damage" : 41,
        "lvl"    : 140,
        "damage_type" : "����",
        "skill_name"  : "�����®"
]),
([      "action" : "$Nǰ��һ�࣬һʽ�����ƺ�ȡ��������罣��һ����������Ϯ��$n����",
        "force"  : 290,
        "attack" : 52,
        "dodge"  : 43,
        "parry"  : 45,
        "damage" : 51,
        "lvl"    : 160,
        "damage_type" : "����",
        "skill_name"  : "���ƺ��"
]),
([      "action" : "$Nʹһʽ���׺羭�졹��˫���������Ȧ������һ������$n��$l�ȥ",
        "force"  : 310,
        "attack" : 72,
        "dodge"  : 41,
        "parry"  : 55,
        "damage" : 68,
        "lvl"    : 180,
        "damage_type" : "����",
        "skill_name"  : "�׺羭��"
]),
([      "action" : "$N˫��ʳָ����ָһ�ͣ�һʽ��������������һ��ǿ�ҵ�����ӿ��$nȫ��",
        "force"  : 330,
        "attack" : 79,
        "dodge"  : 36,
        "parry"  : 61,
        "damage" : 85,
        "lvl"    : 200,
        "damage_type" : "����",
        "skill_name"  : "��������"
]),
([      "action" : "$Nһʽ����Ӣ���졹��˫������ǰ��ת���ƻ����裬����ǵ�ֱָ��$n",
        "force"  : 378,
        "attack" : 84,
        "dodge"  : 41,
        "parry"  : 65,
        "damage" : 103,
        "lvl"    : 220,
        "damage_type" : "����",
        "skill_name"  : "��Ӣ����"
])
});

int valid_enable(string usage)
{
	return usage == "strike" || usage == "parry";
}

int valid_combine(string combo)
{
	return combo == "lanhua-shou";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����Ӣ���Ʊ�����֡�\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("����ڹ���򲻹����޷�ѧ��Ӣ���ơ�\n");

        if ((int)me->query("max_neili") < 400)
                return notify_fail("�������̫�����޷�����Ӣ���ơ�\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("luoying-shenzhang", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷������������Ӣ���ơ�\n");

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
        level = (int)me->query_skill("luoying-shenzhang", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("���������������Ӣ���ơ�\n");

        me->receive_damage("qi", 45);
        me->add("neili", -40);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"luoying-shenzhang/" + action;
}
