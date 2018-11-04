#include <ansi.h>
#include <combat.h>

#define KAI "��" HIY "����ٵ�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;
        object weapon;

        if (userp(me) && ! me->query("can_perform/yinsuo-jinling/kai"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(KAI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "whip")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" KAI "��\n");

        if ((int)me->query_skill("yinsuo-jinling", 1) < 140)
                return notify_fail("���������幻��죬����ʩչ" KAI "��\n");

        if (me->query_skill_mapped("whip") != "yinsuo-jinling")
                return notify_fail("��û�м����������壬����ʩչ" KAI "��\n");

        if (me->query_skill("force") < 180)
                return notify_fail("����ڹ���Ϊ����������ʩչ" KAI "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�����ڵ���������������ʩչ" KAI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("whip");
        dp = target->query_skill("parry");

        msg = HIW "\n$N" HIW "��Хһ�����ۿն���ʩ�����С�" HIY "����ٵ�" HIW
              "��������" +weapon->name() + HIW "���糤���������������ٿն��£���"
              "��$n��" NOR;

        message_sort(msg, me, target);

        if (ap / 2 + random(ap) > dp)
        {
                damage = (int)me->query_skill("yinsuo-jinling", 1);
                damage += random(damage / 2);

                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
                                           HIR "\n����$N" HIR "������飬���ư��磬"
                                           "$n" HIR "������΢һ�����ҽ�һ������"
                                           "ʱ��Ѫ���ܡ�\n" NOR);

                me->start_busy(2 + random(3));
                me->add("neili", -220);
        } else
        {
                msg = CYN "\n$n" CYN "��$N" CYN "����Ϯ��������"
                      "��ӯ��ֻ�����һ�ݣ��Ŷ����һ�ޡ�\n" NOR;

                me->start_busy(4);
                me->add("neili", -100);
        }
        message_vision(msg, me, target);
        return 1;
}
