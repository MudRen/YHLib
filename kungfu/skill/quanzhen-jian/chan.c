#include <ansi.h>
#include <combat.h>

#define CHAN "��" HIC "���־�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int level;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/quanzhen-jian/chan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(CHAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" CHAN "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((level = me->query_skill("quanzhen-jian", 1)) < 80)
                return notify_fail("��ȫ�潣��������죬����ʩչ" CHAN "��\n");

        if (me->query_skill_mapped("sword") != "quanzhen-jian")
                return notify_fail("��û�м���ȫ�潣��������ʩչ" CHAN "��\n");

        if (me->query("neili") < 100)
                return notify_fail("�����ڵ���������������ʩչ" CHAN "��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "$N" HIC "ʹ��ȫ�潣���������־���" + weapon->name() +
              HIC "�������������������˷�������$n" HIC "��\n" NOR;

        me->add("neili", -50);
        ap = me->query_skill("sword");
        dp = target->query_skill("force");

        if (ap / 2 + random(ap) > dp)
        {
                msg += HIR "$p" HIR "ֻ����$P" HIR
                       "����ѹ��һ��ǿ��һ�㣬ֻ��ʹ����������˹��ֵ���\n" NOR;
                target->start_busy(level / 28 + 2);
        } else
        {
                msg += CYN "$p" CYN "��$P" CYN "�з��Ͻ������²���С��"
                       "��������$P" CYN "�����У���¶���������\n" NOR;
                me->start_busy(1);
        }
        message_combatd(msg, me, target);

        return 1;
}

