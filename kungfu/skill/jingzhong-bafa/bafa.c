#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int count;
        int i;
 
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("���а˷�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("����û����ʹʲô���а˷���\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("����ڹ���򲻹���\n");

        if ((int)me->query_skill("jingzhong-bafa", 1) < 200)
                return notify_fail("��ľ��а˷��������ң��޷�ʩչ���С�\n");

        if (me->query_skill_mapped("blade") != "jingzhong-bafa")
                return notify_fail("��û�м������а˷����޷�ʩչ���С�\n");

        msg = HIY "$N" HIY "һ����Х�����е�" + weapon->name() +
              HIY "�������а˷���һ��ʩ���������仯Ī�⣬������$n" HIY "����Ҫ����\n" NOR;

        if (random(me->query_skill("blade")) > target->query_skill("parry") / 3)
        {
                msg += HIR "$n" HIR "������ʵ���Ǳ��Ī�⣬���ɵ���"
                       "�����⣬��ʽ��ʱ����������\n" NOR;
                count = me->query_skill("jingzhong-bafa)", 1) / 3;
        } else
        {
                msg += HIC "$n" HIC "�ĵ�΢΢һ����������С�Ľ��С�\n" NOR;
                count = 0;
        }

        message_combatd(msg, me, target);
        me->add("neili", -150);
        me->add_temp("apply/attack", count);

        for (i = 0; i < 8; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(1);
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -count);
        me->start_busy(1 + random(6));
        return 1;
}

