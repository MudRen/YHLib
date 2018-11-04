#include <ansi.h>
#include <combat.h>

#define FENG "��" HIW "�ɽ���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg, wn;
        object weapon;
        int level;

        if (userp(me) && ! me->query("can_perform/xiaoyao-jian/fei"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(FENG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԣ�����ʩչ" FENG "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((int)me->query_skill("xiaoyao-jian", 1) < 60)
                return notify_fail("����ң����������죬����ʩչ" FENG "��\n");

        if (me->query_skill_mapped("sword") != "xiaoyao-jian")
                return notify_fail("��û�м�����ң����������ʩչ" FENG "��\n");

        if (me->query_skill("dodge") < 150)
                return notify_fail("����Ṧ��Ϊ����������ʩչ" FENG "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" FENG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();
                           
        msg = HIC "\n$N" HIC "��Ȼ����죬�����鶯�ޱȣ�����" + wn + HIC "��"
              "�����ַ���һ�㣬��$n" HIC "�������֡�\n" NOR;

        message_sort(msg, me, target);

        level = me->query_skill("sword");

        me->add("neili", -120);

        if (level * 2 / 3 + random(level) > target->query_skill("dodge"))
        {
		msg = HIY "$N" HIY "������$n" HIY "��ʽ�е���ʵ����æ"
                      "��ס�Լ�ȫ��һʱ������Ӧ�ԣ�\n" NOR; 
                target->start_busy(4 + random(level / 25));
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