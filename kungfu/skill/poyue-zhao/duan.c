#include <ansi.h>
#include <combat.h>

#define DUAN "��" HIY "��������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int i;

        if (userp(me) && ! me->query("can_perform/poyue-zhao/duan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(DUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail(DUAN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("poyue-zhao", 1) < 80)
                return notify_fail("��������צ������죬����ʩչ" DUAN "��\n");

        if (me->query_skill_mapped("claw") != "poyue-zhao")
                return notify_fail("��û�м���������צ������ʩչ" DUAN "��\n");

        if (me->query_skill_prepared("claw") != "poyue-zhao")
                return notify_fail("��û��׼��������צ������ʩչ" DUAN "��\n");

        // ����NPCô������������û����ĺã�����ʱ��CLAW��ǰ�����ˡ�
        if (userp(me) && me->query_skill_prepared("cuff") == "zhenyu-quan")
                return notify_fail("ʩչ" DUAN "ʱ������צ���������ȭ��������\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�������������㣬����ʩչ" DUAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "��ʱ��ֻ��$N" HIY "����һչ��˫צ�������ϣ�צӰ����$n"
              HIY "ȫ�����ҪѨ��\n" NOR;
        message_combatd(msg, me, target);
        me->add("neili", -50);

        for (i = 0; i < 4; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, 0, 0);
        }
        me->start_busy(1 + random(4));
        return 1;
}
