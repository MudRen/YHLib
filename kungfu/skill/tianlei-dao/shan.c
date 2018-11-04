#include <ansi.h>
#include <combat.h>

#define SHAN "��" HIW "��������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg, wn;
	int ap, dp;
        int i, attack_time;

        if (userp(me) && ! me->query("can_perform/tianlei-dao/shan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԣ�����ʩչ" SHAN "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((int)me->query_skill("tianlei-dao", 1) < 150)
                return notify_fail("�����׾���������죬����ʩչ" SHAN "��\n");

        if (me->query_skill_mapped("blade") != "tianlei-dao")
                return notify_fail("��û�м������׾���������ʩչ" SHAN "��\n");

        if (me->query_skill("dodge") < 180)
                return notify_fail("����Ṧ��Ϊ����������ʩչ" SHAN "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�����ڵ���������������ʩչ" SHAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

 
        wn = weapon->name();

	msg = HIY "\n$N" HIY "������" + wn + HIY "������ǰ��ʩ�����С�" HIW "��"
              "������" HIY "����$N����Ȼ�ӿ죬����" + wn + HIY "���������嵶��"
              "����֮������˷�����˼��\n" NOR;

        message_sort(msg, me, target);

        attack_time = 5;

	ap = me->query_skill("blade");
	dp = target->query_skill("dodge");

	me->add("neili", -180);

	if (ap / 2 + random(ap) > dp)
	{
		msg = HIG "$n" HIG "��$P" HIG "����������ӿ���Ʋ���"
                     "������$N" HIG "�����������ˡ�\n" NOR;
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

                COMBAT_D->do_attack(me, target, weapon, 15);
        }

	me->start_busy(1 + random(attack_time));

        return 1;
}
