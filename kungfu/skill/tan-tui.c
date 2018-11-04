inherit SKILL;

mapping *action = ({
([      "action" : "$N����͵ط���һʽ��һ�����������ż�����$n��$l",
        "force"  : 80,
        "damage" : 20,
        "dodge" : 15,
        "lvl" : 0,
        "damage_type" : "����",
        "skill_name" : "һ������"
]),
([      "action" : "$N��Ŷٵأ��ҽ�һʽ��������ת�����͵�����$n��$l",
        "force"  : 120,
        "damage" : 25,
        "dodge" : 10,
        "lvl" : 10,
        "damage_type" : "����",
        "skill_name" : "������ת"
]),
([      "action" : "$N�������ţ��ҽź��ߣ�������׼��һʽ��ʮ������������$n",
        "force"  : 150,
        "damage" : 30,
        "dodge" : 15,
        "lvl" : 20,
        "damage_type" : "����",
        "skill_name" : "ʮ������"
]),
([      "action" : "$NͻȻԾ��˫������Ȧת��һʽ��˫�����š�������$n��ȫ��",
        "force"  : 190,
        "damage" : 35,
        "dodge" : 15,
        "lvl" : 40,
        "damage_type" : "����",
        "skill_name" : "˫������"
]),
([      "action" : "$N˫�Ž�������һʽ���������̡����ŽŲ���$n����������",
        "force"  : 220,
        "damage" : 40,
        "dodge" : 20,
        "lvl" : 60,
        "damage_type" : "����",
        "skill_name" : "��������"
]),
([      "action" : "$Nһ�������ҽ����϶��¡�����һ���ޡ�����$n������ֱ������",
        "force"  : 260,
        "damage" : 45,
        "dodge" : 35,
        "lvl" : 80,
        "damage_type" : "����",
        "skill_name" : "����һ����"
]),
([      "action" : "$Nʹһʽ��ʮ�������⡹��˫���ǰ����Ѹ���޼�����$n���ؿ�",
        "force"  : 300,
        "damage" : 50,
        "dodge" : 30,
        "lvl" : 100,
        "damage_type" : "����",
        "skill_name" : "ʮ��������"
]),
([      "action" : "$N�������������һ����һʽ��Ϭţ����ת�ػ�����˫������$n",
        "force"  : 330,
        "damage" : 60,
        "dodge" : 35,
        "lvl" : 120,
        "damage_type" : "����",
        "skill_name" : "Ϭţ����ת�ػ�"
]),
});

int valid_enable(string usage) { return usage == "unarmed" ||  usage == "parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("ѧϰʮ��·̶�ȱ�����֡�\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("����ڹ���򲻹����޷�ѧʮ��·̶�ȡ�\n");

        if ((int)me->query("max_neili") < 500)
                return notify_fail("�������̫�����޷���ʮ��·̶�ȡ�\n");

        if ((int)me->query_skill("unarmed", 1) < (int)me->query_skill("tan-tui", 1))
                return notify_fail("�����ȭ�Ż�򲻹����޷����������ʮ��·̶�ȡ�\n");

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

        level = (int)me->query_skill("tan-tui", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("�������������ʮ��·̶�ȡ�\n");

        me->receive_damage("qi", 60);
        me->add("neili", -51);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tan-tui/" + action;
}
