inherit SKILL;

string *dodge_msg = ({
        "$nһ�������ѵ�ˮ���������$N��һ�С�\n",
        "$n�������һ�ݣ�ʹ��һ�С�ϸ���ɷ��ơ����ܹ���$N�Ĺ�����\n",
        "$nʹ�����黳���ȡ���ǡ�ö����$N�Ĺ��ơ�\n"
        "����$n����Ʈ��������һ�ݣ����ѱܿ���\n",
        "$n����΢�Σ��о����յرܿ���$N��һ�С�\n"
});

mapping *action = ({
([      "action" : "$Nһ�������һ�С����б�꡹ֱϮ$n��$l�����ް��ۼ�",
        "force"  : 30,
        "dodge"  : 30,
        "damage" : 2,
        "lvl"    : 0,
        "skill_name"  : "���б��",
        "damage_type" : "����"
]),
([      "action" : "$Nת��������һ�С��������ϡ��������㣬���ƻ���$n������",
        "force"  : 50,
        "dodge"  : 40,
        "damage" : 5,
        "lvl"    : 10,
        "skill_name"  : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N�鲽����һ�С���Ҷ���⡹������һת������$n",
        "force"  : 60,
        "dodge"  : 45,
        "damage" : 10,
        "lvl"    : 20,
        "skill_name"  : "��Ҷ����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С���·δ������˫�ƻ���������Ӱ����ƮƮ������$n",    
        "force"  : 70,
        "dodge"  : 55,
        "damage" : 15,
        "lvl"    : 34,
        "skill_name"  : "��·δ��",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С������������������ָ΢΢�ſ�������n������",    
        "force"  : 90,
        "dodge"  : 70,
        "damage" : 20,
        "lvl"    : 45,
        "skill_name"  : "�������",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��һ�С���ң���䡹��һ���ĳ����·�ʳ����˼��̻�",  
        "force"  : 110,
        "dodge"  : 75,
        "damage" : 25,
        "lvl"    : 59,
        "skill_name"  : "��ң����",
        "damage_type" : "����"
]),
([      "action" : "$N����Ʈ����һ�С�������������˫�������������$n",
        "force"  : 120,
        "dodge"  : 80,
        "damage" : 30,
        "lvl"    : 80,
        "skill_name"  : "��������",
        "damage_type" : "����"
]),
});

int valid_enable(string usage)
{
        return usage == "dodge"
            || usage == "parry"
            || usage == "unarmed";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("ѧϰ��ң��ȭ��������֡�\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���򲻹����޷�ѧ��ң��ȭ����\n");

        if ((int)me->query("max_neili") < 800)
                return notify_fail("���������Ϊ̫�����޷�����ң��ȭ����\n");

        if ((int)me->query_skill("unarmed", 1) < (int)me->query_skill("xiaoyaoyou", 1))
                return notify_fail("��Ļ���ȭ��ˮƽ���ޣ��޷������������ң��ȭ����\n");

        if ((int)me->query_skill("dodge", 1) < (int)me->query_skill("xiaoyaoyou", 1))
                return notify_fail("��Ļ����Ṧˮƽ���ޣ��޷������������ң��ȭ����\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action) - 1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;

        level = (int)me->query_skill("xiaoyaoyou", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("�������̫���ˣ���������ң��ȭ����\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("�������̫���ˣ���������ң��ȭ����\n");

        me->receive_damage("qi", 60);
        me->add("neili", -45);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xiaoyaoyou/" + action;
}
