inherit SKILL;

mapping *action = ({
([      "action" : "ֻ��$N����һ����ʩһ�С��൨���ġ���׼$n�ĺ������˹�ȥ",
        "dodge"  : 15,
        "parry"  : 15,
        "attack" : 20,
        "force"  : 120,
        "damage_type":  "����"
]),
([      "action" : "$N��ȭ��������ȭ���磬һ�С����Ĺ������Ʋ��ɵ��ػ���$n",
        "dodge"  : 25,
        "parry"  : 25,
        "attack" : 30,
        "force"  : 140,
        "damage_type":  "����"
]),
([      "action" : "ֻ��$N������ʽ��˫ȭ���磬ʩһ�С�����բ���������$n��ȥ",
        "dodge"  : 20,
        "parry"  : 20,
        "attack" : 25,
        "force"  : 160,
        "damage_type" : "����"
]),
([      "action" : "$Nһ��ת�����ƻ��أ�����ʹ����ֱ��ֱȥ����$n��ͷһȭ",
        "dodge"  : 30,
        "parry"  : 30,
        "attack" : 40,
        "force"  : 270,
        "damage_type" : "����"
]),
});

int valid_enable(string usage)
{
        return usage == "cuff" || usage == "parry";
}

int valid_combine(string combo)
{
        return combo == "chuanxin-zhang";
}

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ȭ��������֡�\n");

        if ((int)me->query_skill("cuff", 1) < 20)
                return notify_fail("��Ļ���ȭ������㣬������������ȭ����\n");

        if ((int)me->query_skill("cuff", 1) < (int)me->query_skill("tiexian-quan", 1))
                return notify_fail("���ȭ����������㣬�޷��������������ȭ����\n");

        return 1;
}

string query_skill_name(int lvl)
{
        return action[random(sizeof(action))]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 40)
                return notify_fail("����������������Ϣһ�������ɡ�\n");

        if ((int)me->query("neili") < 25)
                return notify_fail("������������ˡ�\n");

        me->receive_damage("qi", 35);
        me->add("neili", -22);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tiexian-quan/" + action;
}
