// lianhua-zhi.c ����ָ

inherit SKILL;

mapping *action = ({
([      "action": "$N����̧�ۣ���ָ���˸���Ȧ��һʽ�����¿���������$n��$l",
        "force" : 100,
        "attack": 10,
        "parry" : 15,
        "dodge" : -5,
        "lvl"   : 0,
        "skill_name" : "���¿���",
        "damage_type" : "����"
]),
([      "action": "$N�������У�һʽ�������Ŀ������ָ��Ҹ������ָ��$n����ǰ",
        "force" : 140,
        "attack": 15,
        "parry" : 18,
        "dodge" : -5,
        "lvl"   : 20,
        "skill_name" : "�����Ŀ",
        "damage_type" : "����"
]),
([      "action": "$N����б�У����ְ��ƣ�����һʽ���������㡹����$n��$l����",
        "force" : 170,
        "attack": 20,
        "parry" : 25,
        "dodge" : 5,
        "lvl"   : 40,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action": "$N˫Ŀ΢����һʽ�������ų�����˫�ֻû���ǧ�ٸ�ָӰ������$n��$l",
        "force" : 210,
        "attack": 28,
        "parry" : 30,
        "dodge" : 5,
        "damage": 10,
        "lvl"   : 60,
        "skill_name" : "�����ų�",
        "damage_type" : "����"
]),
([      "action": "$Nһʽ���߱������������ƻ�ס�������бָ���죬���Ƶ���$n��$l",
        "force" : 250,
        "attack": 30,
        "parry" : 35,
        "dodge" : 15,
        "damage": 10,
        "lvl"   : 80,
        "skill_name" : "�߱�����",
        "damage_type" : "����"
]),
([      "action": "$N˫��ƽ����ǰ��ʮָ�濪��һʽ��Ҷ����������ָ��$n�������Ѩ",
        "force" : 280,
        "attack": 45,
        "parry" : 40,
        "dodge" : 20,
        "damage": 15,
        "lvl"   : 100,
        "skill_name" : "Ҷ������",
        "damage_type" : "����"
]),
});

string main_skill() { return "canhe-zhi"; }

int valid_enable(string usage) { return usage == "finger" ||  usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("canhe-zhi", 1))
                return notify_fail("���ѽ�����ָ������κ�ָ�������ٷֿ���ϰ�ˡ�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ָ������֡�\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("����ڹ���򲻹����޷�ѧ����ָ��\n");

        if ((int)me->query_skill("finger", 1) < 60)
                return notify_fail("��Ļ���ָ����򲻹����޷�ѧ����ָ��\n");

        if ((int)me->query("max_neili") < 800)
                return notify_fail("�������̫�����޷�������ָ��\n");

        if (me->query_skill("finger", 1) < me->query_skill("lianhua-zhi", 1))
                return notify_fail("��Ļ���ָ��̫��޷��������������ָ��\n");

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
        level = (int)me->query_skill("lianhua-zhi", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query_skill("canhe-zhi", 1))
                return notify_fail("���ѽ�����ָ������κ�ָ�������ٷֿ���ϰ�ˡ�\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("�������̫���ˣ��޷�������ָ��\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("��������������޷�������ָ��\n");

        me->receive_damage("qi", 55);
        me->add("neili", -51);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"lianhua-zhi/" + action;
}
