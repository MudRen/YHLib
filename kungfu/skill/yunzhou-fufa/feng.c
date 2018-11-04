#include <ansi.h>

inherit F_SSERVER;

#define FENG "��" HIG "��ħ��" NOR "��"

int perform(object me, object target)
{
        object weapon;
        string msg;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(FENG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ����"
                                   "�������ɡ�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            weapon->query("skill_type") != "whip")
                return notify_fail("����������ԣ��޷�ʩչ" FENG "\n");

        if (me->query_skill("yunzhou-fufa", 1) < 60)
                return notify_fail("�������������𲻹����޷�ʩչ" FENG "��\n");

        if (me->query("neili") < 100)
                return notify_fail("�����������������޷�ʩչ" FENG "��\n");

        if (me->query_skill_mapped("whip") != "yunzhou-fufa")
                return notify_fail("��û�м�������������޷�ʩչ" FENG "��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "\n$N����һ����Ǳ��������������" + weapon->name() + HIY 
              "����ú���ֱ�죬ֱ�Ƴ��գ����������ɳ�����$n��" NOR;

        me->start_busy(1);

        message_sort(msg, me, target);

        if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2)
        {
                msg = HIR "$n" HIR "ֻ��������������ǰ��ǧ��Ӱ���ٸ�"
                      "�ֽ��޴룬���Ų��ѡ�\n" NOR;
                target->start_busy((int)me->query_skill("yunzhou-fufa") / 25 + 2);
        } else
        {
                msg = CYN "����$p" CYN "������$P"
                      CYN "����ͼ��б������������\n" NOR;
        }
        me->add("neili", -80);
        message_combatd(msg, me, target);

        return 1;
}
