inherit SKILL;

mapping *action = ({
([      "action": "ֻ��$N����һ�ݣ�һ�С����Ӷ�ˮ�����һȭ����$n��$l",
        "dodge": 15,
        "parry": 15,
        "attack": 20,
        "force": 120,
        "damage_type":  "����"
]),
([      "action": "$N����һ������ȭ��������ȭ���磬һ�С���β�֡��Ʋ��ɵ��ػ���$n$l",
        "dodge": 25,
        "parry": 25,
        "attack": 30,
        "force": 140,
        "damage_type":  "����"
]),
([      "action": "ֻ��$N������ʽ��һ�С���ˮ�ơ�ʹ�û����з硣����ȴ����һ������$n$l",
        "dodge": 20,
        "parry": 20,
        "attack": 25,
        "force": 160,
        "damage_type":  "����"
]),
([      "action": "$Nһ��ת�����ƻ��أ�����ʹ�˸����ٻ���š���$n��ͷһȭ",
        "dodge": 30,
        "parry": 30,
        "attack": 40,
        "force": 270,
        "damage_type":  "����"
]),
([      "action": "ֻ��$N������ʽ��һ�С�ƽ���ơ�ʹ�û����з磬��ֻ����һ�����$n��$l",
        "dodge": 20,
        "parry": 20,
        "attack": 25,
        "force": 160,
        "damage_type":  "����"
]),
([      "action": "$Nһ��ת�����ƻ��أ�����ʹ�˸����������衹��$n��ͷ����",
        "dodge": 30,
        "parry": 30,
        "attack": 40,
        "force": 270,
        "damage_type":  "����"
]),
});

string main_skill() { return "baihua-cuoquan"; }

int valid_learn(object me)
{
        if (me->query_skill("baihua-cuoquan", 1) > 0)
                return notify_fail("���Ѿ������˰ٻ���ȭ�������ٵ���ѧϰ�ˡ�\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ȭ������֡�\n");

        if ((int)me->query_skill("unarmed", 1) < (int)me->query_skill("yanqing-quan", 1))
                return notify_fail("��Ļ���ȭ�Ż���㣬�޷��������������ȭ��\n");

        if ((int)me->query_skill("cuff", 1) < (int)me->query_skill("yanqing-quan", 1))
                return notify_fail("���ȭ����������㣬�޷��������������ȭ��\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage == "cuff" || usage=="unarmed" || usage=="parry";
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
        if( (int)me->query("qi") < 100 )
                return notify_fail("����������������Ϣһ�������ɡ�\n");

        if( (int)me->query("neili") < 80 )
                return notify_fail("������������ˡ�\n");

        me->receive_damage("qi", 80);
        me->add("neili", -50);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yanqing-quan/" + action;
}
