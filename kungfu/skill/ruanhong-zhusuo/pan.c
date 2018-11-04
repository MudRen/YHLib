// panying.c ��ӥ��

#include <ansi.h>
#include <combat.h>

#define PANYING "��" YEL "��ӥ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
 
        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/ruanhong-zhusuo/panying"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(PANYING "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԣ��޷�ʩչ" PANYING "��\n");

        if ((int)me->query_skill("ruanhong-zhusuo", 1) < 80)
                return notify_fail("����������������죬�޷�ʩչ" PANYING "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

        if (me->query("neili") < 100)
                return notify_fail("��������������޷�ʩչ" PANYING "��\n");

        if (me->query_skill_mapped("whip") != "ruanhong-zhusuo")
                return notify_fail("��û�м�������������޷�ʩչ" PANYING "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = YEL "$N" YEL "ʹ�������������ӥ��������������һ������ʱ��"
              "Ӱ���أ���ȫ����$n" YEL "���ܣ�\n";

        me->start_busy(1);

        if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2)
        {
                msg += HIR "$n" HIR "΢�����죬һʱ���Ʋ�͸$N" HIR "����"
                       "����ٱ����˸����ֲ�����\n" NOR;
                target->start_busy((int)me->query_skill("ruanhong-zhusuo") / 20 + 2);
        } else
        {
                msg += CYN "����$p" CYN "������$P"
                       CYN "����ͼ��С��Ӧ�ԣ���û���ϵ���\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
