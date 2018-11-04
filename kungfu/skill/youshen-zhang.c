// youshen-zhang.c ���������

inherit SKILL;

string *dodge_msg = ({
        "$n����΢΢һ�Σ���ƮƮ�ĳ�һ�ƣ�����һ�Σ�����������$Nʮ��֮�⡣\n",
        "$n�����󣬵���Ʈ���������ͷ��ĳ�����$N�Ĺ���ȫ�����أ�ֻ���Ա���\n",
        "$n˫�������أ��͵İεض��𣬶㿪��$N����ʽ��\n",
});

mapping *action = ({
([      "action" : "$N�������߲�������$n����Χ����Ȧ����Ȼ�䡰������һ����$n$l����",
        "force" : 260,
        "attack": 40,
        "dodge" : 90,
        "parry" : 90,
        "damage": 30,
        "lvl"   : 0,
        "damage_type" : "����",
]),
([      "action" : "$N����һչ����Ȼ�εض���˫���ͷ��ĳ����ƣ���������$n��$l",
        "force" : 290,
        "attack": 40,
        "dodge" : 100,
        "parry" : 100,
        "damage": 30,
        "lvl"   : 60,
        "damage_type" : "����",
]),
([      "action" : "$N����Ծ���˺���������Ȼ��ȴ�ּ�����ϣ�����$n��$l������һ��",
        "force" : 320,
        "attack": 45,
        "dodge" : 115,
        "parry" : 115,
        "damage": 35,
        "lvl"   : 120,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "unarmed" ||  usage == "parry" ||  usage == "dodge"; } 

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("ѧϰ��������Ʊ�����֡�\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���򲻹����޷�ѧ��������ơ�\n");

        if ((int)me->query_skill("dodge", 1) < 80)
                return notify_fail("��Ļ����Ṧ��򲻹����޷�ѧ��������ơ�\n");

        if ((int)me->query_skill("unarmed", 1) < 80)
                return notify_fail("��Ļ���ȭ�Ż�򲻹����޷�ѧ��������ơ�\n");

        if ((int)me->query("max_neili") < 800)
                return notify_fail("�������̫�����޷�����������ơ�\n");

        if ((int)me->query_skill("unarmed", 1) < (int)me->query_skill("youshen-zhang", 1))
                return notify_fail("��Ļ���ȭ��ˮƽ���ޣ��޷������������������ơ�\n");

        if ((int)me->query_skill("dodge", 1) < (int)me->query_skill("youshen-zhang", 1))
                return notify_fail("��Ļ����Ṧˮƽ���ޣ��޷������������������ơ�\n");

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
        level = (int)me->query_skill("youshen-zhang", 1);
        for(i = sizeof(action); i > 0; i--)
            if(level > action[i-1]["lvl"])
                return action[NewRandom(i, 20, level/5)];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 100)
               return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 80)
               return notify_fail("�������������������ơ�\n");

        me->receive_damage("qi", 80);
        me->add("neili", -60);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"youshen-zhang/" + action;
}
