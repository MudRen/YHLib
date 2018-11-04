inherit SKILL;

mapping *action = ({
([      "action": "�ں��������У�$Nʹһ�С����ڶ�ʳ����˫���繳��ꫣ�����$n��$l",
        "force" : 60,
        "dodge" : 17,
        "parry" : 1,
        "damage": 1,
        "damage_type" : "ץ��"
]),
([      "action": "$N����һԾ���������ϣ�ʹ��һ�С�������ʳ��������ֱֱץ��$n��$l",
        "force" : 80,
        "dodge" : 20,
        "parry" : 5,
        "damage": 3,
        "damage_type" : "ץ��"
]),
([      "action": "$N˫��ƽ�죬ʮָ΢΢���¶�����һ�С�ɽ�����ѡ�����$n��$l",    
        "force" : 120,
        "dodge" : 32,
        "parry" : 10,
        "damage": 5,
        "damage_type" : "ץ��"
]),
([      "action": "$Nʹ��һ�С�ҹ�ڷ�ߡ���������Ϣ��������$n��ǰ���͵�һצ����ץ��$n��$l",
        "force" : 132,
        "dodge" : 38,
        "parry" : 19,
        "damage": 5,
        "damage_type" : "ץ��"
]),
([      "action": "$N˫��ƽ����ǰ�����ֻ�ס���ţ�һ�С����Ϲǡ���������$n��$l",
        "force" : 137,
        "dodge" : 41,
        "parry" : 21,
        "damage": 7,
        "damage_type" : "ץ��"
]),
([      "action": "$Nʹ�������ֻ�Х�����ͺ�һ����˫�ֻ���Ϊצ��һǰһ��ץ��$n��$l",
        "force" : 143,
        "dodge" : 49,
        "parry" : 22,
        "damage": 9,
        "damage_type" : "ץ��"
]),
([      "action": "$Nʹ���������̶�����˫צ����������׼$n��$l����ץ��",
        "force" : 151,
        "dodge" : 58,
        "parry" : 38,
        "damage": 15,
        "damage_type" : "ץ��"
])
});

string main_skill() { return "baihua-cuoquan"; }

int valid_learn(object me)
{
        if (me->query_skill("baihua-cuoquan", 1) > 0)
                return notify_fail("���Ѿ������˰ٻ���ȭ�������ٵ���ѧϰ�ˡ�\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����צ�ֱ�����֡�\n");

        if ((int)me->query_skill("claw", 1) < (int)me->query_skill("huzhao-shou", 1))
                return notify_fail("��Ļ���צ������㣬�޷���������Ļ�צ�֡�\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage == "claw" || usage=="parry";
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
        return __DIR__"huzhao-shou/" + action;
}
