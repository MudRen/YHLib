#include <ansi.h>
#include <combat.h>

#define YIN "��" HIR "������ӡ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if (userp(me) && ! me->query("can_perform/bazhen-zhang/yin"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(YIN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(YIN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("force") < 180)
                return notify_fail("����ڹ���Ϊ����������ʩչ" YIN "��\n");

        if ((int)me->query_skill("bazhen-zhang", 1) < 130)
                return notify_fail("��İ�������Ʋ�����죬����ʩչ" YIN "��\n");

        if (me->query_skill_mapped("strike") != "bazhen-zhang") 
                return notify_fail("��û�м�����������ƣ�����ʩչ" YIN "��\n");

        if (me->query_skill_prepared("strike") != "bazhen-zhang") 
                return notify_fail("��û��׼����������ƣ�����ʩչ" YIN "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("��������������������ʩչ" YIN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "������ģ�����ȫ������һ�ƣ�Я������֮�Ʒ�����$n"
              HIR "��ǰ���䡣\n" NOR;

        if (random(me->query_skill("strike")) > target->query_skill("parry") / 2)
        {
                me->start_busy(2);
                damage = me->query_skill("strike");
                damage = damage / 2 + random(damage);
                me->add("neili", -250);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 45,
                                           HIR "���$p" HIR "�мܲ�������$P" HIR
                                           "һ��ӡ���ؿڣ��������������߹ǣ����"
                                           "һ�����Ѫ��\n" NOR);
        } else
        {
                me->start_busy(3);
                me->add("neili", -100);
                msg += CYN "����$p" CYN "�����мܣ���¶�����������$P"
                       CYN "��һ����֮�����Ρ�\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
