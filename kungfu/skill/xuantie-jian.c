// Modify by Rcwiz for hero.cd

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([      "action": "$N���е�$w����������󽭶�ȥ�������Ʋ��ɵ�",
        "force" : 250,
        "attack": 170,
        "dodge" : 30,
        "parry" : 70,
        "damage": 230,
        "lvl"   : 0,
        "damage_type": "����"
]),
([      "action": "$N̤��һ��������$w���һ����������$n��$l",
        "force" : 310,
        "attack": 280,
        "dodge" : 33,
        "parry" : 79,
        "damage": 224,
        "lvl"   : 40,
        "damage_type": "����"
]),
([      "action": "$N����$wһ����һ���̳�������$n��$l��û�а�㻨��",
        "force" : 330,
        "attack": 290,
        "dodge" : 41,
        "parry" : 85,
        "damage": 235,
        "lvl"   : 80,
        "damage_type": "����"
]),
([      "action": "$N����$w΢΢��������Ȼ�̳���һ����������$n��$l",
        "force" : 360,
        "attack": 295,
        "dodge" : 45,
        "parry" : 92,
        "damage": 239,
        "lvl"   : 120,
        "damage_type": "����"
]),
([      "action": "$N���$w����Ȼ��ɨ$n��������磬�����س�",
        "force" : 340,
        "attack": 297,
        "dodge" : 47,
        "parry" : 99,
        "damage": 248,
        "lvl"   : 160,
        "damage_type": "����"
]),
([      "action": "$N���е�$w�������̣��д���һ�������ӹ�$nȫ��",
        "force" : 380,
        "attack": 300,
        "dodge" : 50,
        "parry" : 100,
        "damage": 300,
        "lvl"   : 200,
        "damage_type": "����"
])
});

int valid_enable(string usage)
{
	return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
        if (me->query("int") < 34)
                return notify_fail("�����������̫��޷��������������\n");

        if (me->query("str") < 34)
                return notify_fail("������������������޷�ѧϰ����������\n");

        if (me->query("character") == "�ĺ�����")
                return notify_fail("��һ����ɱ�����ˣ�û��������������ĵ��������塣\n");

        if (me->query("character") == "���ռ�թ")
                return notify_fail("��һ������ôѧ�ý���ȥ���ˣ����û���������������\n");

        if ((int)me->query_skill("force") < 380)
                return notify_fail("����ڹ���򲻵����޷�ѧϰ����������\n");

        if (me->query_skill("martial-cognize", 1) < 220)
                return notify_fail("����ѧ�������㣬�޷���������������\n");

        if (me->query("max_neili") < 5000)
                return notify_fail("�������̫��޷�ѧϰ����������\n");

        if (me->query_skill("force", 1) < me->query_skill("xuantie-jian", 1))
                return notify_fail("��Ļ����ڹ�ˮƽ���ޣ��޷��������������������\n");

        if (me->query_skill("sword", 1) < me->query_skill("xuantie-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷��������������������\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("xuantie-jian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;
        object env;
        
        env = environment(me);
        if (! env->query("can_practice_xiantie-jian"))
                return notify_fail("�����𽣻����˰��죬ֻ���ô˴����ʺ���ϰ����������\n");
       
        if (!objectp(weapon = me->query_temp("weapon")) || 
            (string)weapon->query("skill_type") != "sword" ||
            weapon->query("id") != "xuantie jian")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 80)
                return notify_fail("�����������������������\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("�����������������������\n");

        me->receive_damage("qi", 65);
        me->add("neili", -70);

        message_vision(HIW "\n$N" HIW"������Ϣ�����������е�"+ weapon->name() + HIW "������������࿹��\n\n", me);

        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        object weapon = me->query_temp("weapon");

        lvl = me->query_skill("xuantie-jian", 1);

        if (damage_bonus < 120
           || lvl < 160
           || random(2)
           || me->query("neili") < 500
           || me->query_skill_mapped("sword") != "xuantie-jian" )
      		return damage_bonus / 4;

        if (lvl / 2 + random(lvl) > victim->query_skill("parry", 1))
        {
                me->add("neili", -120);
                victim->receive_wound("qi", damage_bonus * 4 / 5, me);
      
                return HIW "$N" HIW "����" + weapon->name() + HIW "����������������£�����"
                       "�ɵ�������$n" HIW "�����ƻֺ�֮����\n" NOR;
         }
}

int difficult_level()
{
        return 500;
}

string perform_action_file(string action)
{
        return __DIR__"xuantie-jian/" + action;
}
