#include <ansi.h>
#include <combat.h>

#define BAN "��" HIG "���־�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
        int ap, dp, damage, level;

        if (userp(me) && ! me->query("can_perform/dagou-bang/ban"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(BAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "staff")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" BAN "��\n");

        level = me->query_skill("dagou-bang", 1);

        if (level < 180)
		return notify_fail("��򹷰���������죬����ʩչ" BAN "��\n");

        if (me->query_skill_mapped("staff") != "dagou-bang")
                return notify_fail("��û�м����򹷰���������ʩչ" BAN "��\n");

	if ((int)me->query_skill("force") < 240)
		return notify_fail("����ڹ�����㣬����ʩչ" BAN "��\n");

        if (me->query("neili") < 300)
                return notify_fail("�����ڵ���������������ʩչ" BAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIG "$N" HIG "ʹ���򹷰�����" NOR + WHT "��"
              HIG "���־�������" + weapon->query("name") +
              HIG "����ұƣ�������$n" HIG "��ȥ��\n" NOR;

        ap = me->query_skill("staff") +
             me->query_skill("martial-cognize") / 2 +
             me->query("int") * 10;

        dp = target->query_skill("dodge") +
             target->query_skill("martial-cognize") / 2 +
             target->query("dex") * 10;

        if (me->query("max_neili") > target->query("max_neili") * 2)
        {
                msg += HIR "$n" HIR "ȫ��һ�������㲻�ȣ���$N"
                       HIR "���л��÷������صĵ����ڵ��ϡ�\n" NOR;

                me->add("neili", -50);
                me->start_busy(1);

                message_combatd(msg, me, target);

                target->set("eff_qi", 1);
                target->set("eff_jing", 1);
                target->unconcious(me);
                return 1;
        } else
        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 70,
                                           HIR "ֻ��$n" HIR "С�ȴ������͡�������"
                                           "�죬����$N" HIR "��" + weapon->name() +
                                           HIR "�������Ѫ����\n" NOR);
                me->start_busy(3);
                me->add("neili", -200);
        } else
        {
                msg += CYN "��$n" CYN "ȫ���������¶���������ʹ��$N"
                       CYN "�����޹�������\n" NOR;
                me->start_busy(4);
                me->add("neili", -100);
        }
        message_combatd(msg, me, target);

	return 1;
}
