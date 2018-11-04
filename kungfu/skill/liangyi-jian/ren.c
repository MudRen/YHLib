#include <ansi.h>
#include <combat.h>

#define REN "��" HIW "���ͬ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int ap, dp, damage;
        string msg;
        object weapon;

        if (userp(me) && ! me->query("can_perform/liangyi-jian/ren"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(REN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" REN "��\n");

        if ((int)me->query_skill("liangyi-jian", 1) < 120)
                return notify_fail("�����ǽ���������죬����ʩչ" REN "��\n");

        if ((int)me->query("max_neili") < 1500)
                return notify_fail("���������Ϊ���㣬����ʩչ" REN "��\n");

        if (me->query_skill_mapped("sword") != "liangyi-jian")
                return notify_fail("��û�м������ǽ���������ʩչ" REN "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("��������������������ʩչ" REN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "���г�����âԾ�������Ⱪ������������ƺ������Ҵ���$n"
              HIW "��$n" HIW "������\n��ƫ�󣬼�������ת����ֻ��һɲ������ɲʱϮ"
              "�����ף�\n";

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                me->start_busy(2);
                damage = ap * 4 / 3;
                damage = damage / 2 + random(damage * 2 / 3);

                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
                                           HIR "$n" HIR "��æ��ת��ȴ����$N" HIR
                                           "��" + weapon->name() + HIR "������ת"
                                           "����ʱ���ض�����Ѫ��Ȫӿ��\n" NOR);
                me->add("neili", -180);
        } else
        {
                me->start_busy(3);
                msg += CYN "����$p" CYN "����һЦ��������ת���㿪��$P"
                       CYN "��ת�Ľ�ʽ������δ�ˡ�\n" NOR;
        }
        message_combatd(msg, me, target);
        return 1;
}
