inherit SKILL;

mapping *action = ({
([      "action" : "$N����$w���ƣ�һ�С��Ʋ�������������������$nl��ȥ",
        "skill_name" : "�Ʋ�����",
        "force"  : 120,
        "attack" : 35,
        "dodge"  : 30,
        "parry"  : 12,
        "lvl"    : 0,
        "damage" : 40,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С�ɳŸ�Ӳ������������¶��ϻ��˸��뻡��$wһ��һ�գ�ƽ�л���$n��$l",
        "skill_name" : "ɳŸ�Ӳ�",
        "force"  : 160,
        "attack" : 42,
        "dodge"  : 40,
        "parry"  : 15,
        "lvl"    : 20,
        "damage" : 50,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С���������������$w��������һ�㣬����ǵ�ѹ��$n",
        "skill_name" : "��������",
        "force"  : 185,
        "attack" : 51,
        "dodge"  : 45,
        "parry"  : 17,
        "lvl"    : 40,
        "damage" : 60,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С��������ȡ�������ƽƽ�ĳ�������$w������б����$n��ȥ",
        "skill_name" : "��������",
        "force"  : 220,
        "attack" : 55,
        "dodge"  : 55,
        "parry"  : 21,
        "lvl"    : 60,
        "damage" : 70,
        "damage_type" : "����",
]),
([      "action" : "$N����$w��ת��Ծ��һ�С���´��ʡ���һ���׹�����$n��$l",
        "skill_name" : "��´���",
        "force"  : 255,
        "attack" : 65,
        "dodge"  : 60,
        "parry"  : 32,
        "lvl"    : 80,
        "damage" : 80,
        "damage_type" : "����",
]),
([      "action" : "$N����$w��ʹ��һ�С��׺���᡹���������ã����ҿ�����������$n",
        "skill_name" : "�׺����",
        "force"  : 290,
        "attack" : 70,
        "dodge"  : 70,
        "parry"  : 35,
        "lvl"    : 120,
        "damage" : 90,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С�������ů�������Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
        "skill_name" : "������ů",
        "force"  : 320,
        "attack" : 80,
        "dodge"  : 85,
        "parry"  : 35,
        "lvl"    : 160,
        "damage" : 100,
        "damage_type" : "����",
]),
([      "action" : "$N���ʹһ�С��˷��ص�������ʱ�����������䵶��������˷�ӿ��$n$l",
        "skill_name" : "�˷��ص�",
        "force"  : 340,
        "attack" : 110,
        "dodge"  : 100,
        "parry"  : 50,
        "lvl"    : 200,
        "damage" : 110,
        "damage_type" : "����",
]),
});

string main_skill() { return "daojian-guizhen"; }

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("daojian-guizhen", 1))
                return notify_fail("���Ѿ�����ҽ����ͺ��ҵ������ߺ�һ�ˡ�\n");

        if ((int)me->query("max_neili") < 1400)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("blade", 1) < 120)
                return notify_fail("��Ļ���������򲻹����޷�ѧϰ���ҵ�����\n");

        if ((int)me->query_skill("blade", 1) < (int)me->query_skill("hujia-daofa", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������ĺ��ҵ�����\n");
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
        level   = (int) me->query_skill("hujia-daofa", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if ((int)me->query_skill("daojian-guizhen", 1))
                return notify_fail("���Ѿ�����ҽ����ͺ��ҵ������ߺ�һ�ˡ�\n");

        if ( ! objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("������������������˺��ҵ�����\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("������������������˺��ҵ�����\n");

        me->receive_damage("qi", 50);
        me->add("neili", -80);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"hujia-daofa/" + action;
}
