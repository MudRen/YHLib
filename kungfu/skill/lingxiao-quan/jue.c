#include <ansi.h>
#include <combat.h>

#define JUE "��" HIW "�����ܾ�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if (userp(me) && ! me->query("can_perform/lingxiao-quan/jue"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JUE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("ֻ�п��ֲ���ʩչ" JUE "��\n");

        if ((int)me->query_skill("lingxiao-quan", 1) < 60)
                return notify_fail("�������ȭ��������죬����ʩչ" JUE "��\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���Ϊ����������ʩչ" JUE "��\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("��������������������ʩչ" JUE "��\n");

        if (me->query_skill_mapped("cuff") != "lingxiao-quan") 
                return notify_fail("��û�м�������ȭ��������ʩչ" JUE "��\n");

        if (me->query_skill_prepared("cuff") != "lingxiao-quan")
                return notify_fail("������û��׼��ʹ������ȭ��������ʩչ" JUE "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "ֻ��$N" HIW "һ���Ϻȣ�˫ȭ�����뷢��һʽ�������ܾ���Я"
              "�ŷ���֮�ƺ���$n" HIW "��\n" NOR;

        if (random(me->query_skill("cuff")) > target->query_skill("dodge") / 2)
        {
                me->start_busy(2);
                damage = me->query_skill("cuff");
                damage = damage / 2 + random(damage / 2);
                me->add("neili", -50);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 20,
                                           HIR "���$p" HIR "���ܲ�������$P" HIR
                                           "һȭ�������ţ���ʱ������Ѫ����������"
                                           "��\n" NOR);
        } else
        {
                me->start_busy(3);
                me->add("neili", -30);
                msg += CYN "����$p" CYN "ʶ����$P"
                       CYN "��һ�У�ббһԾ�ܿ���\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
