#include <ansi.h>
#include <skill.h>

inherit SKILL;

string *xue_name = ({ 
"�͹�Ѩ", "����Ѩ", "����Ѩ", "��ԪѨ", "����Ѩ", "�м�Ѩ", "�н�Ѩ", "��ͻѨ", "�ٻ�Ѩ",
"����Ѩ", "����Ѩ", "���Ѩ", "�Ϲ�Ѩ", "��ԨѨ", "�쾮Ѩ", "��ȪѨ", "����Ѩ", "����Ѩ", }); 

mapping *action_finger = ({
([      "action" : "$N����ʳָ΢�㣬���С������������һ���ۻ��һ��ָ������$n�����ֳ��ȣ���������",
        "force" : 350,
        "attack": 80,
        "dodge" : 75,
        "parry" : 55,
        "damage": 70,
        "lvl" : 0,
        "weapon" : HIR "һ��ָ��" NOR,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$Nһָ���ճ�ϼ�⡹��������һ�����ӿ��$n���������´�ƽ�ͣ�����Ȼ����޿��뿹",
        "force" : 370,
        "attack": 81,
        "dodge" : 65,
        "parry" : 65,
        "damage": 72,
        "lvl" : 20,
        "weapon" : HIR "һ��ָ��" NOR,
        "skill_name" : "�ճ�ϼ��",
        "damage_type" : "����"
]),
([      "action" : "�����������죬һ����͵�������$N��ָӿ��������һ�С�����ů�ڡ�����������$n$l",
        "force" : 410,
        "attack": 85,
        "dodge" : 55,
        "parry" : 55,
        "damage": 88,
        "lvl" : 40,
        "weapon" : HIR "һ��ָ��" NOR,
        "skill_name" : "����ů��",
        "damage_type" : "����"
]),
([      "action": "$Nһ���絽$n������������Ծ�أ�һʽ��³�����ա�������ʳָ������ָ��$n��$l",
        "force" : 430,
        "attack": 79,
        "dodge" : 65,
        "parry" : 35,
        "damage": 83,
        "lvl" : 60,
        "weapon" : HIR "һ��ָ��" NOR,
        "skill_name" : "³������",
        "damage_type" : "����"
]),
([      "action": "$N�����������ʳָЮ���ۻ���������$n��$l����ʽ����̹��������һʽ��������ѩ��",
        "force" : 460,
        "attack": 75,
        "dodge" : 91,
        "parry" : 85,
        "damage": 78,
        "lvl" : 80,
        "weapon" : HIR "һ��ָ��" NOR,
        "skill_name" : "������ѩ",
        "damage_type" : "����"
]),
([      "action": "$N��ӰƮ��һʽ���������졹���������϶���������������Ȼ������$n��$l",
        "force" : 490,
        "attack": 105,
        "dodge" : 35,
        "parry" : 24,
        "damage": 98,
        "lvl" : 100,
        "weapon" : HIR "һ��ָ��" NOR,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N̤ǰһ������ָ�������һ�㣬$nֻ����Ϣһ�����ѱ������ս������ĸ�����������$l",
        "force" : 480,
        "attack": 95,
        "dodge" : 75,
        "parry" : 75,
        "damage": 93,
        "lvl" : 120,
        "weapon" : HIR "һ��ָ��" NOR,
        "skill_name" : "���ս���",
        "damage_type" : "����"
]),
([      "action" : "$N������ڣ������������׻ӳ���ӿ��$n��$l���������������һ�С�������ů��",
        "force" : 512,
        "attack": 105,
        "dodge" : 85,
        "parry" : 85,
        "damage": 97,
        "lvl" : 140,
        "weapon" : HIR "һ��ָ��" NOR,
        "skill_name" : "������ů",
        "damage_type" : "����"
]),
([      "action" : "$N���΢Ц�������ʳָ����������$n�ؿڣ����С�ĺ��ӳ�ա�����������ȴ��˿���ƿ�֮��",
        "force" : 540,
        "attack": 113,
        "dodge" : 38,
        "parry" : 38,
        "damage": 89,
        "lvl" : 160,
        "weapon" : HIR "һ��ָ��" NOR,
        "skill_name" : "ĺ��ӳ��",
        "damage_type" : "����"
]),
([      "action": "$N����б����ͻȻ�����Ϊָ���͵�һ���죬һʽ�����ﳯ������ʹ��һ��ָ��������$n��$l",
        "force" : 528,
        "attack": 119,
        "dodge" : 24,
        "parry" : 23,
        "damage": 98,
        "lvl" : 180,
        "weapon" : HIR "һ��ָ��" NOR,
        "skill_name" : "���ﳯ��",
        "damage_type" : "����"
]),
([      "action" : "ֻ��$Nʳָ΢����һָ������Ǭ�������������ɭ�ϣ�Ӻ�����£�������֮�в������߷��",
        "force" : 569,
        "attack": 97,
        "dodge" : 42,
        "parry" : 42,
        "damage": 117,
        "lvl" : 200,
        "weapon" : HIR "һ��ָ��" NOR,
        "skill_name" : "����Ǭ��",
        "damage_type" : "����"
]),
([      "action" : "$Nͷ�������뵣����۽�Ũ����������һ�㣬ʳָ�����һʽ��������̩������$n$l",
        "force" : 540,
        "attack": 135,
        "dodge" : 75,
        "parry" : 91,
        "damage": 138,
        "lvl" : 220,
        "weapon" : HIR "һ��ָ��" NOR,
        "skill_name" : "������̩",
        "damage_type" : "����"
])
});


mapping *action_staff = ({
([      "action" : "$N�����Ц����$wƽ�أ���׼ʱ��һ�Ȼӳ����������������Ѹ���ޱȵ�ֱ��$n$l",
        "force" : 100,
        "dodge" : 15,
        "damage" : 50,
        "lvl" : 0,
        "damage_type" : "����",
]),
([      "action" : "$N��������Ⱦ������󴫶�����һ��ָ�񹦻���$w֮�ϣ��������أ�ƽƽ�����ش���$n",
        "force" : 150,
        "dodge" : -10,
        "damage" : 70,
        "lvl" : 20,
        "damage_type" : "����",
]),
([      "action" : "ֻ��$N��Ϣ���񣬽Ų����ţ����ߵ��ƣ�һʽ����������$n$l����ʽ��������",
        "force" : 200,
        "dodge" : 0,
        "damage" : 90,
        "lvl" : 40,
        "damage_type" : "����",
]),
([      "action" : "$N���²���΢�䣬�������ߣ��������أ���Ʈ�ݵ�һ����$n������������ȴҲ��ʧ��������",
        "force" : 250,
        "dodge" : 10,
        "damage" : 120,
        "lvl" : 60,
        "damage_type" : "����",
]),
([      "action" : "$Nƽ��һ�ȣ����е�$w���ƽ������أ�ʹ��ʱ�Ա���ǰ��ɬ����ʵ�Ǿ������أ�����֮��",
        "force" : 300,
        "dodge" : -15,
        "damage" : 140,
        "lvl" : 80,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) 
{  
	return usage == "finger" || usage == "parry" || usage == "staff"; 
}

int valid_learn(object me)
{
	if ((string)me->query("gender") != "����") 
        	return notify_fail("һ��ָ���Ǵ�������������ο�����ϰ��\n");

        if ((int)me->query("str") < 34)
                return notify_fail("������������������޷����һ��ָ��\n");

        if ((int)me->query("dex") < 30)
                return notify_fail("����������������޷�����һ��ָ��\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��һ��ָ������֡�\n");

        if ((int)me->query_skill("force") < 240)
                return notify_fail("����ڹ���򲻹����޷�ѧһ��ָ��\n");

        if ((int)me->query("max_neili") < 2000)
                return notify_fail("�������̫�����޷���һ��ָ��\n");

        if ((int)me->query_skill("finger", 1) < 150)
                return notify_fail("��Ļ���ָ����򲻹����޷�ѧһ��ָ��\n");

        if ((int)me->query_skill("finger", 1) < (int)me->query_skill("sun-finger", 1))
                return notify_fail("��Ļ���ָ��ˮƽ���ޣ��޷����������һ��ָ��\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action_finger)-1; i >= 0; i--)
                if(level >= action_finger[i]["lvl"])
                        return action_finger[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("sun-finger", 1);

        if ( ! weapon)
        {                
             for(i = sizeof(action_finger); i > 0; i--)
                     if(level >= action_finger[i-1]["lvl"])
                             return action_finger[NewRandom(i, 20, level/5)];
        }        
        else
             for(i = sizeof(action_staff); i > 0; i--)
                     if(level > action_staff[i-1]["lvl"])
                             return action_staff[NewRandom(i, 20, level/5)];        
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 120)
                return notify_fail("�������������һ��ָ!\n");

        me->receive_damage("qi", 60);
        me->add("neili", -100);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
      	string name, weapon;
      	name = xue_name[random(sizeof(xue_name))];

      	if (victim->is_busy())
            	return 0;

      	if (damage_bonus < 150)
            	return 0;

      	if (! objectp(weapon = me->query_temp("weapon")))
      	{
            	if ((me->query("neili") > 300)
               	   && me->query_skill("sun-finger", 1) > 100
               	   && ! victim->is_busy())
            	{
	          	victim->start_busy(2);
                  	me->add("neili", -50);
                  	victim->receive_wound("qi", (damage_bonus - 100) / 3, me);

			if (victim->query("neili") <= (damage_bonus / 4 + 50))
	                	victim->set("neili", 0);
                  	else
                        	victim->add("neili", -damage_bonus / 4);

		              	return HIR "ֻ�����͡���һ����$n" HIR "��$N" HIR "���һָ����" NOR +
                                       HIY + name + NOR + HIR "���������ɵ�һ�͡�\n" NOR;
            	} 
      	} else
      	{
            	if ((me->query("neili") > 300)
                   && me->query_skill("sun-finger", 1) > 100
                   && ! victim->is_busy())
	    	{
	        	victim->start_busy(2);
                	me->add("neili", -50);
                  	victim->receive_wound("qi", (damage_bonus - 120) / 3, me);

	                return HIR "ֻ�����͡���һ����$n" HIR "��$N" HIR "�ȶ˷�������������" NOR +
                               HIY + name + NOR +HIR "���������ɵ�һ�͡�\n" NOR;
            	}   
      	}
 
}

string perform_action_file(string action)
{
      	return __DIR__"sun-finger/" + action;
}