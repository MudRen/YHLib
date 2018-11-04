#include <ansi.h>
#include <combat.h>

#define WANG "��" HIY "Ϭţ����ת�ػ�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/tan-tui/wang"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
                return notify_fail(WANG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(WANG "ֻ�ܿ���ʩչ��\n");

        if (me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻹�������ʩչ" WANG "��\n");

        if ((int)me->query_skill("tan-tui", 1) < 120)
                return notify_fail("���ʮ��·̶�Ȳ�����죬����ʩչ" WANG "��\n");

        if (me->query_skill_mapped("unarmed") != "tan-tui")
                return notify_fail("��û�м���ʮ��·̶�ȣ�����ʩչ" WANG "��\n");

        if (me->query_skill_prepared("unarmed") != "tan-tui")
                return notify_fail("��û��׼��ʮ��·̶�ȣ�����ʩչ" WANG "��\n");

        if (me->query("neili") < 300)
                return notify_fail("�����������������ʩչ" WANG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "ֻ��$N" HIY "�ε�Ծ�����һ����������Ȼ��˫�ȱ���"
              "���ǰ���$n" HIY "����������\n" NOR;

	me->add("neili", -50);
        ap = me->query_skill("unarmed");
        dp = target->query_skill("force");
        if (ap / 2 + random(ap) > dp)
	{
		damage = me->query_skill("unarmed") / 2;
                damage += random(damage / 3);
		me->add("neili", -100);

                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 35,
                                           HIR "ȴ��$n" HIR "һ���Һ����ѱ�$P" HIR
                                           "��������ǰ�أ���ʱ�����������һ��"
                                           "����Ѫ��\n" NOR);
		me->start_busy(3);
	} else
	{
		msg += CYN "����$p" CYN "�����мܣ����ڽ�$P"
                       CYN "��˫�ȼܿ���û���ܵ��κ��˺���\n"NOR;
		me->start_busy(4);
	}
	message_combatd(msg, me, target);

	return 1;
}
