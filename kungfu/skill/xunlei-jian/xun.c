#include <ansi.h>
#include <combat.h>

#define XUN "��" HIY "Ѹ��һ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
 
        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/xunlei-jian/xun"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(XUN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ������޷�ʩչ" XUN "��\n");

        if (me->query_skill("force") < 150)
                return notify_fail("����ڹ�����Ϊ�������޷�ʩչ" XUN "��\n");

        if (me->query_skill("xunlei-jian", 1) < 100)
                return notify_fail("���Ѹ�׽�����Ϊ�������޷�ʩչ" XUN "��\n");

        if (me->query("neili") < 250)
                return notify_fail("��������������޷�ʩչ" XUN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "����һԾ��������" + weapon->name() + NOR + HIY
              "һ���������ʱ����һ����⣬ֱֱ����$n" HIY "��ȥ��\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap / 2);
                me->add("neili", -180);
                me->start_busy(2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40,
                                           HIR "$n" HIR "��ܲ����������ʱ͸���"
                                           "�룬һ���ҽУ���Ѫ��к��ֹ��\n" NOR );
        } else
        {
                me->add("neili", -60);
                me->start_busy(3);
                msg += CYN "����$p" CYN "�����񵲣����ڼܿ���$P"
                       CYN "�����Ľ��С� \n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
