#include <ansi.h>
#include <combat.h>

#define QIAN "��" HIG "ǧɽ�º�Ӱ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int attack_time, i;

        if (userp(me) && ! me->query("can_perform/guhong-zhang/qian"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(QIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(QIAN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("guhong-zhang", 1) < 80)
                return notify_fail("��º��Ʒ�������죬����ʩչ" QIAN "��\n");

        if (me->query_skill_mapped("strike") != "guhong-zhang")
                return notify_fail("��û�м����º��Ʒ�������ʩչ" QIAN "��\n");

        if (me->query_skill_prepared("strike") != "guhong-zhang")
                return notify_fail("��û��׼���º��Ʒ�������ʩչ" QIAN "��\n");

        if (me->query_skill("force") < 100)
                return notify_fail("����ڹ���Ϊ����������ʩչ" QIAN "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" QIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("strike");
        dp = target->query_skill("parry");

        msg = HIC "\n$N" HIC "˫�ƶ�Ȼ�����ĳ������д��ᣬһ��"
              "��" HIG "ǧɽ�º�Ӱ" HIC "����˫�ƴ��磬�ѽ�$n" 
              HIC "�������Ʒ�֮�С�\n" NOR;
        message_sort(msg, me, target);

	if (random(ap) > dp / 2)
	{
		msg = HIR "���$n" HIR "Ŀ��Ͼ�ӣ���ʱ��$N" HIR "��"
                      "����������ʱ��Ŵ��ҡ�\n" NOR;
                me->add_temp("apply/attack", 10);
        } else
        {
                msg = HIY "$n" HIY "����$N" HIY "�⼸�е���·����"
                      "�ھ����������Ტ�ã�Ҳֻ��С�ĵֵ���\n" NOR;          
        }
	message_vision(msg, me, target);

        attack_time += 3 + random(ap / 40);

        if (attack_time > 6)
                attack_time = 6;

	me->add("neili", -attack_time * 20);

	for (i = 0; i < attack_time; i++)
	{
		if (! me->is_fighting(target))
			break;
                COMBAT_D->do_attack(me, target, 0, 0);
	}
	me->start_busy(1 + random(attack_time));
        me->add_temp("apply/attack", -10);

	return 1;
}
