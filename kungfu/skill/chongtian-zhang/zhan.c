#include <ansi.h>
#include <combat.h>

#define ZHAN "��" HIW "��չ����" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/chongtian-zhang/zhan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
                return notify_fail(ZHAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(ZHAN "ֻ�ܿ���ʩչ��\n");

        if (me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻹�������ʩչ" ZHAN "��\n");

        if ((int)me->query_skill("chongtian-zhang", 1) < 120)
                return notify_fail("��İ׺׳����Ʋ�����죬����ʩչ" ZHAN "��\n");

        if (me->query_skill_mapped("strike") != "chongtian-zhang")
                return notify_fail("��û�м����׺׳����ƣ�����ʩչ" ZHAN "��\n");

        if (me->query_skill_prepared("strike") != "chongtian-zhang")
                return notify_fail("��û��׼���׺׳����ƣ�����ʩչ" ZHAN "��\n");

        if (me->query("neili") < 300)
                return notify_fail("�����������������ʩչ" ZHAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "$N" HIW "˫�����ţ���Ե΢΢����������һչ��������$n"
              HIW "��ǰ��˫�ƽ���������£�����\n�׺׳����ơ���չ���ݡ�"
              "�����������ж�ʱ�����һ�������ƿ�����\n" NOR;

	me->add("neili", -50);
        ap = me->query_skill("strike");
        dp = target->query_skill("force");
        if (ap / 2 + random(ap) > dp)
	{
		damage = me->query_skill("strike") * 3 / 5;
                damage += random(damage / 3);
		me->add("neili", -100);

                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30,
                                           HIR "$n" HIR "�������ã�ֻ��Ӳ����˫��"
                                           "����ʱ��$P" HIR "˫�ƿ���˫�����࣬��"
                                           "Ѫ��ֹ��\n" NOR);
		me->start_busy(3);
	} else
	{
		msg += CYN "����$p" CYN "�����мܣ����ڽ�$P"
                       CYN "��˫�Ƽܿ���û���ܵ��κ��˺���\n"NOR;
		me->start_busy(4);
	}
	message_combatd(msg, me, target);

	return 1;
}
