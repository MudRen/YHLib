inherit SKILL;

mapping *action = ({
([      "action" : "$N����΢����������ǰ�˳���һʽ���ɺ�ժ�ҡ�����צֱ����ץ��$n��˫��",
        "force"  : 180,
        "attack" : 41,
        "parry"  : 35,
        "dodge"  : 35,
        "damage" : 28,
        "lvl"    : 0,
        "damage_type" : "ץ��",
        "skill_name"  : "�ɺ�ժ��"
]),
([      "action" : "$N������Σ�һʽ�������֦��������ֱ��������$n�ļ羮��Ѩ",
        "force"  : 260,
        "attack" : 53,
        "parry"  : 45,
        "dodge"  : 45,
        "damage" : 36,
        "lvl"    : 30,
        "damage_type" : "����",
        "skill_name"  : "�����֦"
]),
([      "action" : "$Nһ��ǰ�죬һ�ۺ�ָ��һʽ��Գ�����桹������$n������",
        "force"  : 310,
        "attack" : 64,
        "parry"  : 53,
        "dodge"  : 53,
        "damage" : 42,
        "lvl"    : 60,
        "damage_type" : "����",
        "skill_name"  : "Գ������"
]),
([      "action" : "$N��Ȼ����һ�ţ�ʹһʽ���˷���Ӱ����˫�������޶���һצץ��$n���ؿ�",
        "force"  : 360,
        "attack" : 75,
        "parry"  : 61,
        "dodge"  : 61,
        "damage" : 52,
        "lvl"    : 90,
        "damage_type" : "����",
        "skill_name"  : "�˷���Ӱ"
]),
([      "action" : "$N����һ������һ������ʹһʽ��ˮ�����¡���˫צ������$n��С��",
        "force"  : 430,
        "attack" : 84,
        "parry"  : 65,
        "dodge"  : 65,
        "damage" : 58,
        "lvl"    : 120,
        "damage_type" : "����",
        "skill_name"  : "ˮ������"
]),
([      "action" : "$N�͵����ϸ߸�Ծ��һʽ�����ժ�ǡ����Ӹ����£�һצ����$n��ͷ��",
        "force"  : 460,
        "attack" : 91,
        "parry"  : 69,
        "dodge"  : 67,
        "damage" : 65,
        "lvl"    : 150,
        "damage_type" : "ץ��",
        "skill_name"  : "���ժ��"
]),
});

int valid_enable(string usage)
{
	return usage == "cuff" ||  usage == "parry";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�����ٺ�ȭ������֡�\n");

        if ((int)me->query("max_neili") < 1200)
                return notify_fail("���������Ϊ̫�����޷������ٺ�ȭ��\n");

        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("��Ļ����ڹ���򲻹����޷������ٺ�ȭ��\n");

        if ((int)me->query_skill("cuff", 1) < 100)
                return notify_fail("��Ļ���ȭ����򲻹����޷������ٺ�ȭ��\n");

        if ((int)me->query_skill("cuff", 1) < (int)me->query_skill("mizong-houquan", 1))
                return notify_fail("��Ļ���ȭ��ˮƽ���ޣ��޷�������������ٺ�ȭ��\n");

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
        level = (int)me->query_skill("mizong-houquan", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 90)
                return notify_fail("����������������ٺ�ȭ��\n");

        me->receive_damage("qi", 55);
        me->add("neili", -78);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"mizong-houquan/" + action;
}
