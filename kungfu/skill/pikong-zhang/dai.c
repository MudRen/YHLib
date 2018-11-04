#include <ansi.h>
#include <combat.h>

#define DAI "��" HIB "���Ǵ���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if (userp(me) && ! me->query("can_perform/pikong-zhang/dai"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(DAI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail(DAI "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("pikong-zhang", 1) < 80)
                return notify_fail("�������Ʋ�����죬����ʩչ" DAI "��\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ���Ϊ����������ʩչ" DAI "��\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�����ڵ���������������ʩչ" DAI "��\n");

        if (me->query_skill_mapped("strike") != "pikong-zhang") 
                return notify_fail("��û�м��������ƣ�����ʩչ" DAI "��\n");

        if (me->query_skill_prepared("strike") != "pikong-zhang")
                return notify_fail("��û��׼�������ƣ�����ʩչ" DAI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIB "ֻ��$N" HIB "˫�ƽ������ƹ�������������Ȧ������һ����"
              "��$n" HIB "�ȥ��\n" NOR;

        if (random(me->query_skill("strike")) > target->query_skill("dodge") / 2)
        {
                me->start_busy(2);
                damage = me->query_skill("strike");
                damage = damage / 2 + random(damage / 2);
                me->add("neili", -50);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 20,
                                           HIR "$n" HIR "һ������$N" HIR "�ƾ���"
                                           "����ǰ���������𣬵�ʱŻ��һ����Ѫ��\n" NOR);
        } else
        {
                me->start_busy(3);
                me->add("neili", -30);
                msg += CYN "����$p" CYN "ʶ����$P"
                       CYN "��һ�У�ббһԾ�ܿ���\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
