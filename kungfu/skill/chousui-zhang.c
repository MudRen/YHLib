inherit SKILL;

mapping *action = ({
([      "action": "$N����¶�������Ц�ݣ�����������ɫ��˫��ɨ��$n��$l",
        "force" : 180,
        "attack": 49,
        "dodge" : -30,
        "parry" : -37,
        "dmage" : 32,
        "damage_type": "����"
]),
([      "action": "$NͻȻ������ת��������$n��˫�Ʒ���������$n��$l",
        "force" : 230,
        "attack": 56,
        "dodge" : -22,
        "parry" : -34,
        "dmage" : 47,
        "damage_type": "����"
]),
([      "action": "$N�������������֣�һ�С���ʬ���������ޱȵ�ץ��$n��$l",
        "force" : 260,
        "attack": 61,
        "dodge" : -20,
        "parry" : 10,
        "dmage" : 60,
        "damage_type": "����"
]),
([      "action": "$Nһ���ֽУ�˫��Ю��һ���ȳ�֮������$n��$l",
        "force" : 380,
        "attack": 79,
        "dodge" : 17,
        "parry" : 36,
        "dmage" : 65,
        "damage_type": "����"
]),
([      "action": "$Nҧ����⣬������Ѫ���ۼ�ȫ�����������$n",
        "force" : 420,
        "attack": 81,
        "dodge" : 27,
        "parry" : 21,
        "dmage" : 75,
        "damage_type": "����"
]),
});

int valid_enable(string usage)
{
        return usage == "strike" || usage == "parry";
}

int valid_combine(string combo)
{
        return combo == "sanyin-wugongzhao";
}

int valid_learn(object me)
{
        if ((int)me->query_skill("poison", 1) < 50)
                return notify_fail("��Ļ����������㣬�޷��������ơ�\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���򲻹����޷��������ơ�\n");

        if ((int)me->query_skill("strike", 1) < 80)
                return notify_fail("����Ʒ��������㣬�޷��������ơ�\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("���������Ϊ̫�����޷��������ơ�\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("choushui-zhang", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷���������ĳ����Ʒ���\n");

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
        level = (int) me->query_skill("chousui-zhang", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("������������������ơ�\n");

        me->receive_damage("qi", 65);
        me->add("neili", -55);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"chousui-zhang/" + action;
}
