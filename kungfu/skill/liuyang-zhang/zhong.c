#include <ansi.h>
#include <combat.h>

#define ZHONG "��" HIW "������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/liuyang-zhang/zhong"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHONG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_skill("force") < 200)
                return notify_fail("����ڹ������������ʩչ" ZHONG "��\n");

        if ((int)me->query_skill("liuyang-zhang", 1) < 150)
                return notify_fail("�����ɽ�����Ʋ�����죬����ʩչ" ZHONG "��\n");

        if (me->query_skill_mapped("strike") != "liuyang-zhang")
                return notify_fail("��û�м�����ɽ�����ƣ�����ʩչ" ZHONG "��\n");

        if (me->query_skill_prepared("strike") != "liuyang-zhang")
                return notify_fail("������û��׼����ɽ�����ƣ�����ʩչ" ZHONG "��\n");

        if (me->query("neili") < 100)
                return notify_fail("�����������������ʩչ" ZHONG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "�����������������е�ˮ¶Ϊ�������������У��̶���"
              "����磬��ƮƮ����$n" HIW "���䡣\n";

        ap = me->query_skill("strike");
        dp = target->query_skill("force");
        if (ap / 2 + random(ap) > dp)
        {
                target->receive_wound("jing", 10 + random(5), me);
                damage = ap / 2 + random(ap / 2);
                msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 50,
                                           HIR "ֻ��$n" HIR "��$N" HIR "һ������"
                                           "������������һ����$P" HIR "��ö������"
                                           "������$p" HIR "���ڣ�\n" NOR);
                target->affect_by("ss_poison",
                               ([ "level" : me->query("jiali") + random(me->query("jiali")),
                                  "id"    : me->query("id"),
                                  "duration" : ap / 70 + random(ap / 30) ]));
                me->start_busy(1 + random(4));
        } else
        {
                msg += CYN "����$p" CYN "������������$P"
                       CYN "��ö������Ӳ����������⡣\n" NOR;
                me->start_busy(3);
                target->start_busy(1);
        }
        message_combatd(msg, me, target);

        return 1;
}

