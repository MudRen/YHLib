#include <ansi.h>

inherit F_SSERVER;

#define WEI "��" HIG "������Ϊ" NOR "��"

int perform(object me, object target)
{
        object weapon;
        string msg;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/sanwu-shou/wei"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(WEI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ����"
                                   "�������ɡ�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            weapon->query("skill_type") != "whip")
                return notify_fail("����������ԣ��޷�ʩչ" WEI "\n");

        if (me->query_skill("sanwu-shou", 1) < 70)
                return notify_fail("������������ּ��𲻹����޷�ʩչ" WEI "��\n");

        if (me->query("neili") < 100)
                return notify_fail("�����������������޷�ʩչ" WEI "��\n");

        if (me->query_skill_mapped("whip") != "sanwu-shou")
                return notify_fail("��û�м������������֣��޷�ʩչ " WEI "��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "\n$N����һ����Ǳ������������ʩ�����С�" HIG "������Ϊ" HIY
              "����" + weapon->name() + HIY "����ú���ֱ�죬������ң���$n"
              HIY "������" + weapon->name() + "�Ĺ���֮�¡�" NOR;
        me->start_busy(1);

        message_sort(msg, me, target);

        if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2)
        {
                msg = HIR "$n" HIR "ֻ��������������ǰ��ǧ��Ӱ���ٸ�"
                      "�ֽ��޴룬���Ų��ѡ�\n" NOR;
                target->start_busy((int)me->query_skill("sanwu-shou") / 20 + 2);
        } else
        {
                msg = CYN "����$p" CYN "������$P"
                      CYN "����ͼ��б������������\n" NOR;
        }
        me->add("neili", -80);
        message_combatd(msg, me, target);

        return 1;
}
