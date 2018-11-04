#include <ansi.h>

#define CHAN "��" HIM "�ƹǲ���" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;

        if (userp(me) && ! me->query("can_perform/panlong-suo/chan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail(CHAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" CHAN "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

	if ((int)me->query_skill("force") < 180)
		return notify_fail("����ڹ���򲻹�������ʩչ" CHAN "��\n");

	if ((int)me->query_skill("panlong-suo", 1) < 120)
		return notify_fail("��������������������ң�����ʩչ" CHAN "��\n");

        if (me->query_skill_mapped("whip") != "panlong-suo")
                return notify_fail("��û�м�������������������ʩչ" CHAN "��\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("�����������������ʩչ" CHAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIM "$N" HIM "һ����Х������" + weapon->name() + HIM "һ������ʱ"
              "�û��������â��$n" HIM "�������׹�ȥ��\n" NOR;

        if (random(me->query_skill("whip")) > target->query_skill("parry") / 2)
        {
        	msg += HIR "��ʱ$n" HIR "ֻ��" + weapon->name() + HIR
                       "ѹ���������ӣ������ƹ�֮������֮��ȥ��\n" NOR;
                target->start_busy((int)me->query_skill("panlong-suo") / 20 + 1);
	        me->add("neili", -80);
	        me->start_busy(1);
        } else
	{
                msg += CYN "����$n" CYN "С��Ӧ�ԣ�˿�������Ի�����"
                       "Ծ����$N" CYN "�����֡�\n" NOR;
	        me->add("neili", -30);
	        me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}
