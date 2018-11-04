#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int ap;
        int dp;
        int damage;
        string msg;

        if (target == me || ! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail("��ֻ���ú�������ս���еĶ��֡�\n");

        if (me->query_skill("bingxin-jue", 1) < 150)
                return notify_fail("��ı��ľ���򲻹����޷����ú�����\n");

        if ((int)me->query("neili") < 1000)
                return notify_fail("�����������!");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "Ĭ�˱��ľ���һ�ɺ���ӭ������$n"
              HIW "�����ܵ�ʱѩ��ƮƮ��\n" NOR;

        ap = me->query_skill("force");
        dp = me->query_skill("force");

        me->start_busy(2);

        if (ap / 2 + random(ap) > random(dp))
        {
                damage = ap / 3 + random(ap / 3);
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage, me);
                if (target->query("neili") > damage)
                        target->add("neili", damage);
                else
                        target->set("neili", 0);

                msg += HIR "$n" HIR "��Ȼ����һ��͸�Ǻ��⣬��ʱ��"
                       "�����ѪҺ������Ҫ�����ˡ�\n" NOR;
                target->start_busy(1);
        } else
                msg += HIY "$n" HIY "�е�һ�������ĵ׷�����æ"
                       "�˶��ֿ����������¡�\n" NOR;

        message_combatd(msg, me, target);

        return 1;
}

