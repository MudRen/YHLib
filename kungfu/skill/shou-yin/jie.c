// jie.c ���

#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int count;
        int i;
 
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("����١�ֻ����ս���жԶ���ʹ�á�\n");
 
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����١�ֻ�ܿ���ʹ�á�\n");
                
        if (me->query("max_neili") < 3000)
                return notify_fail("���������Ϊ���������޷�ʩչ��١�\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�������������\n");

        if ((int)me->query("qi") < 800)
                return notify_fail("����������ڲ�����\n");

        if ((int)me->query_skill("shou-yin", 1) < 150)
                return notify_fail("�����ӡ��򲻹����޷�ʹ����٣�\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("����ڹ���Ϊ�������޷�ʹ����٣�\n");

        if (me->query_skill_prepared("hand") != "shou-yin")
                return notify_fail("������û��׼��ʹ����ӡ���޷�ʹ����٣�\n");

        msg = HIW "$N" HIW "һ�����ȣ�˫����Ȼ������"
              "ɲ�Ǽ�ֻ����������ӡ����ǵط�ӵ������"
              "���ƻֺ룬�����ױȡ�\n" NOR;
        ap = me->query_skill("strike") + me->query("str") * 10;
        dp = target->query_skill("parry") + target->query("dex") * 6;
        if (ap / 2 + random(ap) > dp)
        {
                count = ap / 9;
                msg += HIR "$n" HIR "���$P" HIR "����ɽ�������ƣ���ȫ"
                       "�޷��ֵ���Ψ���˺�\n" NOR;
        } else
        {
                msg += HIC "$n" HIC "����Ӧս���߾����ܻ���$P" HIC
                       "�⼸�ơ�\n" NOR;
                count = 0;
        }

        message_vision(msg, me, target);
        me->add_temp("apply/attack", count);

        me->add("neili", -300);
        me->add("qi", -100);    // Why I don't use receive_damage ?
                                // Becuase now I was use it as a cost
        for (i = 0; i < 9; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(5) < 2 && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->start_busy(1 + random(5));
        me->add_temp("apply/attack", -count);

        return 1;
}

