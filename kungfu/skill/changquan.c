inherit SKILL;

mapping *action = ({
([      "action": "ֻ��$N����һ�����������һ���������ڡ���׼$n���Ӻ�������ȥ",
        "dodge": 5,
        "parry": 5,
        "force": 90,
        "skill_name" : "������",
        "damage_type":  "����"
]),
([      "action": "$N����һ�֣���ȭ������һ�С��β�Ѱ�ߡ�����$n��$l�к���ȥ",
        "dodge": 5,
        "parry": 5,
        "force": 60,
        "skill_name" : "�β�Ѱ��",
        "damage_type":  "����"
]),
([      "action": "$N��ȭ��$n����һ�Σ�����ʹ�˸���Ҷ��͵�ҡ���$n��$l����һץ",
        "dodge": 5,
        "parry": 5,
        "force": 60,
        "skill_name" : "Ҷ��͵��",
        "damage_type":  "ץ��"
]),
([      "action": "$N����һ������ȭ��������ȭ���磬һ�С��ڻ����ġ�����$n��$l",
        "dodge": 5,
        "parry": 5,
        "force": 80,
        "skill_name" : "�ڻ�����",
        "damage_type":  "����"
]),
([      "action": "$N������ʽ��һ�С�˫������ʹ�û����з硣����ȴһ������$n",
        "dodge": 5,
        "parry": 5,
        "force": 70,
        "skill_name" : "˫����",
        "damage_type":  "����"
]),
([      "action": "$N�����󹭲���˫��ʹ�˸�������Ʊա���$n��$lһ��",
        "dodge": 5,
        "parry": 5,
        "force": 50,
        "skill_name" : "����Ʊ�",
        "damage_type":  "����"
]),
([      "action": "$N����һ�ݣ�����ʹ�˸��������̸���������ɨ��$n��$l",
        "dodge": 5,
        "parry": 5,
        "force": 50,
        "skill_name" : "�����̸�",
        "damage_type":  "����"
]),
([      "action": "$Nת�����ƻ��أ����Ʒ���ʹ�˸���������ɽ����$n��ͷһ��",
        "dodge": 5,
        "parry": 5,
        "force": 90,
        "skill_name" : "������ɽ",
        "damage_type":  "����"
]),
});

string main_skill() { return "baihua-cuoquan"; }

int valid_learn(object me)
{
        int lv = me->query_skill("changquan", 1);

        if (me->query_skill("baihua-cuoquan", 1) > 0)
                return notify_fail("���Ѿ������˰ٻ���ȭ�������ٵ���ѧϰ��\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��̫�泤ȭ������֡�\n");

        if (me->query_skill("unarmed", 1) < lv
           && me->query_skill("cuff", 1) < lv)
                return notify_fail("��ȭ����ȭ��������㣬�޷�������"
                                   "���̫�泤ȭ��\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage == "cuff" || usage == "unarmed" || usage == "parry";
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
        if ((int)me->query("qi") < 100)
                return notify_fail("����������������Ϣһ�������ɡ�\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("������������ˡ�\n");

        me->receive_damage("qi", 80);
        me->add("neili", -50);
        return 1;
}
