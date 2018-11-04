#include <ansi.h>
#include <combat.h>

#define ZHEN "��" WHT "������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;

        if (userp(me) && ! me->query("can_perform/wai-bagua/zhen"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHEN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail(ZHEN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ�����㣬����ʩչ" ZHEN  "��\n");

        if ((int)me->query_skill("wai-bagua", 1) < 60)
                return notify_fail("�������Բ�����죬����ʩչ" ZHEN  "��\n");
                                
        if ((int)me->query("neili") < 100)
                return notify_fail("�������������㣬����ʩչ" ZHEN  "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = WHT "$N" WHT "����һ������˫�ƽ���һ�С�������ƽƽ�ĳ�����"
              "ͼ����������$n" WHT "��\n" NOR;
        me->add("neili", -50);

        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {
                me->start_busy(3);
                target->start_busy(random(3));

                damage = (int)me->query_skill("wai-bagua", 1);
                damage = damage / 2 + random(damage / 2);
                
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30,
                                           HIR "���$n" HIR "΢΢һ�㣬û�п�����"
                                           "�а��$N" HIR "˫������������ǰ��\n"
                                           NOR ":����@?");
        } else 
        {
                me->start_busy(3);
                msg += CYN "����$p" CYN "������$P"
                       CYN "����ͼ����û���ϵ���\n" NOR;
        }
        message_combatd(msg, me, target);
        return 1;
}
