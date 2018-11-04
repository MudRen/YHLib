#include <ansi.h>
#include <combat.h>

#define XIAN "��" HIG "���ξ�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
	int ap, dp, level;

        if (userp(me) && ! me->query("can_perform/xiaoyaoyou/xian"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(XIAN "ֻ����ս���в���ʹ�á�\n");

        if ((level = me->query_skill("xiaoyaoyou", 1)) < 100)
                return notify_fail("�����ң��ȭ����������������ʩչ" XIAN "��\n");

        if (me->query_skill_mapped("dodge") != "xiaoyaoyou")
                return notify_fail("��û�м�����ң��Ϊ�Ṧ������ʩչ" XIAN "��\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�����ڵ��������㣬����ʩչ" XIAN "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "����΢�Σ�ʩ����" HIG "���ξ�"
              HIW "���������ߣ�����������������ΪƮ�ݡ�\n" NOR;

        ap = me->query_skill("dodge");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                msg += HIR "$n" HIR "ֻ��������Ӱ���������ɴ�"
                       "��ʧɫ�����ƶ�Ϊ���͡�\n" NOR;
                target->start_busy(level / 18 + 2);
                me->start_busy(1);
                me->add("neili", -80);
        } else
        {
                msg += CYN "����$n" CYN "������$P" CYN "����"
                       "������û���ܵ��κ�Ӱ�졣\n" NOR;
                me->start_busy(2);
                me->add("neili", -50);
        }
        message_combatd(msg, me, target);

        return 1;
}
