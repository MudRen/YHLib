#include <ansi.h>
#include <combat.h>

#define BAI "��" HIY "�������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int ap, dp, damage;
        string msg;
        object weapon;

        if (userp(me) && ! me->query("can_perform/tiangang-chenfa/bai"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(BAI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" BAI "��\n");

        if ((int)me->query_skill("tiangang-chenfa", 1) < 120)
                return notify_fail("�������������죬����ʩչ" BAI "��\n");

        if ((int)me->query("max_neili") < 1500)
                return notify_fail("���������Ϊ���㣬����ʩչ" BAI "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("��������������������ʩչ" BAI "��\n");

        if (me->query_skill_mapped("whip") != "tiangang-chenfa")
                return notify_fail("��û�м��������������ʩչ" BAI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "����$N" HIY "����" + weapon->query("name") + HIY "�ܶ���"
              "�ѣ����������������ʽ����Ϯ$n" HIY "����Ҫ����\n";

        ap = me->query_skill("whip");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                me->start_busy(2);
                damage = ap * 4 / 3;
                damage = damage / 2 + random(damage * 2 / 3);

                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
                                           HIR "$n" HIR "��æ������ȴ����$N" HIR
                                           "��" + weapon->name() + HIR "��Ȼ����"
                                           "��ǰҪѨ���ٸ���Ѫ��ӿ������֮����\n" NOR);
                me->add("neili", -180);
        } else
        {
                me->start_busy(3);
                msg += CYN "����$p" CYN "������$P"
                       CYN "������ʵ������������𣬶�ܿ�����\n" NOR;
        }
        message_combatd(msg, me, target);
        return 1;
}
