// modify by rcwiz 2003

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define SONG "��" HIG "����ʽ" NOR "��"

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
        int ap, dp;

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

        if (userp(me) && ! me->query("can_perform/huashan-quan/song"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target || ! me->is_fighting(target))
		return notify_fail(SONG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if ((int)me->query_skill("huashan-quan", 1) < 40)
		return notify_fail("��Ļ�ɽȭ��������죬�޷�ʩչ" SONG "��\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("�����������������޷�ʩչ" SONG "��\n");

        if (me->query_skill_prepared("cuff") != "huashan-quan")
                return notify_fail("��û��׼��ʹ����ʯ����ȭ���޷�ʩչ" SONG "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "$N" HIY "ŭ��һ������ȭֱ�����������������ǻ�ɽ������" HIG "����ʽ" HIY
               "����ȭ����죬Ϯ��$n" HIY "��\n"NOR;

        ap = me->query_skill("cuff") + me->query_str() * 10;
        dp = target->query_skill("force") + target->query_str() * 10;
	if (ap / 2 + random(ap) > dp)
	{
		damage = ap / 3 + random(ap / 3);

                me->add("neili", -60);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30,
		                           HIR "ֻ��$P" HIR "һȭֱ����$p" HIR
                                           "��������ȴ�Ѳ�����һȭ���صش������ϣ�\n" NOR);
		me->start_busy(2);
	} else 
	{
		msg += HIC "����$p" HIC "�����мܣ�Ӳ�����ĵ�����$P"
                       HIC "��һ�С�\n"NOR;
		me->add("neili", -50);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}
