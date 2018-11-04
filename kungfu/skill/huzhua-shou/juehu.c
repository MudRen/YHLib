#include <ansi.h>
#include <combat.h>

#define JUEHU "��" HIR "������ץ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/huzhua-shou/juehu"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(JUEHU "ֻ����ս���жԶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("�������ֲ���ʹ��" JUEHU "��\n");

        if (userp(me) && me->query("shen") < 10000)
                return notify_fail(HIC "\n��������������ʩչ���У���ͻȻ�뵽����������"
                                   "��һ����룬���ò���;�����˹�����\n" NOR);

        if ((int)me->query_skill("huzhua-shou", 1) < 120)
                return notify_fail("��Ļ�צ�����ֲ�����죬����ʩչ" JUEHU "��\n");

        if (me->query_skill_mapped("claw") != "huzhua-shou")
                return notify_fail("��û�м�����צ�����֣�����ʩչ" JUEHU "��\n");

        if (me->query_skill_prepared("claw") != "huzhua-shou")
                return notify_fail("��û��׼��ʹ�û�צ�����֣��޷�ʹ��" JUEHU "��\n");

        if (me->query("neili") < 300)
                return notify_fail("��������������������ʩչ" JUEHU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "���һ��������Ϊצ��˫צ��������צӰ����������һ����$n"
              HIR "��Ҫ��ץȥ��\n" NOR;

        if (random(me->query_skill("claw")) > target->query_skill("parry") / 2)
        {
                me->start_busy(2);

                damage = me->query_skill("huzhua-shou", 1);
                damage = damage * 3 + random(damage * 6);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 40,
                                           HIR "���$p" HIR "һ���Һ���û���м�ס$P"
                                           HIR "�����Ĺ��ƣ���ץ��Ƥ����룬��Ѫ�ɽ���\n" NOR);
                me->add("neili", -200);
        	me->add("shen", -3000);
        } else
        {
                me->start_busy(3);
	        me->add("neili", -100);
        	me->add("shen", -3000);
                msg += CYN "����$p" CYN "������$N"
                       CYN "����ͼ���㿪������ɱ�š�\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

