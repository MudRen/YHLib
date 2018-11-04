#include <ansi.h>
#include <skill.h>

inherit SKILL;

string *xue_name = ({ 
"�͹�Ѩ", "����Ѩ", "����Ѩ", "��ԪѨ", "����Ѩ", "�м�Ѩ", "�н�Ѩ", "��ͻѨ", "�ٻ�Ѩ",
"����Ѩ", "����Ѩ", "���Ѩ", "�Ϲ�Ѩ", "��ԨѨ", "�쾮Ѩ", "��ȪѨ", "����Ѩ", "����Ѩ", }); 

mapping *action_unarmed = ({
([      "action": "$Nʹһ�С�������������˫����Ȼ�����������б�������ء���һ����һ���������һ�����$n��$l",
        "force" : 350,
        "attack": 80,
        "dodge" : 75,
        "parry" : 55,
        "damage": 70,
        "lvl" : 0,
        "weapon" : HIW "���ν���" NOR,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action": "$Nʹ��һ�С���������������ָ����һ�̣�����������ֱ����������ʱ���ɽ����������㿳��$n",
        "force" : 370,
        "attack": 81,
        "dodge" : 65,
        "parry" : 65,
        "damage": 72,
        "lvl" : 40,
        "weapon" : HIW "���ν���" NOR,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action": "$Nһ�����ȣ���Ȼһ�С������������������$n���һ������ʱһ�ɾ����������ƿ�֮��Ϯ��$p$l",
        "force" : 410,
        "attack": 85,
        "dodge" : 55,
        "parry" : 55,
        "damage": 88,
        "lvl" : 80,
        "weapon" : HIW "���ν���" NOR,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action": "$N˫���ͷ��ĳ��������ݺᣬ����һʽ�����̾�ɲ����ɲʱ���쬡��ƿ�����Ȼ���죬����$n$l",
        "force" : 430,
        "attack": 79,
        "dodge" : 65,
        "parry" : 35,
        "damage": 83,
        "lvl" : 120,
        "weapon" : HIW "�������ν���" NOR,
        "skill_name" : "���̾�ɲ",
        "damage_type" : "����"
]),
([      "action": "$Nƾ��һָ��һ�С��������项ббϮ�������ƶ�Ȼ����������²�������â����$n��$l",
        "force" : 460,
        "attack": 75,
        "dodge" : 91,
        "parry" : 85,
        "damage": 78,
        "lvl" : 160,
        "weapon" : HIW "�������ν���" NOR,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action": "$N˫������һ�֣�ʹһ�С��������ơ�����������Ū���������һ�����彣����ֱӿ$n$l��ȥ",
        "force" : 490,
        "attack": 105,
        "dodge" : 35,
        "parry" : 24,
        "damage": 98,
        "lvl" : 200,
        "weapon" : HIW "�������ν���" NOR,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action": "$N��Ȼ���о������䣬һ�С��Ǻ�������ʹ������ʱ���ɴ����ޱȵĽ�����ָ�⼤�������ֱ��$n",
        "force" : 480,
        "attack": 95,
        "dodge" : 75,
        "parry" : 75,
        "damage": 93,
        "lvl" : 240,
        "weapon" : HIW "�������ν���" NOR,
        "skill_name" : "�Ǻ�����",
        "damage_type" : "����"
]),
});


mapping *action_sword = ({
([      "action": "$Nʹһ�С�����������������$w����һ�����������һ�����$n��$l",
        "force" : 140,
        "attack": 60,
        "dodge" : 15,
        "parry" : 25,
        "damage" : 50,
        "lvl" : 0,
        "damage_type" : "����",
]),
([      "action": "$N��ָ��$w��һ����һ�С����������������������ʱ����һ����������Х��ն��$n��$l",
        "force" : 150,
        "attack": 80,
        "dodge" : 60,
        "parry" : 5,
        "damage" : 70,
        "lvl" : 40,
        "damage_type" : "����",
]),
([      "action": "$Nһ�С����������������$w��â��ʱ�������ߣ��⻪���䣬ֱֱ����$n��$l",
        "force" : 200,
        "attack": 80,
        "dodge" : 0,
        "parry" : 10,
        "damage" : 90,
        "lvl" : 80,
        "damage_type" : "����",
]),
([      "action": "$N����$wһʽ�����̾�ɲ����׼$n��$lһ���̳�������ɲʱ�����ݺᣬ�Ʋ��ɵ�",
        "force" : 250,
        "attack": 80,
        "dodge" : 10,
        "parry" : 15,
        "damage" : 92,
        "lvl" : 120,
        "damage_type" : "����",
]),
([      "action": "$N��$wƾ��һָ��һ�С��������项ֱֱ�̳������ⶸȻ����������²�������â����$n��$l",
        "force" : 225,
        "attack": 63,
        "dodge" : 5,
        "parry" : 5,
        "damage" : 103,
        "lvl" : 160,
        "damage_type" : "����",
]),
([      "action": "$N����$w����һ�֣�ʹһ�С��������ơ��������ڽ������ᵯ������ʱһ�ɽ���ֱӿ$n$l��ȥ",
        "force" : 250,
        "attack": 80,
        "dodge" : 10,
        "parry" : 5,
        "damage" : 120,
        "lvl" : 200,
        "damage_type" : "����",
]),
([      "action": "$N��Ȼ���о������䣬һ�С��Ǻ���������һ�ɴ����ޱȵĽ�����$w�ϼ��������ֱ��$n",
        "force" : 300,
        "attack": 100,
        "dodge" : -15,
        "parry" : -15,
        "damage" : 140,
        "lvl" : 240,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) 
{  
        return usage == "unarmed"
            || usage == "parry"
            || usage == "sword"
            || usage == "tanqin-jifa"; 
}

int valid_learn(object me)
{
        if ((int)me->query_skill("force") < 270)
                return notify_fail("����ڹ���򲻹����޷������������ν���\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("�������̫�����޷������������ν���\n");

        if ((int)me->query_skill("unarmed", 1) < 180)
                return notify_fail("��Ļ���ȭ�Ż�򲻹����޷������������ν���\n");

        if ((int)me->query_skill("sword", 1) < 180)
                return notify_fail("��Ļ���������򲻹����޷������������ν���\n");

        if ((int)me->query_skill("tanqin-jifa", 1) < 100)
                return notify_fail("���ټ���ˮƽ���ޣ��޷������������ν���\n");

        if ((int)me->query_skill("force", 1) < (int)me->query_skill("qixian-wuxingjian", 1))
                return notify_fail("����ڹ���Ϊ���ޣ��޷�����������������ν���\n");

        if ((int)me->query_skill("unarmed", 1) < (int)me->query_skill("qixian-wuxingjian", 1))
                return notify_fail("��Ļ���ȭ��ˮƽ���ޣ��޷�����������������ν���\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("qixian-wuxingjian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷�����������������ν���\n");

        if ((int)me->query_skill("tanqin-jifa", 1) < (int)me->query_skill("qixian-wuxingjian", 1) / 2)
                return notify_fail("�����ѧ���˽ⲻ�����룬�޷�����������������ν���\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action_unarmed)-1; i >= 0; i--)
                if(level >= action_unarmed[i]["lvl"])
                        return action_unarmed[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("qixian-wuxingjian", 1);

        if ( ! weapon)
        {                
             for(i = sizeof(action_unarmed); i > 0; i--)
                     if(level >= action_unarmed[i-1]["lvl"])
                             return action_unarmed[NewRandom(i, 20, level/5)];
        }        
        else
             for(i = sizeof(action_sword); i > 0; i--)
                     if(level > action_sword[i-1]["lvl"])
                             return action_sword[NewRandom(i, 20, level/5)];        
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("��������������������ν���\n");

        if ((int)me->query("neili") < 120)
                return notify_fail("��������������������ν���\n");

        me->receive_damage("qi", 60);
        me->add("neili", -100);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        string name, weapon;
        name = xue_name[random(sizeof(xue_name))];
    
        if (me->query_skill("qixian-wuxingjian", 1) < 180
           || me->query("max_neili") < 2500
           || me->query("neili") < 500
           || me->query("max_neili") < victim->query("max_neili")
           || victim->query("max_neili") < 10)
                return 0;

        if (victim->is_busy())
                return 0;

        if (damage_bonus < 150)
                return 0;

        victim->start_busy(1);
        me->add("neili", -100);
        victim->receive_damage("qi", me->query_skill("qixian-wuxingjian", 1) / 5 + damage_bonus / 3);
        victim->receive_wound("qi", me->query_skill("qixian-wuxingjian", 1) / 8 + damage_bonus / 5);
                return HIW "ֻ��һ�󴾺��������$N" HIW "��������$n" HIY "��" + name + "��"
                       NOR + HIW "��ʱ��������������ȫ�������Ҵܲ�ֹ��\n" NOR;
}

void do_effect(object me)
{
        object *obs;
        int lvl;
        int i;
        int damage;

        lvl = me->query_skill("tanqin-jifa", 1) / 2 +
              me->query_skill("qixian-wuxingjian", 1);

        if (environment(me)->query("no_fight")
           || environment(me)->query("skybook")
           || lvl < 150)
                return;

        lvl = lvl / 5 + me->query_skill("force");
        lvl /= 2;

        obs = all_inventory(environment(me));
        for (i = 0; i < sizeof(obs); i++)
        {
                if (! obs[i]->is_character() || obs[i] == me || ! living(obs[i]))
                        continue;

                if (me->query_skill("qixian-wuxingjian") * 2 / 3 <
                    obs[i]->query_skill("qixian-wuxingjian"))
                        continue;

                // ��������������Ҳ����˺�
                if ((int)obs[i]->query_condition("die_guard"))
                        continue;

                if (obs[i]->query("max_neili") < 10)
                {
                        tell_object(obs[i], HIM "������ֻ������������ƽƽ������û�������֮����\n" NOR);
                        continue;
                }

                if (obs[i]->query("max_neili") + 500 > me->query("max_neili"))
                {
                        tell_object(obs[i], HIM "������ֻ����ͷһ���������Լ��������˿������Ӱ�졣\n" NOR);
                        continue;
                }

                if (lvl + random(lvl) < obs[i]->query_skill("force"))
                {
                        tell_object(obs[i], HIM "���������в���΢΢һ�����������������а���֮����\n" NOR);
                        continue;
                }

                damage = me->query("max_neili") - obs[i]->query("max_neili");
                if (damage < 500)
                {
                        tell_object(obs[i], HIM "���Ȼ����һ�����ң���æ����һ�����������ѹ�����\n" NOR);
                        continue;
                }

                damage /= 10;
                me->want_kill(obs[i]);
                me->fight_ob(obs[i]);
                obs[i]->kill_ob(me);
                obs[i]->receive_damage("jing", damage / 2, me);
                obs[i]->receive_wound("jing", damage / 2, me);
                obs[i]->receive_damage("qi", damage * 2, me);
                obs[i]->receive_wound("qi", damage * 2, me);
                
                tell_object(obs[i], HIR "���������񲻶���ֻ�к�����������Ĥ������Ŀ����������ε���\n" NOR);
        }
}

string perform_action_file(string action)
{
      return __DIR__"qixian-wuxingjian/" + action;
}
