// hanxing-fada/lastrisk.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int i, skill;
        string msg;
        object *ob;
        object weapon;
        string pmsg;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("��עһ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("handing")) ||
            (string)weapon->query("skill_type") != "throwing" ||
            weapon->query_amount() < 1)
                return notify_fail("�����б������а�����\n");

        if ((skill = me->query_skill("hanxing-bada", 1)) < 60)
                return notify_fail("��ĺ��ǰ˴���Ϊ̫ǳ���޷�ʩչ��עһ����\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = CYN "$N" CYN "��עһ�����������а�������$n" CYN "��\n" NOR;
        me->start_busy(2);
        if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2)
        {
                msg += HIR "���$p" HIR "��$P" HIR "���˸����ֲ�����������ö������\n" NOR;
                target->receive_wound("qi", skill / 2 + random(skill / 2), me);
                COMBAT_D->clear_ahinfo();
                weapon->hit_ob(me, target, me->query("jiali") + 120);
                if (stringp(pmsg = COMBAT_D->query_ahinfo()))
                        msg += pmsg;
        } else
        {
                msg += CYN "����$p" CYN "���ݲ��ȵĶ����$P"
                       CYN "�����һ����\n" NOR;
        }

        message_combatd(msg, me, target);
        destruct(weapon);
        me->reset_action();
        return 1;
}
