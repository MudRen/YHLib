//wai-bagua.c �����

#include <ansi.h>

inherit SKILL;

string *parry_msg = ({
        "����ȴ��$n���ð����ķ����ɾ�����������������$N��һ����\n",
        "���Ǳ�$n���б������ð��Ծ������ж����\n",
        "����$n���հ��Է�λ������ת�����е�$p����$Nֻ���޴����֡�\n",
});

string *unarmed_parry_msg = ({
        "����ȴ��$n���ð����ķ����ɾ�����������������$N��һ����\n",
        "$n����һת��˫�ְ��հ��Է�λ�����ʹ��$N���еĹ���ȫ����ա�\n",
        "����$N�о�����޻���һ����������ȫ��$n���ð��Ծ�жȥ��\n",
});

string query_parry_msg(object weapon)
{
        if (weapon)
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int valid_enable(string usage)
{
        return usage == "parry";
}

int valid_learn(object me)
{
        if ((int)me->query_skill("bagua-bu", 1) < 100)
                return notify_fail("��İ��Բ���򻹲���������ѧϰ����ԡ�\n");

        if ((int)me->query_skill("bagua-quan", 1) < 100)
                return notify_fail("��İ���ȭ��򻹲���������ѧϰ����ԡ�\n");

        if ((int)me->query_skill("bagua-zhang", 1) < 100)
                return notify_fail("��İ����ƻ�򻹲���������ѧϰ����ԡ�\n");

        if ((int)me->query_skill("parry", 1) < 100)
                return notify_fail("��Ļ����мܼ������յĻ������������޷�ѧϰ����ԡ�\n");

        if ((int)me->query_skill("parry", 1) < (int)me->query_skill("wai-bagua", 1))
                return notify_fail("��Ļ����м�ˮƽ���ޣ��޷��������������ԡ�\n");

        return 1;
}

int practice_skill(object me)
{
        if (me->query_skill("wai-bagua", 1) < 100)
                return notify_fail("���������񹦵��˽���ǳ�������������ж�����\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("������������������񹦡�\n");

        me->receive_damage("qi", 50);
        me->add("neili", -60);
        return 1;
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp;

        if ((int) me->query_skill("wai-bagua", 1) < 100
           || ! living(me))
                return;

        mp = ob->query_skill("count", 1);
        ap = ob->query_skill("force") + mp;
        dp = me->query_skill("parry", 1) / 2 +
             me->query_skill("wai-bagua", 1);

        if (ap / 2 + random(ap) < dp * 3 / 4)
        {
                result = ([ "damage" : -damage ]);

                switch(random(3))
                {
                case 0:
                        result += ([ "msg" : WHT "$n" WHT "���κ�Ȼ���հ��Է�"
                                             "λת����ͣ��$N" WHT "��һ�о�Ȼ"
                                             "�޴����֡�\n" NOR ]);
                        break;
                case 1:
                        result += ([ "msg" : WHT "$n" WHT "�������ð����ķ���"
                                             "�ɾ�����һ�У�$N" WHT "��ʱ����"
                                             "��׼��������������һ����������"
                                             "�ĸо���\n" NOR ]);
                        break;

                default:
                        result += ([ "msg" : WHT "$N" WHT "һ���ۿ�������$n"
                                             WHT "��Ȼ��$n" WHT "����һ��"
                                             "��$N" WHT "�Ĺ������ð����ɾ�"
                                             "�������Ρ�\n" NOR ]);
                        break;
                }
                return result;
        } else
        if (mp >= 100)
        {
                switch (random(2))
                {
                case 0:
                        result = HIY "$n" HIY "�����ȭ��飬���������ɾ�����$N"
                                 HIY "��ͨ����˿������˼�����漴������С�\n" NOR;
                        break;
                default:
                        result = HIY "$n" HIY "���հ�����λת����ͣ����ȴ��$N"
                                 HIY "һ����Ц��˳�ֱ���һ�У�ǡ���ƾ�������\n" NOR;
                        break;
                }
                COMBAT_D->set_bhinfo(result);
        }
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("wai-bagua", 1);
        if (lvl < 100) return 0;
        if (lvl < 150) return 20;
        if (lvl < 200) return 40;
        if (lvl < 250) return 50;
        if (lvl < 300) return 60;
        if (lvl < 350) return 70;
        return 80;
}

string perform_action_file(string action)
{
        return __DIR__"wai-bagua/" + action;
}
