#include <ansi.h>
#include <combat.h>

#define LENG "��" HIW "�佣��" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
 
        if (userp(me) && ! me->query("can_perform/hanmei-jian/leng"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LENG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" LENG "��\n");

        if (me->query_skill("force") < 50)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" LENG "��\n");

        if (me->query_skill("hanmei-jian", 1) < 40)
                return notify_fail("��ĺ�÷������Ϊ����������ʩչ" LENG "��\n");

        if (me->query("neili") < 50)
                return notify_fail("�����������������ʩչ" LENG "��\n");

        if (me->query_skill_mapped("sword") != "hanmei-jian")
                return notify_fail("��û�м�����÷����������ʩչ" LENG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "����һ��������һԾ��������" + weapon->name() +
              HIW "Я������֮������$n" HIW "��\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("force");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap / 3);
                me->add("neili", -30);
                me->start_busy(2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 20,
                                           HIR "���$n" HIR "һ���������ٱ�$N" HIR
                                           "һ���������������˿ڣ�\n" NOR);
        } else
        {
                me->add("neili", -10);
                me->start_busy(3);
                msg += CYN "����$p" CYN "�������ң�������������񵲿���$P"
                       CYN "�Ľ��С�\n"NOR;
        }

        message_combatd(msg, me, target);

        return 1;
}
