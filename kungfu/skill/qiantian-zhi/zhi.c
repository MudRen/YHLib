#include <ansi.h>
#include <combat.h>

#define ZHI "��" HIR "Ǭ����ָ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if (userp(me) && ! me->query("can_perform/qiantian-zhi/zhi"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("qiantian-zhi", 1) < 80)
                return notify_fail("��Ǭ��ָ��������죬����ʩչ" ZHI "��\n");

        if (me->query_skill_mapped("finger") != "qiantian-zhi")
                return notify_fail("��û�м���Ǭ��ָ��������ʩչ" ZHI "��\n");

        if (me->query_skill_prepared("finger") != "qiantian-zhi")
                return notify_fail("��û��׼��Ǭ��ָ��������ʩչ" ZHI "��\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("���ڹ���Ϊ����������ʩչ" ZHI "��\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�����ڵ���������������ʩչ" ZHI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "��Ȼʹ��һ�С�Ǭ����ָ����˫ָ��ʩ��ͬʱ��$n"
              HIR "���ż��ؿڴ���ȥ��\n" NOR;

        if (random(me->query_skill("finger")) > target->query_skill("parry") / 2)
        {
                me->start_busy(2);
                damage = me->query_skill("finger");
                damage = 40 + damage / 3 + random(damage / 3);
                me->add("neili", -80);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30,
                                           HIR "���$p" HIR "������������ʱ��$P"
                                           HIR "һָ���У���Ϣ���ɵ�һ�ͣ�����֮����\n" NOR);
        } else
        {
                me->start_busy(3);
                me->add("neili", -50);
                msg += CYN "����$p" CYN "ʶ����$P"
                       CYN "��һ�У�ббһԾ�ܿ���\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
