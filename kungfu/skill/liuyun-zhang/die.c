#include <ansi.h>
#include <combat.h>

#define DIE "��" HIW "���Ƶ�Ӱ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/liuyun-zhang/die"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(DIE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(DIE "ֻ�ܿ���ʩչ��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((int)me->query_skill("liuyun-zhang", 1) < 100)
                return notify_fail("�������Ʋ�����죬����ʩչ" DIE "��\n");

        if (me->query_skill_mapped("strike") != "liuyun-zhang")
                return notify_fail("��û�м��������ƣ�����ʩչ" DIE "��\n");

        if (me->query_skill_prepared("strike") != "liuyun-zhang")
                return notify_fail("��û��׼�������ƣ�����ʩչ" DIE "��\n");

        if (me->query_skill("dodge") < 150)
                return notify_fail("����Ṧ��Ϊ����������ʩչ" DIE "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" DIE "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("liuyun-zhang", 1) +
             me->query_skill("dodge", 1) / 2;

        dp = target->query_skill("dodge");

        msg = HIC "\n$N" HIC "����Ȼ��죬˫�Ʋ����ĳ�����ʽ��Ӱ"
              "��ã���ʵ�Ѳ⣬��ͼ����$n" HIC "�Ĺ��ơ�" NOR;

        message_sort(msg, me, target);

        if (random(ap) > dp / 2)
        {
		msg = HIY "$n" HIY "ֻ��$N" HIY "˫��Ʈ����������"
                      "����������������$N" HIY "���Ʒ�֮�С�\n" NOR;

                target->start_busy(ap / 45 + 1);
               	me->start_busy(1);
                me->add("neili", -80);
        } else
        {
                msg = CYN "$n" CYN "����$N" CYN "���޹���֮�⣬��"
                      "�Ǵ󵨷�������$N" CYN "���о������⡣\n" NOR;

                me->start_busy(2);
                me->add("neili", -30);
        }
        message_combatd(msg, me, target);

        return 1;
}
