#include <ansi.h>
#include <combat.h>

#define JUAN "��" HIY "��ת���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;

        if (userp(me) && ! me->query("can_perform/qishi-ji/juan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JUAN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "club")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" JUAN "��\n");

        if (me->query_skill("qishi-ji", 1) < 100)
                return notify_fail("��ʥ��ʿ���Ϊ����������ʩչ" JUAN "��\n");

        if (me->query_skill_mapped("club") != "qishi-ji")
                return notify_fail("��û�м���ʥ��ʿꪣ�����ʩչ" JUAN "��\n");

        if (me->query_skill("force") < 150)
                return notify_fail("����ڹ���Ϊ����������ʩչ" JUAN "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" JUAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "��������������" + weapon->name() + HIY "������"
              "ת��ꪼ��ʱ����һ��������ֱ��$n" HIY "��ȥ��\n" NOR;

        ap = me->query_skill("club");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap);
                me->add("neili", -50);
                me->start_busy(2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 90,
                                           HIR "���$n" HIR "������������$N" HIR
                                           "��" + weapon->name() + HIR "ꪼ����"
                                           "Ҫ������ʱ��Ѫ�ɽ���\n" NOR);
        } else
        {
                me->add("neili", -30);
                me->start_busy(3);
                msg += CYN "����$p" CYN "�������ң������������ܿ���$P"
                       CYN "�ļ��̹�����\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

