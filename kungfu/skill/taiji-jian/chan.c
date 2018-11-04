#include <ansi.h>
#include <combat.h>

#define CHAN "��" HIC "���־�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int level;
	string msg;

        if (userp(me) && ! me->query("can_perform/taiji-jian/chan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail(CHAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԣ�����ʩչ" CHAN "��\n");

	if (target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");
		
	if ((level = me->query_skill("taiji-jian", 1)) < 80)
		return notify_fail("���̫������������죬����ʩչ" CHAN "��\n");

        if (me->query_skill_mapped("sword") != "taiji-jian")
                return notify_fail("��û�м���̫������������ʩչ" CHAN "��\n");

        if (me->query("neili") < 60)
                return notify_fail("��������������������ʩչ" CHAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "ʹ��̫�������������־�������Ȧת�����಻������"
              "������������ͼ����$n" HIC "�Ĺ��ơ�\n" NOR;

        me->add("neili", -30);
        if (random(level) > (int)target->query_skill("parry", 1) / 2)
        {
		msg += HIR "���$p" HIR "��$P" HIR "�ָ���æ���ң�"
                       "����ʧ�룬���ڵ�������֪���Ӧ�ԣ�\n" NOR;
		target->start_busy(level / 16 + 2);
	} else
        {
		msg += CYN "����$p" CYN "������$P" CYN "����ͼ����"
                       "����㣬ȫ��Ӧ�����硣\n" NOR;
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}
