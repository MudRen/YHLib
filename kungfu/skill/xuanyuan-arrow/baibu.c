// baibu.c �ٲ�����

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, i;
        int n;
        int my_exp, ob_exp;
        string pmsg;
        string msg;
        object weapon;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("�ٲ�����ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("handing")) ||
            ! weapon->is_arrow())
                return notify_fail("���������в�û�����ż�����ôʩչ�ٲ����\n");

        if (weapon->query_amount() < 3)
                return notify_fail("����Ҫ��һ֧�������ʩչ�ٲ����\n");

        if ((skill = me->query_skill("xuanyuan-arrow", 1)) < 100)
                return notify_fail("�����ԯ����������죬����ʹ�ðٲ����\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�����������ˡ�\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        me->add("neili", -80);
        weapon->add_amount(-1);

        msg= HIY "ͻȻ�䣬$N" HIY "�����������ȥ������$n" HIY
             "����֮�⡣$n" HIY "����׷����$N" HIY "��Ȼת����һ�����ٲ������\n"
             HIY "˵ʱ�٣���ʱ�죬" HIY + weapon->name() + HIY "�Ѵ����ƿ�֮����ֱ��$n"
             HIY "���ţ�\n" NOR;

        me->start_busy(2);
        my_exp = me->query("combat_exp") + skill * skill / 10 * skill;
        ob_exp = target->query("combat_exp");
        if (random(my_exp) > ob_exp)
        {
                msg += HIR "���$p" HIR "��Ӧ����������$P" + HIR "һ����\n" NOR;
                target->receive_wound("qi", skill / 3 + random(skill / 3), me);
                COMBAT_D->clear_ahinfo();
                weapon->hit_ob(me, target,
                               me->query("jiali") + 120);
                if (stringp(pmsg = COMBAT_D->query_ahinfo()))
                        msg += pmsg;
                message_combatd(msg, me, target);
        } else
        {
                msg += CYN "����$p" CYN "���ݲ��ȣ����ɵ�������$P"
                       CYN "��һ����\n" NOR;
                message_combatd(msg, me, target);
        }

        me->reset_action();
        return 1;
}
