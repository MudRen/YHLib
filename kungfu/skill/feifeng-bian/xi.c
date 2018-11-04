#include <ansi.h>
#include <combat.h>

#define XI "��" HIW "��������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int i;

        if (userp(me) && ! me->query("can_perform/feifeng-bian/xi"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(XI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" XI "��\n");

	if ((int)me->query_skill("feifeng-bian", 1) < 120)
		return notify_fail("��ķɷ�޷���������죬����ʩչ" XI "��\n");

        if (me->query_skill_mapped("whip") != "feifeng-bian")
                return notify_fail("������û�м����ɷ�޷�������ʩչ" XI "��\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("����ڹ���Ϊ����������ʩչ" XI "��\n");

	if ((int)me->query("neili") < 300)
		return notify_fail("�����ڵ���������������ʩչ" XI "��\n");
	
        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "������ң�����" + weapon->name() + HIW "���裬��"
              "��һ����һ����Ȧ�Ӳ���$n" HIW "��\n" NOR;
        message_combatd(msg, me, target);

        me->add("neili", -100);

        for (i = 0; i < 6; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(5) == 0 && ! target->is_busy())
                        target->start_busy(1);
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->start_busy(1 + random(6));
        return 1;
}
