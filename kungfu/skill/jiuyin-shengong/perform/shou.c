// shou.c ��������

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define SHOU  "��" HIG "��������" NOR "��"
 
int perform(object me, object target)
{
	string msg;
        int ap, dp, ap1, dp1, damage;

        if (userp(me) && ! me->query("can_perform/jiuyin-shengong/shou"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");
 
	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
	        return notify_fail(SHOU "ֻ����ս���жԶ���ʹ�á�\n");

        if (me->query_temp("weapon"))
                return notify_fail("����ֻ�ܿ���ʩչ��\n");

	if (me->query_skill("jiuyin-shengong", 1) < 260)
		return notify_fail("��ľ����񹦻�������죬����ʹ��" SHOU "��\n");

	if (me->query("neili") < 300)
		return notify_fail("�������������\n");

        if (me->query_skill_prepared("hand") != "jiuyin-shengong"
           && me->query_skill_prepared("unarmed") != "jiuyin-shengong")
                return notify_fail("��û��׼��ʹ�þ����񹦣��޷�ʩչ" SHOU "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "��������һ���³���һ��������ʽ���أ�������ı���$n"
              HIY "��ҪѨ��\n";

        ap = me->query_skill("jiuyin-shengong");
        dp = target->query("combat_exp") / 10000;
	me->add("neili", -60);
	me->start_busy(1 + random(3));

	me->want_kill(target);

        if (dp >= 100) // ���ж԰��������ϵ�����Ч
        { // ������Ȼ�ܵ��˺�

                ap1 = me->query_skill("jiuyin-shengong", 1) + me->query_skill("force", 1);
                dp1 = target->query_skill("parry", 1) + target->query_skill("dodge", 1); 
                damage = ap1 + random(ap1);
                if (ap1 / 2 + random(ap1) > dp1)
                {
                         msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 90,
                                                    HIR "$n" HIR "ֻ�����У������ޱȣ�����Ī�⣬"
                                                    "����һ����ȴ��Ȼ�����һ������͸�Ƕ�����\n" NOR);
                         me->add("neili", -140);
                }
                      
                else
                         msg += HIC "$n" HIC "֪�����в��ƣ�С��Ӧ�ԣ�û��һ����\n" NOR;
                message_combatd(msg, me, target);
                target->start_busy(1 + random(2));
                return 1;
        } else
        if (random(ap) > dp)
        {
                msg += HIR "��һ����ȫ������$n" HIR "�����󣬱�$N"
                       HIR "���ʵʵ�Ĵ�����̴�д�Ѩ������������ʱ��ɢ��\n" NOR;
                message_combatd(msg, me, target);
                me->add("neili", -200);
                target->die(me);
                return 1;
        } else
        {
                msg += HIM "$n" HIM "���һ������æ���ҵֵ�����"
                      "Ȼû��һ���˺������ҵ��ѣ�\n" NOR;
        }

        message_combatd(msg, me, target);

	return 1;
}
