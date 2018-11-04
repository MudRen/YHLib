#include <ansi.h>
#include <combat.h>

#define AO "��" HIY "������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;

        if (userp(me) && ! me->query("can_perform/pichen-jian/ao"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(AO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" AO "��\n");

        if ((int)me->query_skill("pichen-jian", 1) < 100)
                return notify_fail("��ٳ�����������죬����ʩչ" AO "��\n");

        if (me->query_skill_mapped("sword") != "pichen-jian")
                return notify_fail("��û�м����ٳ�����������ʩչ" AO "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����ڵ��������㣬����ʩչ" AO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "һ���Ц��������Χ��ɰ�������" + weapon->name() +
              HIY "Я����ɽ����֮�Ƴ�$n" HIY "��ȥ��\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap / 2);
                me->add("neili", -150);
                me->start_busy(2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 35,
                                           HIR "$n" HIR "�мܲ�����ֻ������������"
                                           "����ؿ�һ���ʹ�����һ����Ѫ��\n" NOR);
        } else
        {
                me->add("neili", -50);
                me->start_busy(3);
                msg += CYN "����" CYN "$n" CYN "���з���������һԾ"
                       "���𣬱ܿ���$N" CYN "�Ľ��С�\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
