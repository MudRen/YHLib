#include <ansi.h>
inherit SHAOLIN_SKILL;

mapping *action = ({
([	"action" : "$Nһ����ȣ����Ƶ�������֮�ϣ�����$n",
	"force" : 210,
        "attack": 22,
	"dodge" : 30,
        "parry" : 31,
	"damage": 15,
	"lvl"   : 0,
	"damage_type" : "����"
]),
([	"action" : "$N��ɫ���أ�˫���ᶶ��Ʈ������������$n",
	"force" : 270,
        "attack": 38,
	"dodge" : 25,
        "parry" : 33,
	"damage": 30,
	"lvl"   : 20,
	"damage_type" : "����"
]),
([	"action" : "$N�������˫�ƻû�һƬ��Ӱ����$n�������ڡ�",
	"force" : 320,
        "attack": 62,
	"dodge" : 43,
        "parry" : 44,
	"damage": 35,
	"lvl"   : 40,
	"damage_type" : "����"
]),
([	"action" : "$N��ǰһ���������й�ֱ������$n��$l��������",
	"force" : 370,
        "attack": 75,
	"dodge" : 55,
        "parry" : 68,
	"damage": 50,
	"lvl"   : 60,
        "damage_type" : "����"
]),
([	"action" : "$N������������˫�ƣ���ʱֻ��һƬ��Ӱ����$n",
	"force" : 420,
        "attack": 82,
	"dodge" : 52,
        "parry" : 80,
	"damage": 30,
	"lvl"   : 80,
	"damage_type" : "����"
]),
([	"action" : "$N˫��ƽ�ӣ��ͻ���$n��$l�����ް�㻨�ɿ���",
	"force" : 460,
        "attack": 103,
	"dodge" : 65,
        "parry" : 101,
	"damage": 50,
	"lvl"   : 100,
        "damage_type" : "����"
]),
([	"action" : "$N���������ŷ���˫���ͷ��ĳ�����ʱһƬ��Ӱ����$n",
	"force" : 510,
        "attack": 128,
	"dodge" : 63,
        "parry" : 125,
	"damage": 80,
	"lvl"   : 120,
	"damage_type" : "����"
]),
([	"action" : "$N������Σ�����Я��ǧ��֮����Ȼ��$n��ͷ������",
	"force" : 530,
        "attack": 125,
	"dodge" : 77,
	"damage": 90,
        "parry" : 152,
	"lvl"   : 140,
        "damage_type" : "����"
]),
([	"action" : "$N������ĺ��ƣ����ֺ�ɨ$n��$l�����ֹ���$n���ؿ�",
	"force" : 580,
        "attack": 131,
	"dodge" : 80,
        "parry" : 115,
	"damage": 100,
	"lvl"   : 160,
        "damage_type" : "����"
]),
([	"action" : "$N��Ȼһ�����ȣ������ŷ���˫��ͬʱ����$n��$l",
	"force" : 620,
        "attack": 132,
	"dodge" : 81,
        "parry" : 123,
	"damage": 130,
	"lvl"   : 180,
        "damage_type" : "����"
])
});

int valid_enable(string usage)
{
	return usage == "parry" || usage == "strike";
}

int double_attack()
{
	return 1;
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ǧ�������Ʊ�����֡�\n");

        if (me->query("str") < 26)
                return notify_fail("�������������㣬�޷�ѧϰ����Ĺ�׾�Ʒ���\n");

        if ((int)me->query_skill("buddhism", 1) < 300)
                return notify_fail("��������ķ��������޷���ǧ�������ơ�\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("����ڹ���򲻹����޷���ǧ�������ơ�\n");

	if ((int)me->query("max_neili") < 3500)
		return notify_fail("���������Ϊ̫ǳ���޷���ǧ�������ơ�\n");

        if ((int)me->query_skill("strike", 1) < 200)
                return notify_fail("��Ļ����Ʒ���򲻹����޷���ǧ�������ơ�\n");

	if ((int)me->query_skill("strike", 1) < (int)me->query_skill("rulai-zhang", 1))
		return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷����������ǧ�������ơ�\n");

	return 1;
}

mixed hit_ob(object me, object victim, int i, int damage_bonus)
{
        if (me->is_busy()
           || random(2) == 0
           || ! living(victim)
           || victim->is_busy()
           || damage_bonus < 150
           || me->query("neili") < 600
           || me->query_temp("action_flag") == 0
           || me->query_skill("buddhism", 1) < 300
           || me->query_skill("rulai-zhang", 1) < 180)
                return 0;

        // ������ʹ��PfmʱѶϢ�ظ�
        if (! me->query_temp("rulai-zhang/hit_msg"))
                message_sort(HIY "\n$N" HIY "��Ȼ�ȵ�����" HIR + RANK_D->query_respect(victim) +
                             HIR "����" + RANK_D->query_self(me) + HIR "һ�ơ�" HIY "��˵����Ʈ"
                             "Ʈ�ĳ�һ�ƣ���ʽ��ΪѰ�������Ƶ���;����Ȼ΢΢ҡ�Σ���ʱһ�Ʊ���"
                             "�ƣ������ֱ����ƣ�������������������$n" HIY "����\n",
                             me, victim);

        me->start_busy(1 + random(3));
        me->add("neili", -200);

        for (i = 0; i < 4; i++)
        {
                if (! me->is_fighting(victim))
                        break;
                COMBAT_D->do_attack(me, victim, 0, 20);
        }

        if (damage_bonus / 6 > victim->query_con())
        {
                me->add("neili", -80);
                victim->receive_wound("qi", (damage_bonus - 120) / 2, me);
                return random(2) ? HIR "$n" HIR "��$N" HIR "�������Ʒ绮�����ţ�ֻ"
                                   "����Ϣ���ͣ����ۡ������һ����Ѫ��\n" NOR:

                                   HIR "$N" HIR "һ���ĳ���ֻ��$n" HIR "��ǰ������"
                                   "���ꡱ�������죬���ƶ��������߹ǣ�\n" NOR;
        }

        return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("rulai-zhang", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 200)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 220)
		return notify_fail("�������������ǧ�������ơ�\n");

	me->receive_damage("qi", 180);
	me->add("neili", -200);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"rulai-zhang/" + action;
}
