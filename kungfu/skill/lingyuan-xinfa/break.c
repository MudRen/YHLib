// break -�������Ƹ֡�
// made by deaner

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int exert(object me, object target)
{
        string msg;
        object target_w;

        target_w = target->query_temp("weapon");

        if (! target || target == me)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }
	if (! target || ! me->is_fighting(target))
                return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á������Ƹ֡���\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���ڷ�㶣��ǽ����ĺ�ʱ����\n");

        if ((int)me->query_skill("lingyuan-xinfa", 1) < 150)
                return notify_fail("�����Ԫ�ķ���򲻹���������ʹ�á������Ƹ֡���\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "$N" HIC "���绬�����Ե���������һ������֮��"
              "˳��Ѫ�����紫��˫���͹�Ѩ�������������֮����"
              "�������������$n" HIC "���еı��У�\n" NOR;
        me->start_busy(2);

        if (target->query_temp("weapon") || target->query_temp("secondary_weapon"))
        {
                if (random(me->query("combat_exp")) >
                    (int)target->query("combat_exp") / 3)
                {
                        msg += HIW "���$p" HIW "���е�" +
                               target_w->query("name") +
                               "���������֮��һ�����������ڵ��ϣ�\n" NOR;
                        target_w->unequip();
                        target_w->move(environment(target));
                        target->reset_action();
                        target->start_busy((int)me->query_skill("lingyuan-xinfa") / 20);
                } else
                {
                        msg += CYN "����$p" CYN "�������У�����"
                               "��ȥ��ʹ$P" CYN "�ļ�ıû�еóѡ�\n" NOR;
                }
                message_combatd(msg, me, target);
                return 1;
        }
        return notify_fail(target->name() + "Ŀǰ�ǿ��֣�ûʲô��Ҫʩչ�������Ƹ֡���\n");
}
