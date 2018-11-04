#include <ansi.h>
#include <combat.h>

#define SHENG "��" HIW "̫������" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
 
        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/wudang-jian/sheng"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHENG "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" SHENG "��\n");

        if (me->query_skill("force") < 80)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" SHENG "��\n");

        if (me->query_skill("wudang-jian", 1) < 60)
                return notify_fail("����䵱������Ϊ����������ʩչ" SHENG "��\n");

        if (me->query_skill_mapped("sword") != "wudang-jian")
                return notify_fail("��û�м����䵱����������ʩչ" SHENG "��\n");

        if (me->query("neili") < 50)
                return notify_fail("��������������������ʩչ" SHENG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "�������������" + weapon->name() +
              HIW "��ת������һ�������Ľ�Ȧ������$n" HIW "��ȥ��\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 3 + random(ap / 2);
                me->add("neili", -30);
                me->start_busy(2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 10,
                                           HIR "$n" HIR "��������һ����������ʱ��$N"
                                           HIR "���У���Ѫֱ����\n" NOR);
        } else
        {
                me->add("neili", -20);
                me->start_busy(3);
                msg += CYN "����$p" CYN "΢΢һЦ������񵲿���$P"
                       CYN "�Ľ��С�\n"NOR;
        }

        message_combatd(msg, me, target);

        return 1;
}
