// ����ָ��������ָ�����֡�
// �����书�ؼ�����Ľ�����ң�    ���÷�ָ������Ҷָ������ָ��
// ����������ס�֡������ߡ���  ����ָ
// �Ϻ�������Ϫ����              ����ָ
// �ض�������������              ������ָ
// ����ɽ���޶����ˡ���          �������ָ
// ���ϡ���ڤ���ˡ�              ��ڤָ
// ����Ϊ��
// canhe-zhi.c �κ�ָ��

#include <ansi.h>
#include <combat.h>
inherit SKILL;
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;

mapping *action = ({
([      "action": "$N˫ָ��£���������ϡ�"NOR + MAG "���÷�ָ" NOR "����"
                  "��" NOR + MAG "����ָ" NOR "��Ϊһʽ����ʱһ���ֱ��$n",
        "force" : 480,
        "attack": 110,
        "parry" : 90,
        "dodge" : 95,
        "damage": 160,
        "weapon" : HIR "�κ����彣��" NOR,
        "damage_type" : "����"
]),
([      "action": "$N˫ָ���������ϡ�" HIG "����ָ" NOR "������" HIG "����Ҷ"
                  "ָ" NOR "��Ϊһʽ����ʱ����������$nȫ�����",
        "force" : 460,
        "attack": 100,
        "parry" : 90,
        "dodge" : 115,
        "damage": 180,
        "weapon" : HIR "�κ����彣��" NOR,
        "damage_type" : "����"
]),
([      
        "action": "ֻ��$Nʮָ���ţ�����ָָ��㣬����" HIY "�������ָ" NOR "����"
                  "��" HIY "������ָ" NOR "���ľ�����ʽͬʱʹ����\n��ʱ�����ݺᣬ��"
                  "ɰ���𣬱���$n��ȥ",
        "force" : 460,
        "attack": 100,
        "parry" : 135,
        "dodge" : 125,
        "damage": 180,
        "weapon" : HIR "�κ����彣��" NOR,
        "damage_type" : "����"
]),
([      
        "action": "ֻ��$N����Ծ�𣬳�Хһ������ն��£���" HIM "���ǽ���" NOR "������"
                  "��$nȫ�����",
        "force" : 460,
        "attack": 100,
        "parry" : 115,
        "dodge" : 145,
        "damage": 200,
        "weapon" : HIR "�κ����彣��" NOR,
        "damage_type" : "����"
]),
([      "action": "$N�����ָ����ָ��������������������ָ��͸������" HIW "��ڤ����" NOR
                  "������$n�����Ѩ",
        "force" : 460,
        "attack": 120,
        "parry" : 130,
        "dodge" : 125,
        "damage": 200,
        "weapon" : HIR "�κ����彣��" NOR,
        "damage_type" : "����"
]),
([      "action": "ң��$N���һָ�������$n��ָδ������" HIR "�κϽ���" NOR "���ѽ�$nѹ"
                  "��͸��������",
        "force" : 480,
        "attack": 120,
        "parry" : 150,
        "dodge" : 165,
        "damage": 240,
        "weapon" : HIR "�κ����彣��" NOR,
        "damage_type" : "����"
])
});

string main_skill() { return "canhe-zhi"; }

mapping sub_skills = ([
        "lianhua-zhi"    : 120,
        "tianlong-zhi"   : 120,
        "qilian-zhi"     : 120,
        "tianzhu-fuzhi"  : 120,
        "qixing-zhi"     : 120,
        "youming-zhi"    : 120,
        "xiuluo-zhi"     : 120,
        "duoluoye-zhi"   : 120,
]);

int get_ready(object me)
{
        return 1;
}

int get_finish(object me)
{
        object ob;

        if (me->query("int") < 34)
        {
                tell_object(me, "��ֻ�����Լ������ԣ��޷��ϳɲκ�ָ�񹦡�\n");
                return 0;
        }

        if (me->query("dex") < 36)
        {
                tell_object(me, "��ֻ�����Լ������鶯�ԣ������޷��ϳɲκ�ָ�񹦡�\n");
                return 0;
        }

        if (me->query_skill("literate", 1) < 200)
        {
                tell_object(me, "����òκ�ָ�񹦼�����£��������о�һ��ѧ�ʿ��ܸ��а�"
                                "����\n");
                return 0;
        }

        if (me->query_skill("jingluo-xue", 1) < 160)
        {
                tell_object(me, "��������ϣ��������ͨ������ѧӦ�ø�����������\n");
                return 0;
        }

        if (me->query_skill("martial-cognize", 1) < 200)
        {
                tell_object(me, "�㷢���Լ�����ѧ�����д���ߣ������޷������ɹ���\n");
                return 0;
        }

        if (me->query_skill("force", 1) < 240)
        {
                tell_object(me, "�㷢���Լ����ڹ����������������޷������ɹ���\n");
                return 0;
        }

        if ((int)me->query("max_neili") < 4500)
        {
                tell_object(me, "������Լ��������̣��޷��ϳɲκ�ָ�񹦡�\n");
                return 0;
        }

        if (random(10) < 7)
        {
                tell_object(me, "������������򣬻���������һ�ξ����ڻ��ͨ��\n");
                return 0;
        }

        tell_object(me, HIY "\n���Ǽ䣬��ֻ������������������ָ���������Ժ��н����\n"
                            "�֣��������ٴ��麣�������ڻ��ͨ����Ϊ���Ҿ�ѧ�κ�\n"
                            "ָ�񹦡�������ͨ���˲κ�ָ�ľ��ϡ�\n" NOR);

        return 1;
}

mapping query_sub_skills()
{
        return sub_skills;
}

int valid_enable(string usage)
{
	return usage == "finger" || usage == "parry";
}

int double_attack()
{
	return 1;
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���κ�ָ������֡�\n");

        if ((int)me->query("int") < 34)
                return notify_fail("�����������̫�ͣ��޷����κ�ָ��\n");

        if ((int)me->query("dex") < 36)
                return notify_fail("����������������޷������κ�ָ��\n");

        if ((int)me->query_skill("force", 1) < 240)
                return notify_fail("����ڹ���򲻹����޷�������ָ��\n");

        if ((int)me->query("max_neili") < 4500)
                return notify_fail("�������̫�����޷������κ�ָ��\n");

        if ((int)me->query_skill("finger", 1) < 160)
                return notify_fail("��Ļ���ָ����򲻹����޷������κ�ָ��\n");

        if (me->query_skill("jingluo-xue", 1) < 160)
                return notify_fail("�㷢���������кܶ���������ľ��繹���йأ�������⡣\n");

        if (me->query_skill("martial-cognize", 1) < 120)
                return notify_fail("�����ѧ�����д���ߣ������޷������κ�ָ��\n");

        if ((int)me->query_skill("finger", 1) < (int)me->query_skill("canhe-zhi", 1))
                return notify_fail("��Ļ���ָ��ˮƽ���ޣ��޷���������Ĳκ�ָ��\n");

        return 1;
}

int practice_skill(object me)
{
        int cost;

        if (me->query_skill("canhe-zhi", 1) > 120 
            && me->query_skill("zihui-xinfa", 1) < 120)
                return notify_fail("���ϻ��ķ���Ϊ������������ȥ���»��߻���ħ��\n");

        if ((int)me->query("qi") < 130)
                return notify_fail("�������̫���ˡ�\n");

        cost = me->query_skill("canhe-zhi", 1) / 2 + 60;

        if ((int)me->query("neili") < cost)
                return notify_fail("������������ˡ�\n");

        me->receive_damage("qi", 100);
        me->add("neili", -cost);
        return 1;
}

mapping query_action(object me, object weapon)
{

        if (! undefinedp(me->query_temp("canhe-action")))
                return action[me->query_temp("canhe-action")];

        if (random(10) == 1 && me->query("neili") > 1000)
        {
                me->add("neili", -300);
                return ([       "action": HIC "$N" HIC "���������˫ָ���������ָ����"
                                          "�����ƿն����ġ��κϽ������Ѿ�����$n",
        		        "attack": 280,
                                "dodge" : 140,
                                "parry" : 140,
                                "damage": 320,
                                "force" : 560,
                                "weapon" : HIR "�κ����彣��" NOR,
                                "damage_type": "����"
		        ]);
        } 

        return action[random(sizeof(action))];
}

string query_parry_msg(object victim_weapon)
{
        switch (random(3))
        {
        case 0:
                return NOR + WHT "$n" NOR + WHT"���˷���������ʳָ��ֱָ��$N" NOR + WHT
                       "��ǰ��Ѩ��$Nһ������æ�����Ծȡ�\n" NOR;
        case 1:
                return NOR + WHT "$n" NOR + WHT"˫ָ���������Ѹ���������������־��Ĳ�"
                       "�Ͻ�������������$N" NOR + WHT"�޴����֡�\n" NOR;
        default:
                return NOR + WHT "$n" NOR + WHT"��Хһ������������������$N" NOR + WHT
                       "˫ָ������������$P��Χ������һ����һ�㣬����������\n";
        }
}

void skill_improved(object me)
{
        int i;
        string *sub_skillnames;

        sub_skillnames = keys(sub_skills);

        for (i = 0; i < sizeof(sub_skillnames); i++)
                me->delete_skill(sub_skillnames[i]);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl, slv, p;
        object target;
        string msg;

        if (! target) target = offensive_target(me);
        lvl = me->query_skill("canhe-zhi", 1);

        // �������񽣾������Խ��κϽ����ۻ�
        if (slv = target->query_skill("liumai-shenjian", 1) > 200 
            && target->query_skill_prepared("finger") == "liumai-shenjian"
            && slv >= me->query_skill("canhe-zhi", 1) - 60
            && random(10) == 0)
        {  
                msg = action[random(sizeof(action))]["action"];
                msg += HIY "\n����$n" HIY "ббһָ�����ָ����磬�����ݺᣬ��Ȼ"
                       "���죬����$N" HIY "�Ľ���ȫ���ۻأ������Լ���ȥ��\n" NOR;

                me->receive_wound("qi", slv / 4 + random(slv / 6), target);
                p = (int)me->query("qi") * 100 / (int)me->query("max_qi");
                msg += "( $N" + eff_status_msg(p) + ")\n";
                return msg;
        }

        if (damage_bonus < 220 || lvl < 140) return 0;

        if (damage_bonus / 5 > victim->query_dex()
            && random(5) == 0 && me->query("neili") > 65)
        {
                me->add("neili", -80);
                victim->receive_wound("qi", (damage_bonus - 80) / 3, me);
                	return HIR "��ֻ���������͡��ƿ������죬���Ͼ�����һЩѪ�Σ�\n" NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"canhe-zhi/" + action;
}
