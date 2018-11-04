inherit SKILL;

string *dodge_msg = ({
        "$n��������һ�ڣ�һ�С�����鳲�����㿪��$N�Ĺ�����\n",
        "$nһ�С����ѵ�ˮ��������΢΢һ����������������ߡ�\n",
        "����$nһ�С�ƽ�����ơ���˫���أ�ƮȻ����ʹ$N������ա�\n",
        "$nһ�С�ѩ���Ϲ项�����������ƿ������㿪�˹�����\n",
        "$nʹ��һ�С����䳤�ա�����������һ���������ƿ���$N������\n",
});

mapping *action = ({
([      "action":"$Nһ�С�����鳲��������$w�����ѵ�ˮ�㣬������$n��$l��ȥ",
        "force" : 120,
        "attack": 25,
        "dodge" : 75,
        "parry" : 82,
        "damage": 10,
        "lvl"   : 0,
        "skill_name" : "����鳲",
        "damage_type":"����"
]),
([      "action":"$N��$wƽ���ؿڣ�һš��һ�С����ѵ�ˮ����$w�͵�����$n��$l",
        "force" : 150,
        "attack": 37,
        "dodge" : 73,
        "parry" : 81,
        "damage": 15,
        "lvl"   : 40,
        "skill_name" : "���ѵ�ˮ",
        "damage_type":"����"
]),
([      "action":"$Nһ�С�ѩ���Ϲ项��ȫ���������ڵ��ϴ����ת��$w��$n��$l���ȥ",
        "force" : 180,
        "attack": 42,
        "dodge" : 65,
        "parry" : 87,
        "damage": 20,
        "lvl"   : 80,
        "skill_name" : "ѩ���Ϲ�",
        "damage_type":"����"
]),
([      "action":"$N����һ��������һ�С�ƽ�����ơ���$wЮ��������Ѹ��ɨ��$n������",
        "force" : 210,
        "attack": 43,
        "dodge" : 68,
        "parry" : 85,
        "damage": 25,
        "lvl"   : 100,
        "skill_name" : "ƽ������",
        "damage_type":"����"
]),
([      "action":"$Nһ�С����䳤�ա��������һ�����˱Ƴ�һ��ֱ�ߣ����ǰ�����$n��$l",
        "force" : 240,
        "attack": 49,
        "dodge" : 73,
        "parry" : 91,
        "damage": 30,
        "lvl"   : 120,
        "skill_name" : "���䳤��",
        "damage_type":"����"
]),
});

int valid_enable(string usage) { return usage == "club" || usage == "parry" || usage == "dodge"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 250)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 50)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("dodge", 1) < (int)me->query_skill("caiyan-gong", 1))
                return notify_fail("��Ļ����Ṧˮƽ���ޣ��޷���������Ĳ��๦��\n");

        if ((int)me->query_skill("club", 1) < (int)me->query_skill("caiyan-gong", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������Ĳ��๦��\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("caiyan-gong", 1);
        for(i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "club")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("����������������๦��\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("����������������๦��\n");

        me->receive_damage("qi", 62);
        me->add("neili", -61);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"caiyan-gong/" + action;
}
