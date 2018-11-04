#include <ansi.h>
#include <combat.h>

#define ZHUAN "��" HIY "������ת" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/luoying-shenzhang/zhuan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(ZHUAN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("luoying-shenzhang", 1) < 120)
                return notify_fail("�����Ӣ���Ʋ�����죬����ʩչ" ZHUAN "��\n");

        if ((int)me->query_skill("qimen-wuxing", 1) < 120)
                return notify_fail("����������е��о�����������ʩչ" ZHUAN "��\n");

        if (me->query_skill_mapped("strike") != "luoying-shenzhang")
                return notify_fail("��û�м�����Ӣ���ƣ�����ʩչ" ZHUAN "��\n");

        if (me->query_skill_prepared("strike") != "luoying-shenzhang")
                return notify_fail("��û��׼����Ӣ���ƣ�����ʩչ" ZHUAN "��\n");

        if ((int)me->query_skill("force") < 180)
                return notify_fail("����ڹ�����㣬����ʩչ" ZHUAN "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�����ڵ���������������ʩչ" ZHUAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "���ƶ�Ȼһ�䣬ʩ����Ӣ���ơ�������ת������������"
              "ʵʵ�Ĺ���$n" HIY "��\n" NOR;

        ap = (int)me->query_skill("luoying-shenzhang", 1) +
             (int)me->query_skill("qimen-wuxing", 1) +
             (int)me->query_skill("force") +
             (int)me->query("int") * 10;

        dp = (int)target->query_skill("dodge") +
             (int)target->query_skill("parry") +
             (int)target->query_skill("qimen-wuxing", 1) +
             (int)target->query("int") * 10;

        me->add("neili", -150);
        if (ap / 2 + random(ap) > dp)
        {
                target->start_busy(2 + random(3));
	        me->start_busy(2);
                damage = (int)me->query_skill("force") + (int)me->query_skill("strike");
                damage = damage / 4;
                damage += random(damage);

                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30,
                                           HIR "$n" HIR "���һ������ʱ�������ƣ�"
                                           "�����һ����Ѫ�����Ӽ�ת����ͣ��\n" NOR);
        } else
	{
	        me->start_busy(3);
                msg += HIC "����$p" HIC "������$P" HIC "����ͼ���������򣬱ܿ���$P"
                       HIC "��һ����\n"NOR;
	}
        message_vision(msg, me, target);
        return 1;
}
