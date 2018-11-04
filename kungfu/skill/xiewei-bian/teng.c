// tengshe.c ����

#include <ansi.h>
#include <combat.h>

#define TENGSHE "��" WHT "���߾�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
 
        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/xiewei-bian/tengshe"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(TENGSHE "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query_skill("xiewei-bian", 1) < 100)
                return notify_fail("��ʹ�õ��������ԣ��޷�ʩչ" TENGSHE "��\n");

        if (me->query("neili") < 200)
                return notify_fail("��������������޷�ʩչ" TENGSHE "��\n");

        if (me->query_skill_mapped("whip") != "xiewei-bian")
                return notify_fail("��û�м���Ыβ�ޣ��޷�ʩչ" TENGSHE "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = WHT "$N" WHT "��Ȼʩչ�������ߡ�������������һ����" + weapon->name() +
              WHT "��ʱ�εص�����ͬ����һ����ȻϮ��$n" + WHT "��\n" NOR;

        ap = me->query_skill("whip") + me->query_skill("force");
        dp = target->query_skill("force") + target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 5 + random(ap / 4);
                me->add("neili", -150);
                me->start_busy(1);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
                                           HIR "Ȼ��$n" HIR "δ�ܿ�����ͼ��һ���Һ���"
                                           + weapon->name() + HIR "�޶���û�����ڰ��"
                                           "����ʱ����������\n" NOR);
        } else
        {
                me->add("neili", -100);
                me->start_busy(3);
                msg += CYN "����$p" CYN "����������������ס��"
                       CYN "$P" CYN "�����Ī���һ����\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
