#include <ansi.h>
#include <combat.h>

#define XIAN "��" HIY "�������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;
        int level;

        if (userp(me) && ! me->query("can_perform/poyang-jian/xian"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(XIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" XIAN "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        level = me->query_skill("poyang-jian", 1);

        if (level < 120)
		return notify_fail("��������⽣������죬����ʩչ" XIAN "��\n");

        if (me->query_skill_mapped("sword") != "poyang-jian")
                return notify_fail("��û�м���������⽣������ʩչ" XIAN "��\n");

	if ((int)me->query_skill("force") < 200)
		return notify_fail("����ڹ�����㣬����ʩչ" XIAN "��\n");

        if (me->query("neili") < 150)
                return notify_fail("�����ڵ���������������ʩչ" XIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");


	msg = HIG "\n$N" HIG "��Хһ����ʹ��������⽣���С�" HIY "�����"
              "��" HIG "��������" + weapon->name() + HIG "��â���ǣ�����"
              "ѣĿ��������⽵����ɲ�Ǽ�ֻ�������Ϊ֮ʧ�ԣ���â�Ѹ�"
              "��$n\n" HIG "��" NOR;
        message_sort(msg, me, target);

        me->add("neili", -120);
        if (level / 2 + random(level) > target->query_skill("dodge", 1))
        {
		msg = HIR "$n" HIR "��ҫ�۵Ĺ�â�������о�"
                      "�ɲ�����һʱ�䲻֪���Ӧ�ԣ�\n" NOR; 
                target->start_busy(level / 26 + 2);
                me->start_busy(1);
	} else
        {
		msg = CYN "����$n" CYN "������$N"
                      CYN "����ͼ��һ˿���ң�Ӧ��������\n" NOR;
                me->start_busy(2);
	}
	message_vision(msg, me, target);

	return 1;
}