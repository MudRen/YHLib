#include <ansi.h>
#include <combat.h>

#define TAO "��" HIG "��������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if (userp(me) && ! me->query("can_perform/canglang-zhi/tao"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(TAO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(TAO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("canglang-zhi", 1) < 80)
                return notify_fail("�����ָ��������죬����ʩչ" TAO "��\n");

        if (me->query_skill_mapped("finger") != "canglang-zhi")
                return notify_fail("��û�м�������ָ��������ʩչ" TAO "��\n");

        if (me->query_skill_prepared("finger") != "canglang-zhi")
                return notify_fail("��û��׼������ָ��������ʩչ" TAO "��\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���Ϊ����������ʩչ" TAO "��\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�����ڵ���������������ʩչ" TAO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIG "$N" HIG "��Ȼʩ��һ�ơ��������졹��ʮָ�׷���ָ����Ȼ��"
              "�죬ȫȫ����$n" HIG "��\n" NOR;

        if (random(me->query_skill("finger")) > target->query_skill("parry") / 2)
        {
                me->start_busy(2);
                damage = me->query_skill("finger");
                damage = 40 + damage / 3 + random(damage / 3);
                me->add("neili", -80);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30,
                                           HIR "���$n" HIR "������������$N" HIR
                                           "һָ���У�ȫ����Ѫ���ڲ��ѡ�\n" NOR);
        } else
        {
                me->start_busy(3);
                me->add("neili", -50);
                msg += CYN "����$n" CYN "ʶ����$N"
                       CYN "��һ�У�ббһԾ�ܿ���\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
