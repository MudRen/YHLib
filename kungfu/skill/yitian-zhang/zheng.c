#include <ansi.h>
#include <combat.h>

#define ZHENG "��" HIY "˭������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int count;
        int lvl;
        int i;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/yitian-zhang/zheng"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHENG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("�������ֲ���ʹ��" ZHENG "��\n");

        if ((lvl = (int)me->query_skill("yitian-zhang", 1)) < 120)
                return notify_fail("������������Ʋ�����죬����ʩչ" ZHENG "��\n");

        if ((int)me->query("neili", 1) < 500)
                return notify_fail("����������̫��������ʩչ" ZHENG "��\n");

        if (me->query_skill_mapped("strike") != "yitian-zhang")
                return notify_fail("��û�м������������ƣ�����ʩչ" ZHENG "��\n");

        if (me->query_skill_prepared("strike") != "yitian-zhang")
                return notify_fail("��û��׼��ʹ�����������ƣ�����ʩչ" ZHENG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "������ͨ�������������ƶ�ʮ����һ���ǳɣ�˫��"
              "Я������ɽ����֮������$n" HIY "��\n\n" NOR;
        me->add("neili", -150);

        if (random(me->query_skill("force") + me->query_skill("strike")) >
            target->query_skill("force"))
        {
                msg += HIR "$n" HIR "��ʱ���ú���������ȫȻ����"
                       "���������ƣ�ֻ��ƴ���˶��ֵ���\n" NOR;
                count = lvl / 5;
                me->add_temp("apply/attack", count);
        } else
        {
                msg += HIC "$n" HIC "����һ����������ֵ�������������"
                       "�ھ��κ���֮�У����ҵ�����ȴ�ǲ�����\n" NOR;
                count = 0;
        }
        message_combatd(msg, me, target);

        for (i = 0; i < 4; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->add_temp("apply/attack", -count);
        me->start_busy(1 + random(4));
        return 1;
}
