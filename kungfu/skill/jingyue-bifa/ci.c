#include <ansi.h>
#include <combat.h>

#define CI "��" HIW "���´�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg, wn;
        object weapon;
        int level;

        if (userp(me) && ! me->query("can_perform/jingyue-bifa/ci"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(CI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "dagger")
		return notify_fail("��ʹ�õ��������ԣ�����ʩչ" CI "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((int)me->query_skill("jingyue-bifa", 1) < 30)
                return notify_fail("�㾪�±ʷ�������죬����ʩչ" CI "��\n");

        if (me->query_skill_mapped("dagger") != "jingyue-bifa")
                return notify_fail("��û�м������±ʷ�������ʩչ" CI "��\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�����ڵ���������������ʩչ" CI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();
                           
        msg = HIC "\n$N" HIC "ŭХһ����ʩչ�����С�" HIW "���´�" HIC "��"
              "����" + wn + HIC "����һ�����Σ���$n" HIC "���֡�"NOR;

        message_sort(msg, me, target);

        level = me->query_skill("jingyue-bifa", 1);

        me->add("neili", -80);

        if (level + random(level) > target->query_skill("dodge"))
        {
		msg = HIY "$N" HIY "������$n" HIY "��ʽ�е���ʵ����æ"
                      "��ס�Լ�ȫ��һʱ������Ӧ�ԣ�\n" NOR; 
                target->start_busy(2 + random(level / 24));
                me->start_busy(random(2));
	} else
        {
		msg = CYN "����$N" CYN "��������С�Ĳ��У�û�б�"
                      "$n" NOR + CYN "��ʽ������\n" NOR;
                      
                me->start_busy(2);
	}
	message_combatd(msg, target, me);

	return 1;
}