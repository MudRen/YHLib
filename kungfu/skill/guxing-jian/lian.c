#include <ansi.h>
#include <combat.h>

#define LIAN "��" HIM "��������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
        int i, attack_time;

        if (userp(me) && ! me->query("can_perform/guxing-jian/lian"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
                return notify_fail(LIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" LIAN "��\n");

	if ((int)me->query_skill("guxing-jian", 1) < 100)
		return notify_fail("��Ĺ��ǽ���������죬����ʩչ" LIAN "��\n");

        if (me->query_skill_mapped("sword") != "guxing-jian")
                return notify_fail("��û�м������ǽ���������ʩչ" LIAN "��\n");

	if (me->query("neili") < 300)
		return notify_fail("��Ŀǰ����������������ʩչ" LIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "\n$N" HIW "���һ����Х��ʩ����ѧ��" HIM "��������"
              HIW "��������" + weapon->name() + HIW "�������졣��ʱ��"
              "���ǽ�����������ӿ��������˷�����������$n" HIW "ȫ��" NOR;

        message_sort(msg, me, target);

        attack_time = 4;

	ap = me->query_skill("sword");
	dp = target->query_skill("dodge");

        attack_time += random(ap / 40);

        if (attack_time > 8)
                attack_time = 8;

	me->add("neili", -attack_time * 20);

	if (ap / 2 + random(ap) > dp)
	{
		msg = HIY "$n" HIY "��$P" HIY "������ӿ�������������"
                      "���Ƶ��������ˣ��Ǳ����ѡ�\n" NOR;
        } else
        {
                msg = HIC "$n" HIC "��$N" HIC "�⼸������Ѹ���ޱȣ���"
                      "��������ֻ��С��Ӧ����\n" NOR;
        }

        message_combatd(msg, me, target);

        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;

                COMBAT_D->do_attack(me, target, weapon, 0);
        }

	me->start_busy(1 + random(attack_time));

        return 1;
}
