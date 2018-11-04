#include <ansi.h>

#define CI "��" HIR "���Ŵ�" NOR "��"

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, ap, dp;

        if (userp(me) && ! me->query("can_perform/shenmen-jian/ci"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(CI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" CI "��\n");

        skill = me->query_skill("shenmen-jian", 1);

        if (skill < 120)
                return notify_fail("�������ʮ�����ȼ�����������ʩչ" CI "��\n");

        if (!objectp(weapon2 = target->query_temp("weapon")))
                return notify_fail("�Է�û��ʹ�ñ���������ʩչ" CI "��\n");

        if (me->query_skill_mapped("sword") != "shenmen-jian")
                return notify_fail("������û�м�������ʮ����������ʩչ" CI "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�������������㣬����ʩչ" CI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "ͻȻ$N" HIR "һ����ߣ�����" + weapon->name() + HIR
              "�й�ֱ����ֱ��$n" HIR "���ŵ�" + weapon2->name() + HIR
              "������\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (dp < 1) dp = 1;

        if (ap / 3 + random(ap) > dp)
        {
                me->add("neili", -120);
                msg += HIR "$n" HIR "ֻ������һ���ʹ������" + weapon2->name() +
                       HIR "��Ҳ����ס�����ֶ��ɡ�\n" NOR;
                me->start_busy(2 + random(2));
                target->start_busy(2);
                weapon2->move(environment(target));
        } else
        {
                me->add("neili", -40);
                msg += CYN "����$n" CYN "������$N" CYN "����ͼ�������б��л�"
                       "����ܲ�͸�磬������$N" CYN "�ı�����\n"NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);
        return 1;
}