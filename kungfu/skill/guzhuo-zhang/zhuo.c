#include <ansi.h>
#include <combat.h>

#define ZHUO "��" WHT "������׾" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/guzhuo-zhang/zhuo"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHUO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(ZHUO "ֻ�ܿ���ʹ�á�\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((int)me->query_skill("force") < 220)
                return notify_fail("���ڹ���Ϊ����������ʩչ" ZHUO "��\n");

        if ((int)me->query("max_neili") < 1800)
                return notify_fail("��������Ϊ����������ʩչ" ZHUO "��\n");

        if ((int)me->query_skill("guzhuo-zhang", 1) < 150)
                return notify_fail("���׾�Ʒ���򲻹�������ʩչ" ZHUO "��\n");

        if (me->query_skill_mapped("strike") != "guzhuo-zhang")
                return notify_fail("��û�м�����׾�Ʒ�������ʩչ" ZHUO "��\n");

        if (me->query_skill_prepared("strike") != "guzhuo-zhang")
                return notify_fail("��û��׼����׾�Ʒ�������ʩչ" ZHUO "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("��������������������ʩչ" ZHUO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = WHT "$N" WHT "����һ̽��ƽƽ�Ƴ�һ�ƣ���ʱ�Ʒ缤������ɳ����ֱ"
              "�ε�$n" WHT "�����������ۡ�\n" NOR;
        me->add("neili", -150);

        ap = me->query_skill("strike");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)

        {
                msg += HIR "$n" HIR "��$N" HIR "�Ʒ���������"
                       "æ�мܣ���ʱ��ʧ���Ȼ���\n" NOR;
                target->start_busy((int)me->query_skill("guzhuo-zhang", 1) / 22 + 2);
                me->start_busy(1);
        } else
        {
                msg += CYN "����$n" CYN "���Ų�æ��������$N"
                       CYN "������ʵ����û���ܵ����Ӱ�졣\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}
