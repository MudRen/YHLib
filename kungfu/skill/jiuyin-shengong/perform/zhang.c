// zhang.c ��������

#include <ansi.h>

inherit F_SSERVER;

#define ZHANG "��" HIM "��������" NOR "��"

int perform(object me, object target)
{
	string msg;
        int ap, dp;
        int i, times, count;

        if (userp(me) && ! me->query("can_perform/jiuyin-shengong/zhang"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail(ZHANG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon"))
                return notify_fail("����ֻ�ܿ���ʩչ��\n");

	if ((int)me->query_skill("jiuyin-shengong", 1) < 260)
		return notify_fail("��ľ����񹦲�����񣬲���ʹ��" ZHANG "��\n");

	if ((int)me->query_skill("strike", 1) < 220)
		return notify_fail("��Ļ����Ʒ���Ϊ����������ʹ��" ZHANG "��\n");

        if (me->query_skill_prepared("unarmed") != "jiuyin-shengong"
           && me->query_skill_prepared("strike") != "jiuyin-shengong")
                return notify_fail("��û��׼��ʹ�þ����񹦣��޷�ʩչ" ZHANG "��\n");

        if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "$N" HIY "˫��һ���û���������Ӱ����������$n"
              HIY "��ȥ��\n" NOR;

        ap = me->query_skill("jiujin-shengong", 1);
        dp = target->query_skill("parry", 1);

        if (ap / 2 + random(ap) > dp)
                count = ap / 7;
 
        else count = 9;

        me->add_temp("apply/attack", count);
        for (i = 0; i < 9; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(2) == 1 && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, 0, );
        }
        me->start_busy(2 + random(4));
        me->add("neili", -320);

        me->add_temp("apply/attack", -count);
	message_combatd(msg, me, target);

	return 1;
}
