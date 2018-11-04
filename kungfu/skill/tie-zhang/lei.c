#include <ansi.h>
#include <combat.h>

#define LEI "��" HIR "������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int damage;

        if (userp(me) && ! me->query("can_perform/tie-zhang/lei"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LEI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(LEI "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("tie-zhang", 1) < 160)
                return notify_fail("�������Ʒ���򲻹�������ʩչ" LEI "��\n");

        if (me->query_skill_mapped("strike") != "tie-zhang")
                return notify_fail("��û�м��������Ʒ�������ʩչ" LEI "��\n");

        if (me->query_skill_prepared("strike") != "tie-zhang")
                return notify_fail("��û��׼�������Ʒ�������ʩչ" LEI "��\n");

        if ((int)me->query_skill("force") < 240)
                return notify_fail("����ڹ���Ϊ����������ʩչ" LEI "��\n");

        if ((int)me->query("max_neili") < 2500)
                return notify_fail("���������Ϊ����������ʩչ" LEI "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�����ڵ��������㣬����ʩչ" LEI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = WHT "$N" WHT "��ת����ʩ����" HIR "������" NOR +
              WHT "��������˫�Ʒ��죬������գ���$n" WHT "��"
              "Ȼ�ĳ���\n" NOR;

        ap = me->query_skill("strike") + me->query("str") * 8;
        dp = target->query_skill("parry") + target->query("con") * 8;

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap / 2);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 65,
                                           HIR "���ֻ��$n" HIR "һ���ƺߣ���$N"
                                           HIR "һ���������ţ�������Ѫ���������"
                                           "\n" NOR);
                me->add("neili", -250);
                me->start_busy(3);
        } else
        {
                msg += CYN "$n" CYN "�ۼ�$N" CYN "������ӿ��˿��"
                       "����С���æ������һ�ԡ�\n" NOR;
                me->add("neili", -100);
                me->start_busy(4);
        }
        message_combatd(msg, me, target);

        return 1;
}
