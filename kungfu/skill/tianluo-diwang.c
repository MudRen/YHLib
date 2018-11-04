#include <ansi.h>;

inherit SKILL;

mapping *action = ({
([      "action" : "$N���ƻ�һ��Բ�����ƻ�����һ��Բ���ʺ�£֮�ƣ�����$n����ǰ��Ѩ",
        "force"  : 160,
        "attack" : 10,
        "parry"  : 10,
        "dodge"  : 10,
        "damage" : 10,
        "lvl"    : 0,
        "damage_type" : "����",
]),
([      "action" : "$N���ƻ��أ���ȭ�����󷢣�����һ��������������$n��$l",
        "force"  : 195,
        "attack" : 20,
        "parry"  : 25,
        "dodge"  : 15,
        "damage" : 15,
        "damage_type" : "����",
        "lvl"    : 30,
]),
([      "action" : "$N������ǰ��ȥ��һ�¼��弲�����������۽���δ��֮�ʣ�˫�ֱ���$n��$l",
        "force"  : 230,
        "attack" : 30,
        "parry"  : 30,
        "dodge"  : 20,
        "damage" : 32,
        "lvl"    : 60,
        "damage_type" : "����"
]),
([      "action" : "$N�������»��أ�����ͻȻһ�䣬��Ȼ��Ϊ�������꣬����$n",
        "force"  : 260,
        "attack" : 40,
        "parry"  : 40,
        "dodge"  : 20,
        "damage" : 40,
        "damage_type" : "����",
        "lvl"    : 90,     
]),
([      "action" : "$N����Ӵ�����������˳���$nֻ�����ܲ�͸�磬��������ӡ����ôҲ���㲻��",
        "force"  : 270,
        "attack" : 50,
        "parry"  : 55,
        "dodge"  : 35, 
        "damage" : 65,
        "lvl"    : 120,        
        "damage_type" : "����"
]),
([      "action" : "$N˫�۷��裬��ֻ�������ƻ�����ǧ��ǧ�ƣ���$n���Ծ�����㣬ʼ�շɲ���"
                   "ֻ����Χ����ȦȦ", 
        "force"  : 300,
        "attack" : 65,
        "parry"  : 70,
        "dodge"  : 40,
        "damage" : 80,
        "lvl"    : 150,
        "damage_type" : "����"
]), 
});

int valid_enable(string usage) 
{ 
        int lvl;
        lvl = (int)this_player()->query_skill("tianluo-diwang", 1);
        
        if (lvl > 30)
               return usage == "strike" || usage == "parry";
        else
               return  usage == "strike";
}

int valid_combine(string combo)
{ 
        return combo == "meinv-quan"; 
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������ַ�����ϰ���޵����ơ�\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("����ڹ������������޷���ϰ���޵����ơ�\n");

        if ((int)me->query_skill("strike", 1) < 40)
                return notify_fail("��Ļ����Ʒ�ˮƽ̫�ͣ��޷���ϰ���޵����ơ�\n");

        if ((int)me->query_skill("strike", 1) < me->query_skill("tianluo-diwang", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽˮƽ���ޣ��޷���ϰ����������޵����ơ�\n");

        return 1;
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp;

        if ((int)me->query_skill("tianluo-diwang", 1) < 100 ||
            ! living(me) || me->query_temp("weapon"))
                return;

        mp = ob->query_skill("count", 1);
        ap = ob->query_skill("force") + mp;
        dp = me->query_skill("parry", 1) / 2 +
             me->query_skill("tianluo-diwang", 1);

        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage": -damage ]);

                switch (random(2))
                {
                case 0:                                             
                                            
                        result += (["msg" : HIC "$n" HIC "˫�۷��裬����ǧ���ĳ�����"
                                            HIC "��͸�磬����$N" HIC "�Ĺ��ƻ��⡣\n" NOR]);
                        break;

                default:
                        result += (["msg" : HIC "$n" HIC "����ͻȻһ�䣬��Ȼ��Ϊ�������꣬"
                                            HIC "������ǰ��$N" HIC "���޴ӹ�����\n" NOR]);
                        break;
                }
                return result;
        } else
        if (mp >= 80)
        {
                switch (random(2))
                {
                case 0:
                        result = HIY "$n" HIY "˫�۷��裬����ǧ���ĳ����ܲ�͸�磬"
                                 HIY "Ȼ��$N" HIY "��֮���������У���Ϯ$n" 
                                 HIY "��\n" NOR;
                        break;

                default:
                        result = HIY "$n" HIY "����ͻȻһ�䣬��Ȼ��Ϊ�������꣬"
                                 HIY "������ǰ������$N" HIY "ȴ��͸������ʵ����"
                                 HIY "ֱ����$n\n" NOR;
                        break;
                }
                COMBAT_D->set_bhinfo(result);
        }
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        if (me->query_temp("weapon"))
                return 0;

        lvl = me->query_skill("tianluo-diwang", 1);
        if (lvl < 60)  return 0;
        if (lvl < 160) return 40;
        if (lvl < 240) return 60;
        if (lvl < 320) return 80;
        return 100;
}

mapping query_action(object me, object weapon)
{
        int i, level;

        level = (int)me->query_skill("tianluo-diwang", 1);

        for (i = sizeof(action); i > 0; i--)
                if (level > action[i - 1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("������������ˡ�\n");

        me->receive_damage("qi", 50);
        me->add("neili", -35);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tianluo-diwang/" + action;
}
