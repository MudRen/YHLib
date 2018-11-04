#include <ansi.h> 
inherit FORCE;

string *dodge_msg = ({
        "$n����̫�������ŷ�������$n�����ĳ������絽������$N��һ�ߡ�\n",
        "$n�ֱۻ�ת��ץס$N����һ�ƣ���$NԶԶ������\n",
        "$nĬ��̫���ھ���������ţ���Ծ��������������ʮ�����⡣\n",
        "$Nֻ����ǰһ����ֻ����$n����һ�ϣ��Լ���������ȻĪ�����������ˡ�\n",
});

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("taixuan-gong", 1);
          return lvl * lvl * 20 * 15 / 100 / 200;
}

mapping *actionf = ({
([      "action":"$N˫��һ�٣�һ�ɾ���������ӿ�������Ƶ�$n���Ժ���",
        "force" : 540,
        "attack": 220,
        "dodge" : 120,
        "parry" : 120,
        "damage": 155,
        "damage_type":  "����"
]),
([      "action":"$N�����������ʱһ�������������Ϯ��$n",    
        "force" : 560,
        "attack": 240,
        "dodge" : 60,
        "parry" : 90,
        "damage": 230,
        "damage_type":  "����"
]),
([      "action":"$N���һ��������һ������ʱһ��������$n����ӿȥ",
        "force" : 570,
        "attack": 235,
        "dodge" : 155,
        "parry" : 135,
        "damage": 260,
        "damage_type":  "����"
]),
([      "action":"$N�����ϣ�ȫ������������˫���͵�����$n",
        "force" : 580,
        "attack": 250,
        "dodge" : 120,
        "parry" : 75,
        "damage": 295,
        "damage_type":  "����"
]),
([      "action":"$N�����죬������֣�ͻȻ��$N˫�������ĳ�������̫���ھ�������$n",
        "force" : 580,
        "attack": 265,
        "dodge" : 140,
        "parry" : 125,
        "damage": 260,
        "damage_type":  "����"
]),
([      "action":"$NͻȻ������һ�࣬��ס$n��·������������ӿ����",
        "force" : 580,
        "attack": 280,
        "dodge" : 125,
        "parry" : 145,
        "damage": 380,
        "damage_type":  "����"
]),
});

mapping *actionw = ({
([      "action" : "$N������磬���ƷǷ���$w�������֣�׽��������$n������ȥ",
        "force" : 510,
        "attack": 180,
        "dodge" : 115,
        "parry" : 125,
        "damage": 325,
        "damage_type": "����"
]),
([      "action":"$N���е�$w�������������糤��������������$n����",
        "force" : 510,
        "attack": 188,
        "dodge" : 112,
        "parry" : 115,
        "damage": 310,
        "damage_type": "����"
]),
([      "action":"$N�������е�$w�����緭������ֱ����$n��ȥ",
        "force" : 532,
        "attack": 225,
        "dodge" : 120,
        "parry" : 102,
        "damage": 365,
        "damage_type": "����"
]),
([      "action":"$N����$w�ó�һ�����⻷����ʱ��$n���Ű�Χ",
        "force" : 565,
        "attack": 210,
        "dodge" : 115,
        "parry" : 105,
        "damage": 390,
        "damage_type": "����"
]),
([      "action":"$N�����������$w����������ؾ���$n",
        "force" : 550,
        "attack": 248,
        "dodge" : 110,
        "parry" : 120,
        "damage": 420,
        "damage_type": "����"
]),
});

mapping *actionbad = ({
([      "action" : "$N����ʩ�У�ȴ��ͻȻ���ú�����������ʽ��ֻ�ú���ʹ����",
        "force" : 10,
        "attack": 10,
        "dodge" : 10,
        "parry" : 10,
        "damage": 10,
        "damage_type": "����"
]),
});

int valid_enable(string usage)
{ 
        object me = this_player();

        if (me->query_skill("literate", 1) 
            || me->query("learned_literate"))
                return usage == 0;

        if (! me->query("can_learned/taixuan-gong/enable_weapon"))
                return usage == "force" || usage == "unarmed" 
                || usage == "dodge" || usage == "parry";
        else
        if (me->query_skill("sword", 1) < me->query_skill("taixuan-gong", 1)
            && me->query_skill("blade", 1) < me->query_skill("taixuan-gong", 1))
                return usage == "force" || usage == "unarmed" || usage == "dodge"
                || usage == "parry";
 
        else 
        if (me->query_skill("sword", 1) < me->query_skill("taixuan-gong", 1)
            && me->query_skill("blade", 1) > me->query_skill("taixuan-gong", 1))
                return usage == "force" || usage == "unarmed" || usage == "dodge"
                || usage =="blade" || usage == "parry";

        else 
        if (me->query_skill("sword", 1) > me->query_skill("taixuan-gong", 1)
            && me->query_skill("blade", 1) < me->query_skill("taixuan-gong", 1))
                return usage == "force" || usage == "unarmed" || usage == "dodge"
                || usage =="sword" || usage == "parry";

        else        
                return usage == "force" || usage == "unarmed" || usage == "dodge"
                || usage =="blade" || usage == "parry" || usage == "sword";
       
}

int double_attack() { return 1; }

mapping query_action(object me, object weapon)
{
        if (me->query_skill("literate", 1) 
            || me->query("learned_literate"))
               return actionbad[0];

        return weapon ? actionw[random(sizeof(actionw))] :
                        actionf[random(sizeof(actionw))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp;
        int cost;  

        if (me->query_skill("literate", 1) 
            || me->query("learned_literate"))
               return;

        if ((int)me->query_skill("taixuan-gong", 1) < 150
           || me->query_skill_mapped("parry") != "taixuan-gong"
           || me->query_skill_mapped("force") != "taixuan-gong"
           || me->query_skill_mapped("unarmed") != "taixuan-gong"
           || (int)me->query("neili") < 500
           || ob->query_temp("weapon")
           || ! living(me) || random(3) != 1)
                return;

        cost = damage / 2;

        if (cost > 100) cost = 100;

        ap = ob->query_skill("force") * 12 + ob->query("max_neili");
        dp = me->query_skill("force") * 12 + me->query("neili");

        if (ap / 2 + random(ap) < dp)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);

                switch (random(2))
                {
                case 0:
                        result += (["msg" : HIR "$n" HIR "Ĭ��̫�����ھ���̫����"
                                            "�������ȫ��$N" HIR "ֻ�����й���"
                                            "$n" HIR "���ϣ���������ͭǽ����һ�㣬"
                                            "˿���������á�\n"NOR]);
                        break;
                case 1:
                        result += (["msg" : HIR "$N" HIR "һ�л���$n" HIR "����"
                                            "����ȴ�������ͭǽ������һ�㣬������ʱ"
                                            "��ʧ����Ӱ���١�\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIR "����$n" HIR "һ����Х����������"
                                            "�Ľ�����$N" HIR "��һ�У�ȴû���ܵ�"
                                            "����˺���\n" NOR]);
                        break;
                }
                return result;
        }
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        object weapon = me->query_temp("weapon");

        lvl = me->query_skill("taixuan-gong", 1);

        if (me->query_skill("literate", 1) 
            || me->query("learned_literate"))
               return 0;

        if (damage_bonus < 150
           || lvl < 140
           || me->query("neili") < 300
           || me->query_skill_mapped("force") != "taixuan-gong")
      		return 0;

        // δѧ���������
        if (! me->query("can_learned/taixuan-gong/enable_weapon"))
        {
             if (me->query_skill_prepared("unarmed") != "taixuan-gong")
                      return 0;
        }

        // �Ѿ����������
        if (me->query("can_learned/taixuan-gong/enable_weapon"))
        {             
             if (! objectp(weapon))
                  if (me->query_skill_prepared("unarmed") != "taixuan-gong")           
                         return 0;

             if (objectp(weapon) && weapon->query("skill_type") != "sword" 
                 && weapon->query("skill_type") != "blade")
                         return 0;
           
             if (objectp(weapon) && weapon->query("skill_type") == "sword"
                 && me->query_skill_mapped("sword") != "taixuan-gong")
                         return 0;
            
             if (objectp(weapon) && weapon->query("skill_type") == "blade"
                 && me->query_skill_mapped("blade") != "taixuan-gong")
                         return 0;                                   
        }

        if (random(2) == 1)return 0;

        if (damage_bonus / 5 > victim->query_con())
        {
                me->add("neili", -100);
                victim->receive_wound("qi", (damage_bonus - 76) / 2, me);
                victim->add("neili", -((damage_bonus - random(70)) / 2), me);

                if (me->query("can_learned/taixuan-gong/enable_weapon") && objectp(weapon))
                        return random(2) ? HIM "$N" HIM "һ�й�����������ǧ�����ˣ�̫���ھ�"
                                           "��ʱԴԴ����͸��" + weapon->name() + HIM "ӿ��$n" HIM "��"
                                           "�ڣ�\n" NOR:
                                           HIM "$N" HIM "̫���ھ��ŷ���$n" HIM "ֻ��ȫ��һ�𣬵�ʱһ"
                                           "������֮��͸�ض�����" + weapon->name() + HIM "��Ѫ���죡\n" NOR;

                return random(2) ? HIW "$N" HIW "һ�й�����������ǧ�����ˣ�̫���ھ�"
                                   "��ʱԴԴ����ӿ��$n" HIW "���ڣ�\n" NOR:
                                   HIW "$N" HIW "̫���ھ��ŷ���$n" HIW "ֻ��ȫ��һ"
                                   "�𣬵�ʱ�������������������߹ǣ�\n" NOR;
        }
}

int practice_skill(object me)
{
        return notify_fail("̫����ֻ����ѧ(learn)�������������ȡ�\n");
}

int valid_learn(object me)
{
        int level;
 
        if ((int)me->query_skill("literate", 1)
            || me->query("learned_literate") )
                return notify_fail("�����̫�������֮����һʱ��������ᡣ\n");

        if (me->query("gender") == "����")
                return notify_fail("���޸����ԣ����������������������̫������\n");

        if ((int)me->query("int") < 38)
                return notify_fail("����������Ȼ�������е㲻���ס�\n");

        if ((int)me->query("dex") < 34)
                return notify_fail("���о��˰��죬ֻ����ʽʼ���޷�����ʩչ��\n");

        level = me->query_skill("taixuan-gong", 1);

        if (me->query_skill("force", 1) < level)
                return notify_fail("��Ի����ڹ�����⻹�������޷���������"
                                   "�����̫������\n");

        if (me->query_skill("unarmed", 1) < level)
                return notify_fail("��Ի���ȭ�ŵ���⻹�������޷���������"
                                   "�����̫������\n");

        return ::valid_learn(me);
}

int get_ready(object me)
{
        return 1;
}

int difficult_level()
{
        return 1000;
}

string perform_action_file(string action)
{
        object me = this_player();

        if (me->query_skill("literate", 1) 
            || me->query("learned_literate"))
               return "ѧ������д����Ҳ�޷�ʩչ̫������";

        return __DIR__"taixuan-gong/perform/" + action;
}

string exert_function_file(string action)
{
        object me = this_player();

        if (me->query_skill("literate", 1) 
            || me->query("learned_literate"))
               return "ѧ������д����Ҳ�޷�ʩչ̫������";

        return __DIR__"taixuan-gong/exert/" + action;
}
