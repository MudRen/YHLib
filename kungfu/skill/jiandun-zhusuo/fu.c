#include <ansi.h>

#define FU "��" HIW "���־�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;

        if (userp(me) && ! me->query("can_perform/jiandun-zhusuo/fu"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(FU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            weapon->query("skill_type") != "whip")
                return notify_fail("����������ԣ�����ʩչ" FU "��\n");

        if (me->query_skill("jiandun-zhusuo", 1) < 50)
                return notify_fail("��Ľ����������𲻹�������ʩչ" FU "��\n");

        if (me->query("neili") < 50)
                return notify_fail("��������������������ʩչ" FU "��\n");

        if (me->query_skill_mapped("whip") != "jiandun-zhusuo")
                return notify_fail("��û�м�����������������ʩչ" FU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "����һ�����" + weapon->name() +
              HIW "��ʱ��������������ػ�������$n" HIW "��\n";

        me->start_busy(1);

        if (random((int)me->query_skill("jiandun-zhusuo", 1)) > (int)target->query_skill("parry", 1) / 2)
        {
                msg += HIR "$n" HIR "ֻ��ȫ��һ�����ѱ�" + weapon->name() +
                       HIR "���θ�ס���������ã�\n" NOR;
                target->start_busy((int)me->query_skill("jiandun-zhusuo") / 20 + 1);
        } else
        {
                msg += CYN "����$p" CYN "������$P"
                       CYN "����ͼ��б������������\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
