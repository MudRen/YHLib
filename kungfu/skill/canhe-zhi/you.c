#include <ansi.h>
#include <combat.h>

#define YOU "��" MAG "��ڤ����" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;
        int i;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/canhe-zhi/you"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(YOU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("�������ֲ���ʹ��" YOU "��\n");

        if ((int)me->query_skill("canhe-zhi", 1) < 120)
                return notify_fail("��Ĳκ�ָ��Ϊ���ޣ�����ʩչ" YOU "��\n");

        if (me->query_skill_mapped("finger") != "canhe-zhi")
                return notify_fail("��û�м����κ�ָ������ʩչ" YOU "��\n");

        if (me->query_skill_prepared("finger") != "canhe-zhi")
                return notify_fail("������û��׼��ʹ�òκ�ָ������ʩչ" YOU "��\n");

        if ((int)me->query("max_neili") < 2500)
                return notify_fail("���������Ϊ���㣬����ʩչ" YOU "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����������������ʩչ" YOU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "ֻ��$N" HIW "����һչ������Ȼ��ù����ޱȣ�������ָ��Ȼ��"
              "�������ɽ���ֱϮ$n" HIW "ҪѨ��ȥ��\n" NOR;  

        message_combatd(msg, me, target);

        me->start_busy(1 + random(5));
        me->add("neili", -300);

        for (i = 0; i < 6; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(2) == 1 && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, 0, 0);
        }

        return 1;
}
