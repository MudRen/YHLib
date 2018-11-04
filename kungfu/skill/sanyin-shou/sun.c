#include <ansi.h>
#include <combat.h>

#define SUN "��" HIR "����" NOR "��"

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object target;
        int skill, ap, dp, damage;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (userp(me) && ! me->query("can_perform/sanyin-shou/sun"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        skill = me->query_skill("sanyin-shou", 1);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SUN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (skill < 140)
                return notify_fail("��������ֵȼ�����������ʩչ" SUN "��\n");

        if (me->query("max_neili") < 1600 )
                return notify_fail("���������Ϊ���㣬����ʩչ" SUN "��\n");

        if (me->query("neili") < 200 )
                return notify_fail("�����������������ʩչ" SUN "��\n");

        if (me->query_skill_mapped("hand") != "sanyin-shou")
                return notify_fail("��û�м��������֣�����ʩչ" SUN "��\n");

        if (me->query_skill_prepared("hand") != "sanyin-shou")
                return notify_fail("������û��׼��ʹ�������֣�����ʩչ" SUN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "��Ȼ������$n" HIR "��ǰ����Ȼʹ��"
              "�����־������������������������$n" HIR "̫��"
              "Ѩ�����Ű��������\n" NOR;

        damage = skill / 2 + random(skill / 2);

        ap = me->query_skill("hand");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -200);
                me->start_busy(2);
                target->receive_damage("jing", damage);
                target->receive_wound("jing", damage);
                target->start_busy(1);
                msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK,
                       damage, 0, HIR "$n" HIR "�Բ������ѱ�$N" HIR
                       "���Ʒ��У�ֻ����ǰһ�ڣ������ε���\n" NOR);
        }
        else
        {
                me->add("neili", -100);
                msg += CYN "$n" CYN "��״���һ������æ�������������"
                       "���ڱܿ���$N" CYN "��һ����\n" NOR;
                me->start_busy(4);
        }
        message_combatd(msg, me, target);
        return 1;
}
