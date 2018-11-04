#include <ansi.h>
#include <combat.h>

#define QIAN "��" HIW "ǧ�ƻ�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int attack_time, i;

        if (userp(me) && ! me->query("can_perform/yinyang-zhang/qian"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(QIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(QIAN "ֻ�ܿ���ʩչ��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((int)me->query_skill("yinyang-zhang", 1) < 100)
                return notify_fail("�������Ʋ�����죬����ʩչ" QIAN "��\n");

        if (me->query_skill_prepared("strike") != "yinyang-zhang")
                return notify_fail("��û��׼�������ƣ�����ʩչ" QIAN "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" QIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("strike");
        dp = target->query_skill("dodge");

        msg = HIC "\n$N" HIC "һ����Х������������˫��֮�ϣ�ʩ������"
              "��" HIW "ǧ�ƻ�" HIC "����ɲʱ�䳾��������$N" HIC 
              "˫�Ʋ��ϵ������ĳ����������������˲��Ҵ��⡣\n" NOR;
        message_sort(msg, me, target);
        
	if (random(ap) > dp / 2)
	{
		msg = HIR "���$n" HIR "Ŀ��Ͼ�ӣ���ʱ��$N" HIR "��"
                      "����������ʱ��Ŵ��ҡ�\n" NOR;
                me->add_temp("apply/attack", 60);
        } else
        {
                msg = HIY "$n" HIY "����$N" HIY "�⼸�е���·����"
                      "�ھ��������Ʒ�Ϭ����Ҳֻ��С�ĵֵ���\n" NOR;          
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
        me->add_temp("apply/attack", -50);
	me->start_busy(1 + random(attack_time));

	return 1;
}
