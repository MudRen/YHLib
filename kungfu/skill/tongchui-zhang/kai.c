#include <ansi.h>
#include <combat.h>

#define KAI "��" HIY "�嶡��ɽ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if (userp(me) && ! me->query("can_perform/tongchui-zhang/kai"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(KAI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(KAI "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("tongchui-zhang", 1) < 80)
                return notify_fail("��ͭ���Ʒ�������죬����ʩչ" KAI "��\n");

        if (me->query_skill_mapped("strike") != "tongchui-zhang") 
                return notify_fail("��û�м���ͭ���Ʒ�������ʩչ" KAI "��\n");

        if (me->query_skill_prepared("strike") != "tongchui-zhang") 
                return notify_fail("��û��׼��ͭ���Ʒ�������ʩչ" KAI "��\n");

        if ((int)me->query_skill("force") < 90)
                return notify_fail("����ڹ���Ϊ����������ʩչ" KAI "��\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�����ڵ���������������ʩչ" KAI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "���ư���������ʮָ���ţ����һ�С�"
              HIR "�嶡��ɽ" HIY "����$n" HIY "������ȥ��\n" NOR;

        if (random(me->query_skill("strike")) > target->query_skill("dodge") / 2)
        {
                damage = me->query_skill("strike");
                damage = damage / 3 + random(damage / 2);

                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 20,
                                           HIR "���$n" HIR "���ܲ������ٱ�$N" HIR
                                           "���ƻ������У������������ڲ��ѡ�\n" NOR);
                me->start_busy(2);
                me->add("neili", -80);
        } else
        {
                msg += CYN "����$n" CYN "�������ţ����������"
                       "��һԾ�����ܿ�����\n" NOR;
                me->start_busy(3);
                me->add("neili", -30);
        }
        message_combatd(msg, me, target);

        return 1;
}
