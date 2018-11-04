#include <ansi.h>
#include <combat.h>

#define SHAN "��" HIW "������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/liuhe-dao/shan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" SHAN "��\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���򲻹�������ʩչ" SHAN "��\n");

        if ((int)me->query_skill("liuhe-dao", 1) < 80)
                return notify_fail("������ϵ����������ң�����ʩչ" SHAN "��\n");

        if (me->query_skill_mapped("blade") != "liuhe-dao")
                return notify_fail("��û�м������ϵ���������ʩչ" SHAN "��\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("�����������������ʩչ" SHAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "$N" HIW "���е�" + weapon->name() +  HIW "���²���������"
              "�任�����ַ�λ��������һ����$n" HIW "���䣡\n" NOR;

        ap = me->query_skill("blade");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
	{
		damage = ap / 2 + random(ap / 2);
                me->add("neili", -100);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 35,
                                           HIR "ֻ��$n" HIR "�мܲ�������ʱ��$N"
                                           HIR "��һ������Ҫ�����˿ڼ��ǣ���Ѫ�񽦣�\n" NOR);
		me->start_busy(2);
	} else 
	{
		msg += CYN "����$p" CYN "�����������ס�Ż�������$P"
                       CYN "�������У�ʼ���κβ��á�\n" NOR;
                me->add("neili", -50);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}
