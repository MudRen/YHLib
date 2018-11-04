#include <ansi.h>

#define YING "��" MAG "��Ӱ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/tie-zhang/ying"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(YING "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");
                
        if ((int)me->query_skill("tie-zhang", 1) < 100)
                return notify_fail("��������Ʒ���������죬����ʩչ" YING "��\n");

        if (me->query_skill_mapped("strike") != "tie-zhang")
                return notify_fail("��û�м��������Ʒ�������ʩչ" YING "��\n");

        if (me->query_skill_prepared("strike") != "tie-zhang")
                return notify_fail("������û��׼��ʹ�������Ʒ�������ʩչ" YING "��\n");

        if (me->query("neili") < 100)
                return notify_fail("�����������������޷�ʩչ����Ӱ�ơ���\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = MAG "ֻ��$N" MAG "˫�Ƽ�����ת��ʹ�������Ʒ���������Ӱ�ơ�����Ӱ����ʵ"
              "ʵ����������������$n" MAG "��\n" NOR;

        me->add("neili", -80);
        if (random(me->query_skill("strike")) > (int)target->query_skill("force") / 2)
        {
                msg += HIR "���$p" HIR "��ȫ��ĥ��͸$P" HIR "������Ʒ������ƶ�ʱ��"
                       "�͡�\n" NOR;
                target->start_busy((int)me->query_skill("strike") / 20 + 2);
        } else
        {
                msg += CYN "����$p" CYN "��û�ϵ���Ӳ��������$P"
                       CYN "�⼸�ơ�\n" NOR;
                me->start_busy(1);
        }
        message_combatd(msg, me, target);

        return 1;
}