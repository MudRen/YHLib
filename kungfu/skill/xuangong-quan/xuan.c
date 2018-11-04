#include <ansi.h>
#include <combat.h>

#define XUAN "��" HIW "�����޼���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, ap, dp, damage;
	string msg;

        if (userp(me) && ! me->query("can_perform/xuangong-quan/xuan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(XUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(XUAN "ֻ�ܿ���ʩչ��\n");

        skill = me->query_skill("xuangong-quan", 1);

        if (skill < 120)
                return notify_fail("����޼�����ȭ�ȼ�����������ʩչ" XUAN "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����������������ʩչ" XUAN "��\n");
 
        if (me->query_skill_mapped("unarmed") != "xuangong-quan")
                return notify_fail("��û�м����޼�����ȭ������ʩչ" XUAN "��\n");

        if (me->query_skill_prepared("unarmed") != "xuangong-quan")
                return notify_fail("������û��׼��ʹ���޼�����ȭ���޷�ʹ��" XUAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "ֻ��$N" HIW "˫�ֻ�Ȧ����������������������$n"
              HIW "�Ծ��䣬$P" HIW "˫ȭ�Ѷ�Ȼ�ƿչ����\n" NOR;
	me->add("neili", -100);

	if (random(me->query_skill("force")) > target->query_skill("force") / 2)
	{
		me->start_busy(3);
		target->start_busy(random(3));
		
		damage = (int)me->query_skill("xuangong-quan", 1);
                damage = damage + random(damage);
		
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 60,
                                           HIR "$n" HIR "��æ�����ܣ�����Ȼ��������$N"
                                           HIR "˫ȭ�������С�\n:����@?");
	} else 
	{
		me->start_busy(3);
		msg += CYN "����$p" CYN "������$P"
                       CYN "����ͼ����û���ϵ���\n" NOR;
	}
	message_combatd(msg, me, target);
	return 1;
}
