#include <ansi.h>
#include <combat.h>

#define XUE "��" HIW "�ͷ�ѩ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
        int i, attack_time;

        if (userp(me) && ! me->query("can_perform/ningxue-zhang/xue"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
                return notify_fail(XUE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "staff")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" XUE "��\n");

	if ((int)me->query_skill("ningxue-zhang", 1) < 50)
		return notify_fail("�����ѩ�ȷ�������죬����ʩչ" XUE "��\n");

        if (me->query_skill_mapped("staff") != "ningxue-zhang")
                return notify_fail("��û�м�����ѩ�ȷ�������ʩչ" XUE "��\n");

	if (me->query("neili") < 200)
		return notify_fail("��Ŀǰ����������������ʩչ" XUE "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "\n$N" HIC "���һ����Х��ʩ����ѧ��" HIM "�ͷ�ѩ��"
              HIC "��������" + weapon->name() + HIC "�������졣��ʱ��"
              "��������$n" HIC "��" NOR;

        message_sort(msg, me, target);

        attack_time = 4;

	ap = me->query_skill("sword");
	dp = target->query_skill("dodge");

        attack_time += random(ap / 40);

        if (attack_time > 6)
                attack_time = 6;

	me->add("neili", -attack_time * 20);

        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;

                COMBAT_D->do_attack(me, target, weapon, 0);
        }

	me->start_busy(1 + random(attack_time));

        return 1;
}
