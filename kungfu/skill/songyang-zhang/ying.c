#include <ansi.h>
#include <combat.h>

#define YING "��" HIY "��Ӱ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/songyang-zhang/ying"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(YING "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(YING "ֻ�ܿ���ʩչ��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((int)me->query_skill("songyang-zhang", 1) < 100)
                return notify_fail("�������Ʋ�����죬����ʩչ" YING "��\n");

        if (me->query_skill_prepared("strike") != "songyang-zhang")
                return notify_fail("��û��׼�������ƣ�����ʩչ" YING "��\n");

        if (me->query_skill("dodge") < 150)
                return notify_fail("����Ṧ��Ϊ����������ʩչ" YING "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" YING "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("songyang-zhang", 1) +
             me->query_skill("dodge", 1) / 2;

        dp = target->query_skill("dodge");

        msg = HIC "\n$N" HIC "һ����Х��ʩ�����С�" HIY "��Ӱ��" HIC
              "��˫�Ʋ����ĳ����Ʒ����죬���Ƴ��գ���$n" HIC "����"
              "Χס��\n" NOR;
        message_sort(msg, me, target);
        
        if (random(ap) > dp / 2)
        {
		msg = HIR "$n" HIR "������ѣ�һʱ�侹�޴�Ӧ�ԣ�"
                      "��������$N" HIR "���Ʒ�֮�С�\n" NOR;

                target->start_busy(ap / 40 + 1);
               	me->start_busy(1);
                me->add("neili", -80);
        } else
        {
                msg = CYN "$n" CYN "����$N" CYN "���޹���֮�⣬��"
                      "�Ǵ󵨷�������$N" CYN "���о������⡣\n" NOR;

                me->start_busy(2);
                me->add("neili", -30);
        }
        message_vision(msg, me, target);

        return 1;
}
