inherit SKILL;

mapping *action = ({
([      "action":"$Nʹһʽ����ʽ�ֽ𡹣�����$w�������Һ�ɨ����$n��$l",
        "force" : 126,
        "parry" : 3,
        "dodge" : 5,
        "damage": 21,
        "lvl"   : 0,
        "skill_name" : "��ʽ�ֽ�",
        "damage_type":  "����"
]),
([      "action":"$N̤��һ������������ء�������$w���������һ���������$n��$l",
        "force" : 149,
        "parry" : 13,
        "dodge" : 10,
        "damage": 25,
        "lvl"   : 30,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([      "action":"$N����$wһ����һ�С���Ʒ��̨����бб�����ó�������$n��$l",
        "force" : 167,
        "parry" : 12,
        "dodge" : 15,
        "damage": 31,
        "lvl"   : 50,
        "skill_name" : "��Ʒ��̨",
        "damage_type":  "����"
]),
([      "action":"$N����$w����������Ȧ��һʽ�����Ტ�á���һ�������$n��$l",
        "force" : 187,
        "parry" : 23,
        "dodge" : 19,
        "damage": 45,
        "lvl"   : 70,
        "skill_name" : "���Ტ��",
        "damage_type":  "����"
]),
([      "action":"$N����$wбָ���죬һʽ�������޻�������׼$n��$lбб����",
        "force" : 197,
        "parry" : 31,
        "dodge" : 27,
        "damage": 56,
        "lvl"   : 90,
        "skill_name" : "�����޻�",
        "damage_type":  "����"
]),
([      "action":"$Nһʽ�����ۡ���$w��ն�������缲�������$n���ؿ�",
        "force" : 218,
        "parry" : 49,
        "dodge" : 35,
        "damage": 63,
        "lvl"   : 110,
        "skill_name" : "����",
        "damage_type":  "����"
]),
([      "action":"$N����$wһ����һʽ����Ӱ���桹��������Ϣ�ػ���$n��$l",
        "force" : 239,
        "parry" : 52,
        "dodge" : 45,
        "damage": 72,
        "lvl"   : 130,
        "skill_name" : "��Ӱ����",
        "damage_type":  "����"
]),
([      "action":"$N����$wбָ���죬��â���£�һʽ����������������׼$n��$lбб����",
        "force" : 287,
        "parry" : 55,
        "dodge" : 51,
        "damage": 88,
        "lvl"   : 150,
        "skill_name" : "��������",
        "damage_type":  "����"
]),
([      "action":"$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ����ˮ���项����$n���ʺ�",
        "force" : 342,
        "parry" : 63,
        "dodge" : 55,
        "damage": 105,
        "lvl"   : 170,
        "skill_name" : "��ˮ����",
        "damage_type":  "����"
]),
([      "action":"$N���Ƶ�����һʽ�����⽣Ӱ����$w�Ի���Ծ�����缲�������$n���ؿ�",
        "force" : 381,
        "parry" : 76,
        "dodge" : 65,
        "damage": 122,
        "lvl"   : 190,
        "skill_name" : "���⽣Ӱ",
        "damage_type":  "����"
])
});

int valid_enable(string usage)
{ 
       return usage == "sword" || usage == "parry" || usage == "blade";
}

int valid_learn(object me)
{
        object weapon;
        int lv = me->query_skill("yinyang-ren", 1);

        if (! objectp(weapon = me->query_temp("weapon"))
           || ((string)weapon->query("skill_type") != "sword"
           && (string)weapon->query("skill_type") != "blade"))
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if (me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻹�������ѧϰ�����з���\n");

        if (me->query("max_neili") < 1800)
                return notify_fail("���������Ϊ����������ѧϰ�����з���\n");

        if (me->query_skill("sword", 1) < 100)
                return notify_fail("��Ļ���������򲻹�������ѧϰ�����з���\n");

        if (me->query_skill("blade", 1) < 100)
                return notify_fail("��Ļ���������򲻹�������ѧϰ�����з���\n");

        // 180 ��֮ǰ�� sword �� blade ���ֻ�����������
        if (lv <= 180 && (int)me->query_skill("sword", 1) < lv)
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������������з���\n");

        if (lv <= 180 && (int)me->query_skill("blade", 1) < lv)
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������������з���\n");

        if ((int)me->query_skill("sword", 1) < lv
           && (int)me->query_skill("blade", 1) < lv)
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������������з���\n");

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
        level = (int) me->query_skill("yinyang-ren", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
           || ((string)weapon->query("skill_type") != "sword"
           && (string)weapon->query("skill_type") != "blade"))
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 100)
                return notify_fail("������������������з���\n");

        if ((int)me->query("neili") < 130)
                return notify_fail("������������������з���\n");

        me->receive_damage("qi", 80);
        me->add("neili", -100);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yinyang-ren/" + action;
}