// suck.c

#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
	int sp, dp;
	int my_max, tg_max;
        int amount;
        object weapon;

	if (! target || target == me) target = offensive_target(me);

	if (environment(me)->query("no_fight"))
		return notify_fail("�����ﲻ�ܹ������ˡ�\n");

	if (! objectp(target) || ! me->is_fighting(target))
		return notify_fail("��ֻ����ȡս���еĶ��ֵĵ�Ԫ��\n");

        if (target->query("race") != "����" ||
            target->query("not_living"))
                return notify_fail("����ˣ�ֻ�л��ŵ���������е�Ԫ��\n");

        my_max = me->query("max_neili");
        tg_max = target->query("max_neili");

	if (me->query_temp("sucked"))
		return notify_fail("��ո���ȡ����Ԫ��\n");

        if (! me->is_fighting() || ! target->is_fighting())

	if ((int)me->query_skill("xixing-dafa", 1) < 200)
		return notify_fail("������Ǵ���δ��ɣ���"
                                   "������ȡ�Է��ĵ�Ԫ��Ϊ���ã�\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("�����������������ʹ�����Ǵ󷨡�\n");

        if ((int)me->query_current_neili_limit() <= my_max)
                return notify_fail("����ڹ�ˮƽ���ޣ�����ȡҲ��ͽ�͡�\n");

	if ((int)target->query("max_neili") < 100)
		return notify_fail( target->name() +
			"��Ԫ��ɢ������δ�ۣ����޷�����������ȡ�κζ�����\n");

        if ((int)target->query("max_neili") < (int)me->query("max_neili") / 5)
		return notify_fail( target->name() +
			"���ڹ���ΪԶ�����㣬���޷�����������ȡ��Ԫ��\n");

        if (! objectp(weapon = me->query_temp("weapon")))
        	message_combatd(HIR "$N" HIR "̽�����֣�ƽƽ������$n"
                                HIR "����ǰ���ƺ�û�а��������\n\n" NOR,
                                me, target);
        else
                message_combatd(HIR "$N" HIR "�����е�" + weapon->name() +
                                HIR "һ������ı���$n" HIR + "��$p"
                                HIR "��æ��ס��\n" NOR,
                                me, target);

        if (target->query_skill_mapped("force") == "taixuan-gong")
        {
                tell_object(target, HIW + me->name() + HIW "������֣��������������"
                             "���ϣ���ͼ��ȡ������������������ڵ�̫�������͵ؽ�"
                             "�䷴����ȥ��\n");

                return notify_fail(HIG "��������֣���������" + target->name() +
                                   HIG "���ֱ��ϣ�ȴ�͵ĸо�һ���ھ�������ֵ��ء�\n" NOR);
        }

        if (living(target) && !target->is_killing(me))
        {
                me->want_kill(target);
                target->kill_ob(me);
        }

        sp = me->query_skill("force");
        dp = target->query_skill("force");

	me->set_temp("sucked", 1);

        if ((sp + random(sp) > dp + random(dp) ) || ! living(target))
	{
		tell_object(target, HIR "��ֻ��ȫ������ȫ������"
			    "��ѩ����ʧ����Ӱ���٣�\n" NOR);
		tell_object(me, HIG "�����" + target->name() +
			    HIG "�ĵ�Ԫ������ԴԴ���������˽�����\n" NOR);

                amount = 1 + (me->query_skill("xixing-dafa", 1) - 120) / 10;
                target->add("max_neili", -amount);
                me->add("max_neili", amount);
                me->add("exception/xixing-count", amount * 10);
                SKILL_D("xixing-dafa")->check_count(me);
                if (target->query("max_neili") < 1)
			target->set("max_neili", 0);

                me->start_busy(4 + random(4));
                if (! target->is_busy()) target->start_busy(2);
                me->add("neili", -10);

		call_out("del_sucked", 10, me);
	} else
	{	
		message_combatd(HIY "����$p" HIY "������$P" HIY
                                "����ͼ��������������$P" HIY
                                "���漴���˿�ȥ��\n" NOR,
                                me, target);
                me->start_busy(7);
		call_out("del_sucked", 20, me);
	}

	return 1;
}

void del_sucked(object me)
{
        me->delete_temp("sucked");
}
