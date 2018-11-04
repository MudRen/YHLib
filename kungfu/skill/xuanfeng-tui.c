inherit SKILL;

string *dodge_msg = ({
        "$n����΢΢һ�Σ�˫�������߳�����$NӲ�������ˡ�\n",
        "$n����ǰ���������һ̧����$N�Ĺ���ȫ�����أ�ֻ���Ա���\n",
        "$n˫�������أ��͵İεض��𣬶㿪��$N����ʽ��\n",
});

mapping *action = ({
([      "action" : "$N˫����Σ�����͵ط���һʽ��������ӿ�����ż�����$n��$l",
        "force" : 80,
        "attack": 10,
        "dodge" : 45,
        "parry" : 45,
        "damage": 10,
        "lvl"   : 0,
        "damage_type" : "����",
        "skill_name" : "������ӿ"
]),
([      "action" : "$N��ת�����������ߣ�ɲ�Ǽ�����ҽ�һʽ���չ�����������$n",
        "force" : 100,
        "attack": 20,
        "dodge" : 50,
        "parry" : 50,
        "damage": 15,
        "lvl"   : 40,
        "damage_type" : "����",
        "skill_name" : "�չ�����"
]),
([      "action" : "$N�ҽ�ͬʱ�߳���������׼��һʽ����Ԩ���ԡ������е�$n���ؿ�",
        "force" : 160,
        "attack": 30,
        "dodge" : 55,
        "parry" : 55,
        "damage": 18,
        "lvl"   : 80,
        "damage_type" : "����",
        "skill_name" : "��Ԩ����"
]),
([      "action" : "$NͻȻԾ��˫������Ȧת��һʽ�������Ҷ��������糾������$n",
        "force" : 190,
        "attack": 35,
        "dodge" : 60,
        "parry" : 60,
        "damage": 20,
        "lvl"   : 120,
        "damage_type" : "����",
        "skill_name" : "�����Ҷ"
]),
([      "action" : "$N���ֻ��أ�˫�Ž�������һʽ����ɨ���ơ����ŽŲ���$n��Χ",
        "force" : 220,
        "attack": 35,
        "dodge" : 70,
        "parry" : 70,
        "damage": 25,
        "lvl"   : 140,
        "damage_type" : "����",
        "skill_name" : "��ɨ����"
]),
([      "action" : "$NͻȻ�����ҽ����϶���һʽ������׹�ء�����$n������ֱ������",
        "force" : 260,
        "attack": 40,
        "dodge" : 90,
        "parry" : 90,
        "damage": 30,
        "lvl"   : 160,
        "damage_type" : "����",
        "skill_name" : "����׹��"
]),
([      "action" : "$Nʹһʽ��˷�紵ѩ����ȫ��ͻȻ������ת��˫��Ѹ���޼�������$n",
        "force" : 290,
        "attack": 40,
        "dodge" : 100,
        "parry" : 100,
        "damage": 30,
        "lvl"   : 180,
        "damage_type" : "����",
        "skill_name" : "˷�紵ѩ"
]),
([      "action" : "$N����Ծ�𣬿�����������Ȼһʽ���׶����졹��˫�������������$n",
        "force" : 340,
        "attack": 45,
        "dodge" : 115,
        "parry" : 115,
        "damage": 35,
        "lvl"   : 200,
        "damage_type" : "����",
        "skill_name" : "�׶�����"
]),
});

int valid_enable(string usage)
{
	return usage == "unarmed" ||  usage == "parry" ||  usage == "dodge";
}

int valid_combine(string combo)
{
	return combo == "pikong-zhang";
}

int valid_learn(object me)
{
    	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        	return notify_fail("ѧϰ����ɨҶ�ȱ�����֡�\n");

    	if ((int)me->query_skill("force") < 100)
        	return notify_fail("����ڹ���򲻹����޷�ѧ����ɨҶ�ȡ�\n");

    	if ((int)me->query("max_neili") < 800)
        	return notify_fail("�������̫�����޷�������ɨҶ�ȡ�\n");

    	if ((int)me->query_skill("unarmed", 1) < (int)me->query_skill("xuanfeng-tui", 1))
        	return notify_fail("��Ļ���ȭ��ˮƽ���ޣ��޷��������������ɨҶ�ȡ�\n");

        if ((int)me->query_skill("dodge", 1) < (int)me->query_skill("xuanfeng-tui", 1))
                return notify_fail("��Ļ����Ṧˮƽ���ޣ��޷��������������ɨҶ�ȡ�\n");

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
        level = (int)me->query_skill("xuanfeng-tui", 1);
        for(i = sizeof(action); i > 0; i--)
            if(level > action[i-1]["lvl"])
                return action[NewRandom(i, 20, level/5)];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    	if ((int)me->query("qi") < 60)
       		return notify_fail("�������̫���ˡ�\n");

    	if ((int)me->query("neili") < 60)
       		return notify_fail("�����������������ɨҶ�ȡ�\n");

    	me->receive_damage("qi", 45);
    	me->add("neili", -51);
    	return 1;
}

string perform_action_file(string action)
{
    	return __DIR__"xuanfeng-tui/" + action;
}
