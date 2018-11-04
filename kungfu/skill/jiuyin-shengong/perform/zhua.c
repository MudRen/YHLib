// zhua.c ������ץ

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define ZHUA "��" HIR "������צ" NOR "��"

int perform(object me, object target)
{
	int damage;
	string  msg;
        string  pmsg;
        string *limbs;
        string  limb;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/jiuyin-shengong/zhua"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail(ZHUA "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon"))
                return notify_fail(ZHUA "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("jiuyin-shengong", 1) < 280)
		return notify_fail("��ľ����񹦻�������죬����ʹ��" ZHUA "��\n");
	                        
        if ((int)me->query("neili", 1) < 300)
		return notify_fail("����������̫��������ʹ��" ZHUA "��\n");

        if (me->query_skill_prepared("claw") != "jiuyin-shengong"
           && me->query_skill_prepared("unarmed") != "jiuyin-shengong")
                return notify_fail("��û��׼��ʹ�þ����񹦣��޷�ʩչ" ZHUA "��\n");
       
       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "$N" HIY "΢΢һЦ�����ֳ�צ������ץ��$n"
	      HIY "��ҪѨ��\n" NOR;
	me->add("neili", -20);

        ap = me->query_skill("jiuyin-shengong", 1) * 3 / 2 +
             me->query_skill("martial-cognize", 1);
        dp = target->query_skill("parry") +
             target->query_skill("martial-cognize", 1);

	me->want_kill(target);
        if (ap / 2 + random(ap * 2) > dp)
        {
		me->start_busy(2);
                me->add("neili", -180);
                damage = 0;

                if (me->query("max_neili") > target->query("max_neili") * 2)
                {
                        msg += HIR "$N" HIR "��һצ���ƺÿ죬��ץ��$n"
			       HIR "��̴�д�Ѩ��$n" HIR
			       "һ���ҽУ��������̱����ȥ��\n" NOR;
                        damage = -1;
                } else
                {
        		target->start_busy(1 + random(3));
        
        		damage = ap + (int)me->query_skill("force");
                        damage = damage / 2 + random(damage / 2);
        		
                        if (arrayp(limbs = target->query("limbs")))
                                limb = limbs[random(sizeof(limbs))];
                        else
                                limb = "Ҫ��";
                        pmsg = HIR "$n��æ��Ų������Ȼ�������ꡱһ����$N"
			       HIR "��ָ������$n" HIR "��" + limb + "��$n"
			       HIR "һ���ҽУ�Ѫ���岽��\n" NOR;
                        msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 110, pmsg);
                }
	} else 
	{
		me->start_busy(2);
		msg += CYN "����$p" CYN "������$P"
                       CYN "�����ƣ���Ӧ�÷����ܿ�����һץ��\n"NOR;
	}

	message_combatd(msg, me, target);
        if (damage < 0) target->die(me);

	return 1;
}
