#include <ansi.h>
#include <combat.h>

#define DING "��" HIY "�����߷�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int i, ap, dp;

        if (userp(me) && ! me->query("can_perform/zhongping-qiang/ding"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
                return notify_fail(DING "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "club")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" DING "��\n");

        if ((int)me->query_skill("zhongping-qiang", 1) < 120)
                return notify_fail("����ƽǹ��������죬����ʩչ" DING "��\n");

        if (me->query_skill_mapped("club") != "zhongping-qiang")
                return notify_fail("��û�м�����ƽǹ��������ʩչ" DING "��\n");

        if ((int)me->query_skill("force") < 180 )
                return notify_fail("����ڹ���򲻹�������ʩչ" DING "��\n");

        if ((int)me->query("max_neili") < 2000)
                return notify_fail("���������Ϊ����������ʩչ" DING "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" DING "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "$N" HIY "����һת��ʩ����ƽǹ��������" HIR "�����߷�"
              HIY "��������" + weapon->name() + HIY "�����ߴ̣�ǹǹ����"
             "$n" HIY "Ҫ����\n" NOR;

	ap = me->query_skill("club");
	dp = target->query_skill("parry");

	if (ap / 2 + random(ap * 2) > dp)
	{
		msg += HIR "$n" HIR "��$N" HIR "���������쳣��ʵ��"
                       "Ѱ���������������⣬�мܵ�ʱɢ�ҡ�\n" NOR;
        } else
        {
                msg += HIC "$n" HIC "��$N" HIC "���������쳣��ʵ��"
                       "Ѱ������æ������С��Ӧ��������\n" NOR;
        }
	message_combatd(msg, me, target);

	me->add("neili", -7 * 20);

	for (i = 0; i < 7; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}
	me->start_busy(1 + random(7));

	return 1;
}
