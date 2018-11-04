#include <ansi.h>
#include <combat.h>

#define PO "��" HIR "������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg, wp;
        int ap, dp, damage;

        if (userp(me) && ! me->query("can_perform/riyue-lun/po"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target ) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail(PO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_temp("yuan_man"))
                return notify_fail("��������Ͼʩչ" PO "��\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "hammer")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" PO "��\n");

        if (me->query_skill_mapped("hammer") != "riyue-lun")
                return notify_fail("��û�м��������ַ�������ʩչ" PO "��\n");

        if (me->query_skill_mapped("force") != "longxiang-gong")
                return notify_fail("��û�м������������������ʩչ" PO "��\n");

        if ((int)me->query_skill("riyue-lun", 1) < 120)
                return notify_fail("��������ַ�����㣬����ʩչ" PO "��\n");

        if ((int)me->query_skill("force") < 180)
                return notify_fail("����ڹ�����㣬����ʩչ" PO "��\n");

        if ((int)me->query("max_neili") < 1500)
                return notify_fail("���������Ϊ���㣬����ʩչ" PO "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����ڵ��������㣬����ʩչ" PO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wp = weapon->name();

	msg = HIY "$N" HIY "���ָ߾�" + wp + HIY "������$n" HIY "���£���"
              "�˵���ȫȻ��$n" HIY "�������У�\n" NOR;

	ap = me->query("force") + me->query("str") * 10;
	dp = target->query("force") + target->query("con") * 10;

	if (ap / 2 + random(ap) > dp)
	{
		me->add("neili", -300);
		damage = ap / 2 + random(ap / 2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
                                           HIR "$n" HIR "��$N" HIR "��ǿ���ޱȵ�"
                                           "�ھ��������ҡ�һΣ��������У�������"
                                           "Ѫ��\n" NOR);
		me->start_busy(3);

	} else
	{
		msg += CYN "ȴ��$p" CYN "�벻���⣬����һ���Ͷ����$P"
		       CYN "���׺�������\n"NOR;
		me->add("neili", -150);
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}
