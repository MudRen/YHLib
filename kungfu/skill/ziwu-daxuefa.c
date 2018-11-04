
inherit SKILL;

mapping *action = ({
([      "action":"$Nһ�С�����������������$wһ����������$n������Ѩ",
        "force" : 90,
        "attack": 15,
        "dodge" : -10,
        "parry" : 20,
        "damage": 25,
        "lvl"   : 0,
        "skill_name" : "��������",
        "damage_type" : "��Ѩ"
]),
([      "action":"$N��������һ�С��ٳ󵱵�����$w���������£���$n�׺�Ѩ��ȥ",
        "force" : 130,
        "attack": 30,
        "dodge" : -10,
        "parry" : 30,
        "damage": 30,
        "lvl"   : 40,
        "skill_name" : "�ٳ󵱵�",
        "damage_type" : "��Ѩ"
]),
([      "action":"$N��ǰ����һ�����������ս�⣬����$wʹ������ʱ���ơ�������$n�ĵز�Ѩ",
        "force" : 170,
        "attack": 40,
        "dodge" : 5,
        "parry" : 32,
        "damage": 35,
        "lvl"   : 60,
        "skill_name" : "��ʱ����",
        "damage_type" : "��Ѩ"
]),
([      "action":"$N���е�$w������ҵ�һ�Σ�ʹ������î���ġ����ź����������$n������Ѩ",
        "force" : 190,
        "attack": 50,
        "dodge" : 5,
        "parry" : 35,
        "damage": 40,
        "lvl"   : 80,
        "skill_name" : "��î����",
        "damage_type" : "��Ѩ"
]),
([      "action":"$N����Ծ��һʽ���粻���ӡ������������Ӱ��$w��$n�͹�Ѩ�����ȥ",
        "force" : 240,
        "attack": 60,
        "dodge" : 10,
        "parry" : 45,
        "damage": 50,
        "lvl"   : 100,
        "skill_name" : "�粻����",
        "damage_type" : "��Ѩ"
]),
([      "action":"$N�������У�$w�Ƴ�����ѩ���ʷ棬�ӳ�����Ԫ���졹��һ�п���һ�еع���$n",
        "force" : 260,
        "attack": 65,
        "dodge" : 5,
        "parry" : 50,
        "damage": 60,
        "lvl"   : 120,
        "skill_name" : "��Ԫ����",
        "damage_type" : "��Ѩ"
]),
([      "action":"$Nʹ��һ�С���ҫ�ƶ����й�ֱ����$w�������ѣ���;��Ȼת�����ϴ���$n",
        "force" : 280,
        "attack": 70,
        "dodge" : 5,
        "parry" : 52,
        "damage": 75,
        "lvl"   : 140,
        "skill_name" : "��ҫ�ƶ�",
        "damage_type" : "��Ѩ"
]),
([      "action":"$N����б��һ�У�����һʽ����ɷ��ء�����ź�����������$n��Χ����",
        "force" : 310,
        "attack": 75,
        "dodge" : 5,
        "parry" : 64,
        "damage": 90,
        "lvl"   : 150,
        "skill_name" : "��ɷ���",
        "damage_type" : "��Ѩ"
]),
});


int valid_enable(string usage) { return (usage == "dagger") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 500)
                return notify_fail("���������Ϊ̫ǳ���޷��������Ѩ����\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ����̫ǳ���޷��������Ѩ����\n");

        if ((int)me->query_skill("dagger", 1) < 80)
                return notify_fail("��Ļ����̱����̫ǳ���޷��������Ѩ����\n");

        if ((int)me->query_skill("dagger", 1) < (int)me->query_skill("ziwu-daxuefa", 1))
                return notify_fail("��Ļ����̱�ˮƽ���ޣ��޷���������������Ѩ����\n");

    return 1;
}

string query_skill_name(int level)
{
        int i;

        for(i = sizeof(action) - 1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;

        level = (int) me->query_skill("ziwu-daxuefa", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "dagger")
                return notify_fail("�����ֵ������޷���ϰ�����Ѩ����\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("������������������Ѩ����\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("������������������Ѩ����\n");

        me->receive_damage("qi", 65);
        me->add("neili", -62);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"ziwu-daxuefa/" + action;
}
