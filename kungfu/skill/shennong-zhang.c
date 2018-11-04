// shennong-zhang.c ��ũ�ȷ�
// Edit By Vin Oo 22/2/2001

inherit SKILL;

mapping *action = ({
([      "action": "$N΢һ����һ�С������������$w���Ŵ̶���֨֨��������ɨ��$n�Ľ���",
        "force" : 130,
        "attack": 10,
        "dodge" : -5,
        "parry" : 19,
        "damage": 20,
        "lvl"   : 0,
        "skill_name" : "�������",
        "damage_type":"����"
]),
([      "action": "$Nһ�С��������ա���������ס�ȶˣ����ƾ���һ��������ƾ���Ե���$n�ļ�ͷ",
        "force" : 140,
        "attack": 15,
        "dodge" : -10,
        "parry" : 15,
        "damage": 25,
        "lvl"   : 20,
        "skill_name" : "��������",
        "damage_type":"����"
]),
([      "action": "$Nһ�С��丸���ա�������һԾ����$w����ת����ͣ���Ƶ�$n�����ұܣ��Ǳ�����",
        "force" : 150,
        "attack": 20,
        "dodge" : -5,
        "parry" : 19,
        "damage": 30,
        "lvl"   : 40,
        "skill_name" : "�丸����",
        "damage_type":"����"
]),
([      "action": "$Nһ�С�Īа�콣��������$wбָ���죬�����ض���һ�ᣬͻȻ�͵�һ�ȴ���$n��$l",
        "force" : 160,
        "attack": 25,
        "dodge" : -5,
        "parry" : 22,
        "damage": 40,
        "lvl"   : 60,
        "skill_name" : "Īа�콣",
        "damage_type":"����"
]),
([      "action": "$N�߾�$w����Ȼһ�����ȣ��ȶ�ңָ$n��һ�С�������ˮ����Я�ź�Х������$n",
        "force" : 180,
        "attack": 30,
        "dodge" : -15,
        "parry" : 28,
        "damage": 50,
        "lvl"   : 80,
        "skill_name" : "������ˮ",
        "damage_type":"����"
]),
([      "action": "$Nһ�С��������ҡ�������һչ�����ȿ�ӣ�$wȫ��һ��������$n��ȥ",
        "force" : 210,
        "attack": 35,
        "dodge" : 5,
        "parry" : 32,
        "damage": 57,
        "lvl"   : 100,
        "skill_name" : "��������",
        "damage_type":"����"
]),
([      "action": "$N��ɫׯ�ϣ�һ�С���ԯ���������˳�$w����Ȼ������һ�Σ������һ����չ���$n��ȥ",
        "force" : 240,
        "attack": 40,
        "dodge" : -5,
        "parry" : 37,
        "damage": 60,
        "lvl"   : 120,
        "skill_name" : "��ԯ����",
        "damage_type":"����"
]),
([      "action": "$Nһ�С����������������ֳ��ȣ���ע���󣬴�$n������ $w�͵ص�����𣬻���$n",
        "force" : 260,
        "attack": 45,
        "dodge" : -5,
        "parry" : 45,
        "damage": 71,
        "lvl"   : 140,
        "skill_name" : "��������",
        "damage_type":"����"
]),
([      "action": "$Nһ�С�Ů洲��졹����Ȼһ�������εض��𣬸߾�$w��մ���$n��ͷ��",
        "force" : 280,
        "attack": 50,
        "dodge" : -5,
        "parry" : 55,
        "damage": 70,
        "lvl"   : 160,
        "skill_name" : "Ů洲���",
        "damage_type":"����"
]),
([      "action": "$Nһ�С����¾Ѫ�����������Ų��ƣ�$wȴ�ζ���������ƫ���еص�����$n��ҪѨ",
        "force" : 310,
        "attack": 55,
        "dodge" : -5,
        "parry" : 58,
        "damage": 84,
        "lvl"   : 180,
        "skill_name" : "���¾Ѫ",
        "damage_type":"����"
]),
([      "action": "$N�߾�$w��һ�С��̹ſ��졹����������Ȱ�Ʈ������׼$n�������һ�ȴ���",
        "force" : 330,
        "attack": 61,
        "dodge" : -5,
        "parry" : 62,
        "damage": 90,
        "lvl"   : 200,
        "skill_name" : "�̹ſ���",
        "damage_type":"����"
]),
([      "action": "$Nһ�С���ũ�ٲݡ������ȶ�����$w���ǧ�ٸ����ƣ���������$nȫ�����Ҫ��",
        "force" : 350,
        "attack": 65,
        "dodge" : -5,
        "parry" : 67,
        "damage": 95,
        "lvl"   : 220,
        "skill_name" : "��ũ�ٲ�",
        "damage_type":"����"
]),
});

int valid_enable(string usage) { return usage == "staff" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 800)
                return notify_fail("���������Ϊ������\n");

        if ((int)me->query_skill("force") < 130)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("staff") < 50)
                return notify_fail("��Ļ����ȷ�ˮƽ���㡣\n");

        if ((int)me->query_skill("staff", 1) < (int)(int)me->query_skill("shennong-zhang", 1))
                return notify_fail("��Ļ����ȷ�ˮƽ���ޣ��޷������������ũ�ȷ���\n");

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
        level = (int) me->query_skill("shennong-zhang",1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "staff")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 80)
                return notify_fail("���������������ũ�ȷ���\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("���������������ũ�ȷ���\n");

        me->receive_damage("qi", 65);
        me->add("neili", -85);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shennong-zhang/" + action;
}
