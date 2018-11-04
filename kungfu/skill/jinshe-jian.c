// jinshe-jian.c
// Modify by Rcwiz for heros.cd

#include <ansi.h>
inherit SKILL;

string *parry_msg = ({
        "$n���˷������������죬���е�$v�ݺݿĿ���$N��$w��\n",
	"$n�ؽ����أ���ס��$N��$w��\n",
	"$n���е�$v����ǧ�ٰѣ���ס��ȫ��\n",
	"$n���е�$v�������£�������$N��$w�������Ρ�\n",
});

mapping *action = ({
([	"skill_name": "�����Ӱ",
	"action": "$Nʹһ�С������Ӱ�������е�$w��һ��ָ������$n��$l��������",
	"force" : 190,
	"attack": 95,
	"dodge" : 170,
	"parry" : 90,
	"damage": 155,
	"damage_type": "����"
]),
([	"skill_name": "��Ӱ���",
	"action": "$Nʹһ�С���Ӱ�����������$w�����������$n��$l��������",
	"force" : 220,
	"attack": 122,
	"dodge" : 210,
	"parry" : 120,
	"damage": 177,
	"damage_type": "����"
]),
([	"skill_name": "ѩ�ط���",
	"action": "$N����һת����������Ծ������$w�鶯زԾ��һ�С�ѩ�ط��ߡ�����$n��$l",
	"force" : 180,
	"attack": 56,
        "dodge" : 160,
        "parry" : 70,
	"damage": 105,
	"damage_type": "����"
]),
([	"skill_name": "��������",
	"action": "$N����һת��һ�С��������š������е�$w����������$n��$l���˹�ȥ",
	"force" : 210,
	"attack": 88,
	"dodge" : 180,
	"parry" : 90,
	"damage": 112,
	"damage_type": "����"
]),
([	"skill_name": "���߿���",
	"action": "$N����һ����һ�С����߿��衹��$wЮ���������⣬����޷�����$n��$l",
	"force" : 240,
	"attack": 82,
	"dodge" : 180,
	"parry" : 90,
	"damage": 125,
	"damage_type": "����"
]),
([	"skill_name": "���ߵ���",
	"action": "$N������������񴦣�һ�С����ߵ�������$w���޷����ݵ��ٶ�ֱ��$n��$l",
	"force" : 260,
	"attack": 95,
	"dodge" : 180,
	"parry" : 100,
	"damage": 130,
	"damage_type": "����"
]),
([	"skill_name": "�������",
	"action": "$N����һ����һ�С�������ǡ������е�$w�������ϴ���$n��$l",
	"force" : 300,
	"attack": 102,
	"dodge" : 200,
	"parry" : 120,
	"damage": 165,
	"damage_type": "����"
]),
([	"skill_name": "���߻���",
	"action": "$N����$w���Ⱪ����һ�С����߻���������ǧ����Ы��$n$lҧȥ",
	"force" : 320,
	"attack": 120,
	"dodge" : 220,
	"parry" : 140,
	"damage": 200,
	"damage_type": "����"
]),
});

string query_skill_name(int level)
{
        return action[random(sizeof(action))]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        object weapon;
        int i, ap, dp;

        lvl = me->query_skill("jinshe-jian", 1);

        if (me->query("neili") < 300
           || me->query_skill_mapped("sword") != "jinshe-jian"
           ||! objectp(weapon = me->query_temp("weapon"))
           || weapon->query("skill_type") != "sword")
                     return 0;

        ap = me->query_skill("sword");
        dp = victim->query_skill("dodge");

        me->add("neili", -80);

        switch(random(5))
        {
           case 1:
             break;

           case 2:
             break;

          case 3:
             break;
          
          case 4:
             if (ap / 2 + random(ap) > dp &&
                 ! me->is_busy() &&
                 ! victim->is_busy())
             {
                 message_sort(HIW "\n$N" HIW "����һת������" + weapon->name() + HIW
                              "�������߰���趯�ţ�����$n" HIW "������ơ�\n" NOR); 
                 me->start_busy(1);
                 victim->start_busy(1 + random(lvl / 20));
             }
             break;                        
          
          default :
             if (ap * 3 / 5 + random(ap) > dp && 
                 ! me->is_busy() &&
                 ! me->query_temp("jinshe-jian/lian"))
             {
                weapon = me->query_temp("weapon");
                message_sort(HIY "\n$N" HIY "һ������������" + weapon->name() + HIY 
                             "��ʱ����һ�����ߣ�Ѹ���ޱȵ�Ϯ��$n" HIY "��\n" NOR,
                             me, victim);

                me->add("neili", -180);
              
                me->set_temp("jinshe-jian/lian", 1);
                for (i = 0; i < 9; i++)
                {
                    if (! me->is_fighting(victim))
                            break;
                   
                    if (! victim->is_busy() && random(2) == 1)
                            victim->start_busy(1);

                    COMBAT_D->do_attack(me, victim, weapon, 0);
                }
                me->delete_temp("jinshe-jian/lian");
                
             }
             break;                        
       }
}
int valid_learn(object me)
{

        if (me->query("int") < 33)
                return notify_fail("���������Բ��㣬�޷�������߽�����\n");

        if (me->query("dex") < 33)
                return notify_fail("�����������㣬�޷���ϰ���߽�����\n");

	if ((int)me->query("max_neili") < 4000)
		return notify_fail("���������Ϊ������û�а취�����߽�����\n");

	if ((int)me->query_skill("force", 1) < 200)
		return notify_fail("��Ļ����ڹ���򲻹���û�а취�����߽�����\n");

	if ((int)me->query_skill("dodge", 1) < 240)
		return notify_fail("��Ļ����Ṧ��򲻹���û�а취�����߽�����\n");

	if ((int)me->query_skill("sword", 1) < 220)
		return notify_fail("��Ļ���������򲻹���û�а취�����߽�����\n");

	if ((int)me->query_skill("martial-cognize", 1) < 220)
		return notify_fail("�����ѧ�������㣬û�а취������߽�����\n");

        if (me->query("character") == "�ĺ�����")
                return notify_fail("��һ����ɱ�����ˣ�û�������߽�����\n");

        if (me->query("character") == "���ռ�թ")
                return notify_fail("��һ������ôѧ�ý���ȥ���ˣ����û�������߽�����\n");

        if (me->query("character") == "��������")
                return notify_fail("�����а�����ʲô���߽��������߰���ģ�û�а�����ơ�\n");

	if ((int)me->query_skill("sword", 1) < (int)me->query_skill("jinshe-jian", 1))
		return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������Ľ��߽�����\n");

        return 1;
}

int valid_enable(string usage)
{
	return usage == "sword" || usage == "parry";
}

int practice_skill(object me)
{
	object ob;

	if (! (ob = me->query_temp("weapon")) ||
	    (string)ob->query("skill_type") != "sword")
		return notify_fail("���������һ�ѽ�������������\n");

	if ((int)me->query("qi") < 80)
		return notify_fail("�����������û�а취��ϰ���߽�����\n");

	if ((int)me->query("neili") < 80)
		return notify_fail("�������������û�а취��ϰ���߽�����\n");

	me->receive_damage("qi", 70);
	me->add("neili", -70);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jinshe-jian/" + action;
}

