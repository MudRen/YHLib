
#include <ansi.h>

inherit F_SSERVER;

#define DIAN "��" HIG "���յ�Ѩ" NOR "��"

int perform(object me, object target)
{
        object weapon;
        string msg;
        int time;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/yinsuo-jinling/dian"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(DIAN "��Ѩ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            weapon->query("skill_type") != "whip")
                return notify_fail("����������ԣ��޷�ʩչ" DIAN "��\n");

        if (me->query_skill("yinsuo-jinling", 1) < 80)
                return notify_fail("����������弶�𲻹����޷�ʩչ" DIAN "��\n");

        if (me->query_skill("force") < 100)
                return notify_fail("����ڹ���Ϊ�������޷�ʩչ" DIAN "��\n");

        if (me->query("neili") < 150)
                return notify_fail("�����������������޷�ʩչ" DIAN "��\n");

        if (me->query_skill_mapped("whip") != "yinsuo-jinling")
                return notify_fail("��û�м����������壬�޷�ʩչ" DIAN "��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "\n$N" HIY "����һ��������" + weapon->name() +
              HIY "�������£��ֵ�$n" HIY "���ϡ�ӭ�㡹��������"
              "���������С�����Ѩ���������µ�Ѩ����֮�졢��λ֮"
              "׼��ʵ�����ֺ�����" NOR;

        me->start_busy(1 + random(2));

        message_sort(msg, me, target);

        if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2)
        {
                msg = HIR "$n" HIR "ֻ��$N" + weapon->name() +
                      HIR "�����������죬���䲻��ȴ��"
                      "ʮ�ֹ��죬�������ҡ�ǣ�һ��\n����"
                      "�������е�����ţ�ȫ��̱����������"
                      "�����ã�\n" NOR;
                time = (int)me->query_skill("yinsuo-jinling") / 25;
                time = 2 + random(time);
                if (time > 13) time = 13;
                target->start_busy(time);
        } else
        {
                msg = CYN "����$p" CYN "������$P"
                      CYN "����ͼ��б������������\n" NOR;
        }
        me->add("neili", -120);
        message_combatd(msg, me, target);

        return 1;
}
