#include <ansi.h>
#include <combat.h>

#define SHI "��" HIR "������" NOR "��"

string final(object me, object target, int damage);

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/wudu-shenzhang/shi"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_skill("force") < 200)
                return notify_fail("����ڹ������������ʩչ" SHI "��\n");

        if ((int)me->query_skill("wudu-shenzhang", 1) < 150)
                return notify_fail("����嶾���Ʋ�����죬����ʩչ" SHI "��\n");

        if (me->query_skill_prepared("strike") != "wudu-shenzhang")
                return notify_fail("������û��׼���嶾���ƣ�����ʩչ" SHI "��\n");

        if (me->query("neili") < 120)
                return notify_fail("�����������������ʩչ" SHI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "��������������˫��֮�䣬ֻ��˫��΢΢�����Ϲ⣬��"
              "������$n��\n" NOR;

        ap = me->query_skill("strike");
        dp = target->query_skill("force");
        if (ap / 2 + random(ap) > dp)
        {

                damage = ap / 2 + random(ap / 2);
                msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 60,
                                          (: final, me, target, damage :));

                me->start_busy(2 + random(3));
        } else
        {
                msg += CYN "����$p" CYN "�����ֿ죬����һ��$P"
                       CYN "�Ѷ��$N���С�\n" NOR;
                me->start_busy(3);
                target->start_busy(1);
        }
        message_combatd(msg, me, target);

        return 1;
}

string final(object me, object target, int damage)
{
        int ap, dp;

        ap = me->query_skill("strike");
        dp = target->query_skill("force");

        target->affect_by("wudu_shenzhang",
                ([ "level" : me->query("jiali") + random(me->query("jiali")),
                   "id"    : me->query("id"),
                   "duration" : ap / 70 + random(ap / 30) ]));

        target->receive_wound("jing", 8 + random(4), me);

        return  HIR "ֻ��$n" HIR "��$N" HIR "һ������"
                "�����˼�����ȴ����ɫ��΢΢���ڡ�\n" NOR;

}