#include <ansi.h>
#include <combat.h>

#define DAO "��" HIR "��ָ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int i, count;

        if (userp(me) && ! me->query("can_perform/tie-zhang/dao"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(DAO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(DAO "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("tie-zhang", 1) < 180)
                return notify_fail("�������Ʒ���򲻹�������ʩչ" DAO "��\n");

        if (me->query_skill_mapped("strike") != "tie-zhang")
                return notify_fail("��û�м��������Ʒ�������ʩչ" DAO "��\n");

        if (me->query_skill_prepared("strike") != "tie-zhang")
                return notify_fail("��û��׼�������Ʒ�������ʩչ" DAO "��\n");

        if ((int)me->query_skill("force") < 280)
                return notify_fail("����ڹ���Ϊ����������ʩչ" DAO "��\n");

        if ((int)me->query("max_neili") < 2800)
                return notify_fail("���������Ϊ����������ʩչ" DAO "��\n");

        if ((int)me->query("neili") < 400)
                return notify_fail("�����ڵ��������㣬����ʩչ" DAO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = WHT "$N" WHT "����һչ��ʩ�����ƾ�����" HIR "��ָ��" NOR +
              WHT "�����Ʒ漤�������ˣ���$n" WHT "������ȥ��\n" NOR;  

        ap = me->query_skill("strike") + me->query("str") * 6;
        dp = target->query_skill("parry") + target->query("dex") * 6;

        if (ap / 2 + random(ap) > dp)
        {
                msg += HIR "$n" HIR "���$N" HIR "����ɽ������Ĺ�"
                       "�ƣ���ȫ�޷��ֵ����м�ɢ�ң������˺�\n" NOR;
                count = ap / 12;
        } else
        {
                msg += HIC "$n" HIC "�ĵ�΢΢һ������֪�����æ"
                       "�������񣬽߾����ܻ���$N" HIC "����������\n" NOR;
                count = 0;
        }
        message_combatd(msg, me, target);

        me->add_temp("apply/attack", count);
        me->add_temp("apply/unarmed_damage", count / 2);

        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(5) < 2 && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, 0, 0);
        }
        me->add("neili", -250);
        me->start_busy(1 + random(5));
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/unarmed_damage", -count / 2);
        return 1;
}

