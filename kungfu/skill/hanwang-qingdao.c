// hanwang-qingdao.c �����൶

inherit SKILL;

mapping *action = ({
([      "action": "$Nһ�С��൶��Ӱ����$w����һ��������$n���������Σ�����������仯����",
        "force" : 40,
        "attack": 10,
        "dodge" : -10,
        "parry" : 5,
        "lvl"   : 0,
        "damage": 5,
        "skill_name" : "�൶��Ӱ",
        "damage_type" : "����"
]),
([      "action": "$Nһ�С���ˮǧɽ����������һǰһ��$w����������$n��$lնȥ",
        "force" : 90,
        "attack": 20,
        "dodge" : -10,
        "parry" : 8,
        "damage": 5,
        "lvl"   : 10,
        "skill_name" : "��ˮǧɽ",
        "damage_type" : "����"
]),
([      "action":  "$N����Ծ�䣬һ�С���ɨǧ������$w���ż������һ������$n��ɨ��ȥ",
        "force" : 110,
        "attack": 25,
        "dodge" : -5,
        "parry" : 12,
        "damage": 15,
        "lvl"   : 30,
        "skill_name" : "��ɨǧ��",
        "damage_type" : "����"
]),
([      "action": "$Nһ�С�ָ�㽭ɽ����$w�󿪴��أ����Ҳ�������һ������һ����$n�����翳��",
        "force" : 130,
        "attack": 30,
        "dodge" : 5,
        "parry" : 15,
        "damage": 25,
        "lvl"   : 50,
        "skill_name" : "ָ�㽭ɽ",
        "damage_type" : "����"
]),
([      "action": "$N����$w���϶��£�һ�С�������Ӱ����������к����һƬѩ���ٲ�����$n��ͷ��",
        "force" : 160,
        "attack": 35,
        "dodge" : 10,
        "parry" : 25,
        "damage": 30,
        "lvl"   : 80,
        "skill_name" : "������Ӱ",
        "damage_type" : "����"
]),
([      "action": "$N����$w��ʹ��һ�С�ֱ�����������������ã����ҿ�����ǧ�����������$n",
        "force" : 180,
        "attack": 40,
        "dodge" : 15,
        "parry" : 32,
        "damage": 35,
        "lvl"   : 100,
        "skill_name" : "ֱ������",
        "damage_type" : "����"
]),
([      "action": "$N���õ��羢����һ�С�һ�����ϡ���һ����ת������������$n��$l����ȥ",
        "force" : 190,
        "attack": 45,
        "dodge" : 5,
        "parry" : 35,
        "damage": 50,
        "lvl"   : 120,
        "skill_name" : "һ������",
        "damage_type" : "����"
]),
([      "action": "$N��ǰһ��������һ�С�ǧ��������$wֱֱ��������һƬ�����ĵ�Ӱ��$n��ȫ����ȥ",
        "force" : 220,
        "attack": 50,
        "dodge" : 20,
        "parry" : 45,
        "damage": 60,
        "lvl"   : 150,
        "skill_name" : "ǧ������",
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 30)
                return notify_fail("����ڹ���򲻹���\n");

        if ((int)me->query_skill("blade", 1) < (int)me->query_skill("hanwang-qingdao", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������ĺ����൶��\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("hanwang-qingdao",1);
        for(i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("������������������൶��\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("������������������൶��\n");

        me->receive_damage("qi", 55);
        me->add("neili", -58);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"hanwang-qingdao/" + action;
}
