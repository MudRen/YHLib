// fugu.c ��������

#include <ansi.h>

inherit F_SSERVER;

#define GU "��" HIW "��������" NOR "��"

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/tianshan-zhang/fugu"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(GU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "staff")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
                
        if ((int)me->query_skill("tianshan-zhang", 1) < 60)
                return notify_fail("�����ɽ�ȷ�������죬����ʹ��" GU "��\n");

        if (me->query_skill_mapped("staff") != "tianshan-zhang")
                return notify_fail("��û�м�����ɽ�ȷ���ʹ����" GU "��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIG "$N" HIG "�����Ц�����е�" + weapon->name() +
              HIG "����Ӱ��һ��Ϯ��$n��\n" NOR;

        ap = me->query_skill("staff");
        dp = target->query_skill("dodge");
        if (ap * 11 / 20 + random(ap) > dp)
        {
                msg += HIR "���$n" HIR "��$N" HIR "�ŵþ���ʧ�룬"
                       "һʱ����æ���ң�����Ӧ�ԣ�\n" NOR;
                target->start_busy((int)me->query_skill("staff") / 25 + 2);
        } else
        {
                msg += "����$n" HIR "������$N" HIR "����ͼ��"
                       "����һ�ˣ���ȥ��$N" HIR "��׷����\n" NOR;
                me->start_busy(1);
        }
        message_combatd(msg, me, target);

        return 1;
}
