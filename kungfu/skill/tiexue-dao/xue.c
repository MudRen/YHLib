#include <ansi.h>
#include <combat.h>

#define XUE "��" HIR "Ѫ������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;

        if (userp(me) && ! me->query("can_perform/tiexue-dao/xue"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(XUE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "blade")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" XUE "��\n");

        if (me->query_skill("tiexue-dao", 1) < 100)
                return notify_fail("����Ѫ�����ȼ�����������ʩչ" XUE "��\n");

        if (me->query_skill_mapped("blade") != "tiexue-dao")
                return notify_fail("��û�м�����Ѫ����������ʩչ" XUE "��\n");

        if (me->query_skill("force") < 150)
                return notify_fail("����ڹ���Ϊ����������ʩչ" XUE "��\n");

        if (me->query("neili") < 200)
                return notify_fail("��Ŀǰ���������㣬����ʩչ" XUE "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "ɱ����ʢ������" + weapon->name() +
              HIR "һ�񣬶�ʱһ��Ѫ��ӵ�����������$n"
              HIR "���Ź�ס��\n" NOR;

        ap = me->query_skill("blade");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap / 2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 35,
                                           HIR "ֻ��$n" HIR "һ���Һ�������һ����"
                                           "һ��Ѫ����" HIR "Ѫɫ��Ӱ�м��������"
                                           "\n" NOR);
                me->start_busy(2);
                me->add("neili", -120);
        } else
        {
                msg += CYN "����$n" CYN "�����ֿ죬�����мܣ���$N"
                       CYN "����ʽȫ��������\n" NOR;
                me->start_busy(3);
                me->add("neili", -80);
        }
        message_combatd(msg, me, target);

        return 1;
}