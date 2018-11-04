inherit SKILL;

mapping *action = ({
([      "action" : "$N����͵ط���һʽ���̹ſ��졹���ż�����$n��$l",
        "force"  : 80,
        "damage" : 20,
        "dodge"  : 15,
        "lvl"    : 0,
        "damage_type" : "����",
        "skill_name"  : "�̹ſ���"
]),
([      "action" : "$N��Ŷٵأ��ҽ�һʽ�����Ǹ��¡�������$n��$l",
        "force"  : 120,
        "damage" : 25,
        "dodge"  : 10,
        "lvl"    : 15,
        "damage_type" : "����",
        "skill_name"  : "���Ǹ���"
]),
([      "action" : "$N�������ţ��ҽź��ߣ�������׼��һʽ����ɨǧ��������$n",
        "force"  : 150,
        "damage" : 30,
        "dodge"  : 15,
        "lvl"    : 30,
        "damage_type" : "����",
        "skill_name"  : "��ɨǧ��"
]),
([      "action" : "$NͻȻԾ��˫������Ȧת��һʽ���ٲ����������$n��ȫ��",
        "force"  : 190,
        "damage" : 35,
        "dodge"  : 15,
        "lvl"    : 50,
        "damage_type" : "����",
        "skill_name"  : "�ٲ�����"
]),
([      "action" : "$N˫�Ž�������һʽ��������Ϣ�����ŽŲ���$n����������",
        "force"  : 220,
        "damage" : 40,
        "dodge"  : 20,
        "lvl"    : 70,
        "damage_type" : "����",
        "skill_name"  : "������Ϣ"
]),
([      "action" : "$Nһ�������ҽ����϶��¡����߻�ɽ������$n������ֱ������",
        "force"  : 260,
        "damage" : 45,
        "dodge"  : 35,
        "lvl"    : 90,
        "damage_type" : "����",
        "skill_name"  : "���߻�ɽ"
]),
([      "action" : "$Nʹһʽ���丸׷�ա���˫���ǰ����Ѹ���޼�����$n���ؿ�",
        "force"  : 300,
        "damage" : 50,
        "dodge"  : 30,
        "lvl"    : 100,
        "damage_type" : "����",
        "skill_name"  : "�丸׷��"
]),
([      "action" : "$N�������������һ����һʽ�����춯�ء���˫���͵�����$n��$l",
        "force"  : 330,
        "damage" : 60,
        "dodge"  : 35,
        "lvl"    : 120,
        "damage_type" : "����",
        "skill_name"  : "���춯��"
]),
});

int valid_enable(string usage)
{
        return usage == "unarmed" ||  usage == "parry";
} 

int valid_combine(string combo)
{
        return combo == "tongchui-zhang";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("ѧϰ�����ȱ�����֡�\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("����ڹ���򲻹����޷�ѧ�����ȡ�\n");

        if ((int)me->query("max_neili") < 500)
                return notify_fail("�������̫�����޷��������ȡ�\n");

        if ((int)me->query_skill("unarmed", 1) < (int)me->query_skill("jueming-tui", 1))
                return notify_fail("��Ļ���ȭ�Ż�򲻹����޷���������ľ����ȷ���\n");

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

        level = (int)me->query_skill("jueming-tui", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("������������������ȡ�\n");

        me->receive_damage("qi", 60);
        me->add("neili", -51);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jueming-tui/" + action;
}
