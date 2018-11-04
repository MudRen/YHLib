// sanshen.c ���������

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define SAN "��" HIG "���������" NOR "��"
 
int perform(object me, object target)
{
	object weapon;
	string msg;
	int i, damage;
        int ap, dp;
 
        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/fanliangyi-dao/san"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
		return notify_fail(SAN "ֻ����ս���жԶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query("max_neili") < 1800)
		return notify_fail("���������Ϊ�������޷�ʩչ" SAN "��\n");

	if ((int)me->query("neili") < 320)
		return notify_fail("�������������\n");

	if ((int)me->query_skill("fanliangyi-dao", 1) < 100)
		return notify_fail("�㷴���ǵ�������㣬�޷�ʩչ" SAN "\n");

	if ((int)me->query_skill("force", 1) < 140)
		return notify_fail("����ڹ���Ϊ���㣬�޷�ʩչ" SAN "\n");

	if (me->query_skill_mapped("blade") != "fanliangyi-dao")
		return notify_fail("�㻹û�м��������ǵ������޷�ʩչ" SAN "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "\n$N" HIY "ʹ����ɽ�ɾ�����" HIG "���������" HIY "������"
              "��ͻȻ����쳣�鶯Ʈ��������" + weapon->name() + HIY "������"
              "��$n" HIY "��" NOR; 
	message_sort(msg, me, target);

        msg = HIW "$N" HIW "��ת" + weapon->name() + HIW "����Ȼһ���������������\n" NOR;
        
        ap = me->query_skill("blade");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) < dp)
                msg += CYN "$n" CYN "����һ�����������С�\n" NOR;
        else
        {
                damage = ap / 2 + random(ap / 2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
                                           HIR "$n" HIR "��ܲ�������$N"
                                           HIR "�⵶���м����Ѫֱ����\n" NOR);
        }

        msg += HIW "\n$N" HIW "��ת" + weapon->name() + HIW "���͵ش���ǰ��ֱϮ$n" HIW "���̡�\n" NOR;
        if (ap / 2 + random(ap) < dp)
                msg += CYN "$n" CYN "������𣬶����һ�С�\n" NOR;
        else
        {
                damage = ap / 2+ random(ap / 2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 60,
                                           HIR "$n"HIR "���ܲ����������ѱ�$N" HIR "����Ѫ��ģ����\n" NOR);
        }

        msg += HIW "\n$N" HIW "����Ծ������" + weapon->name() + HIW "������£�����$n" HIW "��\n" NOR;
        if (ap / 2 + random(ap) < dp)
                msg += CYN "$n" CYN "һ���죬������һ������������С�\n" NOR;
        else
        {
                damage = ap + random(ap / 2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 70,
                                           HIR "$n" HIR "����ԥ�������⻮������Ѫ��Ⱦ��������\n" NOR);
        }

        me->start_busy(3);
        message_combatd(msg, me, target);
        return 1;
}
