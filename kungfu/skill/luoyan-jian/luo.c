#include <ansi.h>
#include <combat.h>

#define LUO "��" HIR "һ�������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
        int i, count;

        if (userp(me) && ! me->query("can_perform/luoyan-jian/luo"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
                return notify_fail(LUO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" LUO "��\n");

	if ((int)me->query_skill("luoyan-jian", 1) < 150)
		return notify_fail("��Ļط����㽣������죬����ʩչ" LUO "��\n");

        if (me->query_skill_mapped("sword") != "luoyan-jian")
                return notify_fail("��û�м����ط����㽣��������ʩչ" LUO "��\n");

	if (me->query("neili") < 400)
		return notify_fail("��Ŀǰ����������������ʩչ" LUO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "\n$N" HIW "���һ����Х��ʩ����ɽ�ɾ�ѧ��" HIR "һ�������"
              HIW "��������" + weapon->name() + HIW "��⵴������ʱ��ط�"
              "���㽣��������ӿ����������������������$n" HIW "�ķ���" NOR;

        message_sort(msg, me, target);

	ap = me->query_skill("sword");
	dp = target->query_skill("dodge");

	if (ap / 2 + random(ap) > dp)
	{
		msg = HIY "$n" HIY "��$P" HIY "������ӿ�������������"
                      "���Ƶ��������ˣ��Ǳ����ѡ�\n" NOR;
                count = me->query_skill("luoyan-jian") / 40;
        } else
        {
                msg = HIC "$n" HIC "��$N" HIC "�⼸������Ѹ���ޱȣ���"
                      "��������ֻ��С��Ӧ����\n" NOR;
                count = 0;
        }
        message_combatd(msg, me, target);

        me->add("neili", -200);
        me->add_temp("apply/attack", count);

        for (i = 0; i < 9; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -count);
        me->start_busy(1 + random(9));
        return 1;
}
