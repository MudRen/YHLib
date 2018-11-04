#include <ansi.h>
#include <combat.h>

#define MENG "��" HIW "�������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg, wn;
        object weapon;
        int level;

        if (userp(me) && ! me->query("can_perform/songshan-jian/meng"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(MENG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԣ�����ʩչ" MENG "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((int)me->query_skill("songshan-jian", 1) < 40)
                return notify_fail("���������������죬����ʩչ" MENG "��\n");

        if (me->query_skill_mapped("sword") != "songshan-jian")
                return notify_fail("��û���������������ʩչ" MENG "��\n");

        if ((int)me->query("neili") < 120)
                return notify_fail("�����ڵ���������������ʩչ" MENG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();
                           
        msg = HIC "\n$N" HIC "ŭХһ����ʩչ�����С�" HIW "�������" HIC "��"
              "����" + wn + HIC "�ƹ��ǹ����������ˣ����˷�����˼��\n"NOR;

        message_sort(msg, me, target);

        level = me->query_skill("songshan-jian", 1);

        me->add("neili", -80);

        if (level + random(level) > target->query_skill("dodge"))
        {
		msg = HIY "$N" HIY "������$n" HIY "��ʽ�е���ʵ����æ"
                      "��ס�Լ�ȫ��һʱ������Ӧ�ԣ�\n" NOR; 
                target->start_busy(2 + random(level / 26));
                me->start_busy(random(2));
	} else
        {
		msg = CYN "����$N" CYN "��������С�Ĳ��У�û�б�"
                      "$n" NOR + CYN "��ʽ������\n" NOR;
                      
                me->start_busy(2);
	}
	message_vision(msg, target, me);

	return 1;
}