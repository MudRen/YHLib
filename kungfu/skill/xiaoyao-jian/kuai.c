#include <ansi.h>
#include <combat.h>

#define LIAN "��" HIM "�콣��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
        int i, attack_time;

        if (userp(me) && ! me->query("can_perform/xiaoyao-jian/kuai"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
                return notify_fail(LIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" LIAN "��\n");

	if ((int)me->query_skill("xiaoyao-jian", 1) < 120)
		return notify_fail("�����ң����������죬����ʩչ" LIAN "��\n");

        if (me->query_skill_mapped("sword") != "xiaoyao-jian")
                return notify_fail("��û�м�����ң����������ʩչ" LIAN "��\n");

	if (me->query("neili") < 300)
		return notify_fail("��Ŀǰ����������������ʩչ" LIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "\n$N" HIW "���һ����Х��ʩ����ѧ��" HIM "�콣��"
              HIW "��������" + weapon->name() + HIW "�������졣��ʱ��"
              "����Ľ�������ӿ����" NOR;

        attack_time = 4;

	ap = me->query_skill("sword");
	dp = target->query_skill("dodge");

        attack_time += random(ap / 40);

        if (attack_time > 9)
                attack_time = 9;

	me->add("neili", -attack_time * 30);
        me->add_temp("apply/attack", 20);

        message_combatd(msg, me, target);

        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (! target->is_busy() && random(3) == 1)
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, weapon, 0);
        }

	me->start_busy(1 + random(attack_time));
        me->add_temp("apply/attack", -20);

        return 1;
}
