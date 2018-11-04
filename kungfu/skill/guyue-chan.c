inherit SKILL;

mapping *action = ({
([      "action":"$N�ݲ���ǰ������$w���¶��ϣ������ޱȵ���$n��С����ȥ",
        "force" : 35,
        "attack": 8,
        "dodge" : -10,
        "parry" : 5,
        "damage": 5,
        "lvl"   : 0,
        "damage_type":"����"
]),
([      "action":"$N�첽���������ƽ��$w�����������ȶˣ�����$n���ؿ�",
        "force" : 50,
        "attack": 10,
        "dodge" : -10,
        "parry" : 8,
        "damage": 8,
        "lvl"   : 30,
        "damage_type":"����"
]),
([      "action":"$N�߾�$w��ȫ��Ծ������$w����$nͷ���������Ȼ������ȥ",
        "force" : 65,
        "attack": 15,
        "dodge" : -5,
        "parry" : 10,
        "damage": 12,
        "lvl"   : 60,
        "damage_type":"����"
]),
([      "action":"$N˫�ֳ������֣���׼$n�͵�һ������ͬƽ�ع���һ������",
        "force" : 80,
        "attack": 18,
        "dodge" : -5,
        "parry" : 12,
        "damage": 15,
        "lvl"   : 80,
        "damage_type":"����"
]),
([      "action":"$N���$w���ȶ˻���������ԲȦ�����ͳ��أ���$n��������",
        "force" : 100,
        "attack": 26,
        "dodge" : -15,
        "parry" : 18,
        "damage": 20,
        "lvl"   : 100,
        "damage_type":"����"
]),
([      "action":"$Nȫ�������$w�̵غ�ɣ�����������Ӱ����Ӱ��$n��������",
        "force" : 130,
        "attack": 35,
        "dodge" : 5,
        "parry" : 22,
        "damage": 27,
        "lvl"   : 120,
        "damage_type":"����"
]),
([      "action":"$N˫�ֺ�ʮ������һ�ݳ�$w��ֻ��$w������ɳ���������$nײȥ",
        "force" : 160,
        "attack": 40,
        "dodge" : -5,
        "parry" : 28,
        "damage": 30,
        "lvl"   : 140,
        "damage_type":"����"
]),
([      "action":"$N���һ��������$w�������������Ծ����ֱ��$n���ؿڴ���",
        "force" : 180,
        "attack": 52,
        "dodge" : -5,
        "parry" : 35,
        "damage": 35,
        "lvl"   : 160,
        "damage_type":"����"
]),
});

int valid_enable(string usage)
{
        return usage == "staff" || usage == "parry";
}

int valid_learn(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "staff")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("max_neili") < 400)
                return notify_fail("���������Ϊ���㣬�޷�ѧϰ���²�����\n");

        if ((int)me->query_skill("force") < 60)
                return notify_fail("����ڹ����̫ǳ���޷�ѧϰ���²�����\n");

        if ((int)me->query_skill("staff", 1) < 20)
                return notify_fail("��Ļ����ȷ�̫ǳ���޷�ѧϰ���²�����\n");

        if ((int)me->query_skill("staff", 1) < (int)me->query_skill("poshui-zhang", 1))
                return notify_fail("��Ļ����ȷ�ˮƽ���ޣ��޷���������Ĺ��²�����\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("guyue-chan", 1);

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "staff")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("����������������²�����\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("����������������²�����\n");

        me->receive_damage("qi", 65);
        me->add("neili", -58);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"guyue-chan/" + action;
}
