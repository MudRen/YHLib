#include <ansi.h>
#include <combat.h>

#define KAI "��" HIY "����ٵ�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;

        if (userp(me) && ! me->query("can_perform/pangu-qishi/kai"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(KAI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "hammer")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" KAI "��\n");

        if (me->query_skill("force") < 300)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" KAI "��\n");

        if (me->query_skill("pangu-qishi", 1) < 180)
                return notify_fail("����̹�������Ϊ����������ʩչ" KAI "��\n");

        if (me->query("neili") < 400)
                return notify_fail("�����������������ʩչ" KAI "��\n");

        if (me->query_skill_mapped("hammer") != "pangu-qishi")
                return notify_fail("��û�м����̹����ƣ�����ʩչ" KAI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = WHT "$N" WHT "һ���Ϻȣ�����" + weapon->name() +
              WHT "��ɽ��Ρ�ţ�Я�ſ���ٵ�֮����$n" WHT "�������£�\n" NOR;

        ap = me->query_skill("hammer") + me->query("str") * 10;
        dp = target->query_skill("force") + target->query("con") * 10;

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap);
                me->add("neili", -500);
                me->start_busy(5);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 80,
                                           HIR "$n" HIR "��ܲ�������$N" HIR "��"
                                           "�������ؿڣ���ʱһ�����죬���ݰ����"
                                           "��ɳ�ȥ��\n" NOR);
        } else
        {
                me->add("neili", -300);
                me->start_busy(6);
                msg += HIC "����$n" HIC "�����ĵ���$N" HIC "������"
                       "�ľ��������а�������ʱ���������Ρ�\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
