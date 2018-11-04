#include <ansi.h>
#include <combat.h>

#define MANG "��" HIW "������â" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
 
        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/bagua-dao/mang"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(MANG "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" MANG "��\n");

        if (me->query_skill("force") < 200)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" MANG "��\n");

        if (me->query_skill("wai-bagua", 1) < 140)
                return notify_fail("������������Ϊ����������ʩչ" MANG "��\n");

        if (me->query_skill("bagua-dao", 1) < 140)
                return notify_fail("��İ��Ե�����Ϊ����������ʩչ" MANG "��\n");

        if (me->query_skill_mapped("blade") != "bagua-dao")
                return notify_fail("��û�м������Ե���������ʩչ" MANG "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����������������ʩչ" MANG "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "��̤�����ķ�֮λ����Ȼһ������" + weapon->name() +
              HIW "�������ʱ��������ѩ����â����$n" + HIW "���Ź�ס��\n" NOR;

        ap = me->query_skill("blade");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap);
                me->add("neili", -150);
                me->start_busy(2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 75,
                                           HIR "ֻ��$n" HIR "һ���ҽУ�һ��Ѫ����" HIR
                                           "���׵ĵ�â�зɽ�������\n" NOR);
        } else
        {
                me->add("neili", -60);
                me->start_busy(3);
                msg += CYN "����$p" CYN "�����ֿ죬ֻ����������������һ��"
                       CYN "������$p" CYN "��$P" CYN "����ʽȫ��������\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
