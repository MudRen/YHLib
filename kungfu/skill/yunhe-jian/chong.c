#include <ansi.h>
#include <combat.h>

#define CHONG "��" HIM "�׳����" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
 
        if (userp(me) && ! me->query("can_perform/yunhe-jian/chong"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(CHONG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" CHONG "��\n");

        if (me->query_skill("force") < 150)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" CHONG "��\n");

        if (me->query_skill("yunhe-jian", 1) < 100)
                return notify_fail("����ƺ��߽���Ϊ����������ʩչ" CHONG "��\n");

        if (me->query("neili") < 100)
                return notify_fail("�����������������ʩչ" CHONG "��\n");

        if (me->query_skill_mapped("sword") != "yunhe-jian")
                return notify_fail("��û�м����ƺ��߽�������ʩչ" CHONG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIM "$N" HIM "��Ȼһ����Х������" + weapon->name() +
              HIM "������������ճ�һ��Ѥ���Ľ�â��ֱ��$n" HIM "ǰ�أ�\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = 50 + ap / 2 + random(ap / 2);
                me->add("neili", -80);
                me->start_busy(2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 25,
                                           HIR "$n" HIR "�����񵲣��վ����У���$N"
                                           HIR "һ�������ؿڣ���Ѫ�ɽ�������\n" NOR);
        } else
        {
                me->add("neili", -60);
                me->start_busy(3);
                msg += CYN "����$p" CYN "�������ң�������������񵲿���$P"
                       CYN "�Ľ��С�\n"NOR;
        }

        message_combatd(msg, me, target);

        return 1;
}
