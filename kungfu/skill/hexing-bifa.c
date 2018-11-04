
inherit SKILL;

mapping *action = ({
([      "action":"$Nһ�С��ɺ�չ�᡹������$w��Ȼ����$nС��",
        "force" : 120,
        "attack": 24,
        "dodge" : 10,
        "parry" : 20,
        "damage": 45,
        "lvl"   : 0,
        "skill_name" : "�ɺ�չ��",
        "damage_type" : "����"
]),
([      "action":"$N���˷�����һ�С�������Ѩʽ��������$w����$n���Ѩ",
        "force" : 150,
        "attack": 40,
        "dodge" : 14,
        "parry" : 30,
        "damage": 60,
        "lvl"   : 40,
        "skill_name" : "������Ѩʽ",
        "damage_type" : "����"
]),
([      "action":"$N����$w��Ȼ��ת��ʹ�����ƿ��ճ���������$n������Ѩ",
        "force" : 180,
        "attack": 60,
        "dodge" : 25,
        "parry" : 32,
        "damage": 75,
        "lvl"   : 60,
        "skill_name" : "�ƿ��ճ�",
        "damage_type" : "����"
]),
([      "action":"$N����$w�������죬ʹ����������ת����$wֱ��$n������Ѩ",
        "force" : 220,
        "attack": 50,
        "dodge" : 5,
        "parry" : 35,
        "damage": 70,
        "lvl"   : 80,
        "skill_name" : "������ת",
        "damage_type" : "����"
]),
([      "action":"$N����Ծ��һʽ�������⡹������$w������ǧ�����$n�ɻ���ȥ",
        "force" : 260,
        "attack": 70,
        "dodge" : 10,
        "parry" : 45,
        "damage": 80,
        "lvl"   : 100,
        "skill_name" : "������",
        "damage_type" : "����"
]),
([      "action":"$N��ʽ��Ȼ������һ�С�����ɼ���������$w������֮��ֱϮ$wҪѨ",
        "force" : 300,
        "attack": 100,
        "dodge" : 51,
        "parry" : 50,
        "damage": 110,
        "lvl"   : 120,
        "skill_name" : "����ɼ�",
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "dagger") || (usage == "parry"); }

int valid_learn(object me)
{
        object ob;

        if ((int)me->query("max_neili") < 300)
                return notify_fail("���������Ϊ������\n");

        if (! (ob = me->query_temp("weapon"))
        ||  (string)ob->query("skill_type") != "dagger" )
                return notify_fail("���������һ����Ӧ����������ѧϰ���αʷ���\n");

        if ((int)me->query_skill("dagger", 1) < (int)me->query_skill("hexing-bifa", 1))
                return notify_fail("��Ļ����̱�ˮƽ���ޣ��޷���������ĺ��αʷ���\n");

    return 1;
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

        level = (int) me->query_skill("hexing-bifa", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "dagger")
                return notify_fail("�����ֵ������޷���ϰ���αʷ���\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("����������������αʷ���\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("����������������αʷ���\n");

        me->receive_damage("qi", 55);
        me->add("neili", -52);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"hexing-bifa/" + action;
}
