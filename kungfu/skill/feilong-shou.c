inherit SKILL;

mapping *action = ({
([      "action": "�ں��������У�$Nʹһ�С�����׽Ӱ����˫���繳��ꫣ�����$n��$l",
        "force" : 80,
        "attack": 25,
        "dodge" : 20,
        "parry" : 25,
        "damage": 10,
        "lvl"   : 0,
        "damage_type" : "����"
]),
([      "action": "$N˫ȭ���裬һʽ������ȥ���������ֻ��ۣ�£��Ȧ״���ͻ�$n�����",
        "force" : 100,
        "attack": 28,
        "dodge" : 20,
        "parry" : 27,
        "damage": 20,
        "lvl"   : 30,
        "damage_type" : "����"
]),
([      "action": "$Nһ�С�������צ����˫�ַ׷ɣ�$nֻ���ۻ�����",
        "force" : 120,
        "attack": 32,
        "dodge" : 30,
        "parry" : 28,
        "damage": 30,
        "lvl"   : 60,
        "damage_type" : "����"
]),
([      "action": "$N���ֻ��أ�Ҹ�º��գ�������ָ�繳��һ�С�������ȱ������$n�Ķ���",
        "force" : 150,
        "attack": 33,
        "dodge" : 30,
        "parry" : 33,
        "damage": 35,
        "lvl"   : 80,
        "damage_type" : "����"
]),
([      "action": "$Nһ�ֶ����צ��һ��ָ�أ�һ�С����Ƽ��ա�����������$n��ȫ��",
        "force" : 180,
        "attack": 36,
        "dodge" : 30,
        "parry" : 37,
        "damage": 45,
        "lvl"   : 100,
        "damage_type" : "����"
]),

([      "action": "$N˫��ƽ�٣�һ�С�������ˮ�������λ���һ����������$n",
        "force" : 210,
        "attack": 42,
        "dodge" : 35,
        "parry" : 45,
        "damage": 40,
        "lvl"   : 120,
        "damage_type" : "����"
]),
([      "action": "$Nһ�С�������צ��������$n���ƺ�$n��ȫ��������",
        "force" : 240,
        "attack": 47,
        "dodge" : 30,
        "parry" : 41,
        "damage": 45,
        "lvl"   : 140,
        "damage_type" : "����"
]),

([      "action": "$N������Σ�����һ�ǡ��������졹����$n��ͷ��",
        "force" : 260,
        "attack": 46,
        "dodge" : 30,
        "parry" : 47,
        "damage": 50,
        "lvl"   : 160,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="parry"|| usage=="hand"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������̽���ֱ�����֡�\n");

        if ((int)me->query("max_neili") < 2500)
                return notify_fail("�������̫�����޷�������̽���֡�\n");

        if ((int)me->query_skill("force") < 200)
                return notify_fail("����ڹ���򲻹����޷�������̽���֡�\n");

        if ((int)me->query_skill("hand", 1) < 150)
                return notify_fail("��Ļ����ַ���򲻹����޷�������̽���֡�\n");

        if ((int)me->query_skill("hand", 1) < (int)me->query_skill("feilong-shou", 1))
                return notify_fail("��Ļ����ַ�ˮƽ���ޣ��޷���������ķ���̽���֡�\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("feilong-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("�����������������̽���֡�\n");

        me->receive_damage("qi", 65);
        me->add("neili", -62);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"feilong-shou/" + action;
}

