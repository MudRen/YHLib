// juan.c ���־�

#include <ansi.h>

inherit F_SSERVER;

#define JUAN "��" HIW "���־�" NOR "��"

int perform(object me, object target)
{
        object weapon;
        int damage;
	int ap, dp;
        string msg;

        if (userp(me) && ! me->query("can_perform/xuantie-jian/juan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query_skill("xuantie-jian", 1) < 100)
                return notify_fail("�����������������죬����ʹ��" JUAN "��\n");

        if ((int)me->query_skill("force") < 400)
                return notify_fail("����ڹ���򲻹�������ʹ��" JUAN "��\n");

        if ((int)me->query("neili") < 100 )
                return notify_fail("����������̫��������ʹ��" JUAN "��\n");

        if (me->query_skill_mapped("sword") != "xuantie-jian")
                return notify_fail("��û�м�����������������ʩչ" JUAN "��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$Nһ�����е�" + weapon->name() + HIY "�����¶��ϵĳ�$n"
	      HIY "���˹�ȥ���������ۣ��仯�޳���\n" NOR;

	ap = me->query_skill("sword");
	dp = target->query_skill("dodge");
        if (random(ap) > dp / 2)
        {
                target->start_busy(ap / 20 + 2);
                me->add("neili", -50);
                msg += YEL "$p" YEL "��æ�����мܣ�һʱ��Ͼ������\n" NOR;
        } else
        {
                msg += CYN "����$p" CYN "������$P" CYN "����ͼ��бԾ�ܿ���$P"
                       CYN "�Ĺ�����\n"NOR;
		me->add("neili", -25);
        	me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}
