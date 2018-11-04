// zhi.c ������ָ

#include <ansi.h>

inherit F_SSERVER;

#define ZHI "��" HIY "������ָ" NOR "��"

int perform(object me, object target)
{
        string msg;
        object weapon;
        int n;
        int skill, ap, dp, damage;


        if (userp(me) && ! me->query("can_perform/jiuyin-shengong/zhi"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        skill = me->query_skill("jiuyin-shengong", 1);

        if (! me->is_fighting(target))
                return notify_fail(ZHI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon"))
                return notify_fail(ZHI "ֻ�ܿ���ʩչ��\n");

        if (skill < 250)
                return notify_fail("��ľ����񹦵ȼ��������޷�ʩչ" ZHI "��\n");

        if (me->query("neili") < 250)
                return notify_fail("��������������������ʩչ" ZHI "��\n");

        if (me->query_skill_prepared("finger") != "jiuyin-shengong"
           && me->query_skill_prepared("unarmed") != "jiuyin-shengong")
                return notify_fail("��û��׼��ʹ�þ����񹦣��޷�ʩչ" ZHI "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        me->add("neili", -100);

        ap = skill * 3 / 2 + me->query_skill("martial-cognize", 1);
        dp = target->query_skill("parry") + target->query_skill("martial-cognize", 1);

        msg = HIY "$N" HIY "���ֳ�ָ�����������ƺ�������$n"
              HIY + "��ʽ�е�������\n" NOR;
        if (ap / 2 + random(ap * 2) > dp)
        {
                n = 4 + random(4);
                if (ap * 11 / 20 + random(ap) > dp)
                {
                        msg += HIY "$n" HIY "����ָ�����ޱȣ�ȫȻ�޷��ֵ�������֮������������$N"
                               HIY "��������" + chinese_number(n) + "ָ��\n" NOR;
                        message_combatd(msg, me, target);
                        me->start_busy(1 + random(n));
                        while (n-- && me->is_fighting(target))
                        {
                                if (random(2) && ! target->is_busy())
                                	target->start_busy(1);

                                COMBAT_D->do_attack(me, target, 0, 0);
                        }

                        weapon = target->query_temp("weapon");
                        if (weapon && random(ap) / 2 > dp && weapon->query("type") != "pin")
                        {
                                msg = HIW "$n" HIW "������ǰ�ۻ����ң����е�" + weapon->name() +
                                      HIW "һʱ��Ȼ����ס�����ֶ�����\n" NOR;
                                weapon->move(environment(me));
                        } else
                        {
                                msg = HIY "$n�����ֵ���һʱ����Ҳ����������\n" NOR;
                        }

                        if (! me->is_fighting(target))
                                // Don't show the message
                                return 1;
                } else
                {
                        msg += HIY "$n" HIY "�������룬��æ�ֵ���ȫȻ�޷�������\n" NOR;
			if (! target->is_busy())
                        	target->start_busy(4 + random(skill / 30));
                }
        } else
        {
                msg += HIC "����$n" HIC "�����Ż�����¶���������\n" NOR;
                me->start_busy(3 + random(2));
        }

        message_combatd(msg, me, target);
        return 1;
}
