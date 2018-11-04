// shan.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, i;
        int n;
        string pmsg;
        string msg;
        object weapon;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("С��ɵ�ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("handing")) ||
            (string)weapon->query("skill_type") != "throwing")
                return notify_fail("���������в�û�����ŷɵ���\n");

        if ((skill = me->query_skill("xiaoli-feidao", 1)) < 100)
                return notify_fail("���С��ɵ�������졣\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�����������ˡ�\n");

        me->add("neili", -50);
        weapon->add_amount(-1);

        msg= HIW "��Ȼ��ֻ��$N" HIW "���к���һ��������С��ɵ��������鷢��\n\n"
             NOR + HIR "һ����Ѫ��$n" HIR "�ʺ����������\n" NOR;
        message_combatd(msg, me, target);


        me->start_busy(random(5));
        target->die(me);
        me->reset_action();
        return 1;
}
