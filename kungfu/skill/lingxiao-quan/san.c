#include <ansi.h>
#include <combat.h>

#define SAN "��" HIR "�񵹹��������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        string wname;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/lingxiao-quan/san"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("ֻ�п��ֲ���ʩչ" SAN "��\n");

        if (me->query_skill("force") < 250)
                return notify_fail("����ڹ���Ϊ����������ʩչ" SAN "��\n");

        if ((int)me->query_skill("lingxiao-quan", 1) < 180)
                return notify_fail("�������ȭ��������죬����ʩչ" SAN "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("��������������������ʩչ" SAN "��\n");

        if (me->query_skill_mapped("cuff") != "lingxiao-quan")
                return notify_fail("��û�м�������ȭ��������ʩչ" SAN "��\n");

        if (me->query_skill_prepared("cuff") != "lingxiao-quan")
                return notify_fail("������û��׼��ʹ������ȭ��������ʩչ" SAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        damage = (int)me->query_skill("lingxiao-quan", 1) / 2;
        damage += random(damage);

        ap = me->query_skill("cuff");
        dp = target->query_skill("parry");
        msg = HIR "$N" HIR "΢΢һЦ��ʩ�����񵹹����������������̽����ֱ��$n"
              HIR "�󾱡�\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 20,
                                           HIR "$P" HIR "���ּȿ죬��λ���棬$p"
                                           HIR "��αܵã�������$N" HIR "��ס��"
                                           "���ص�ˤ�ڵ��ϣ�\n" NOR);
        } else
        {
                msg += CYN "$p" CYN "���Ʋ����æ������ס���ұۻӳ�����$P"
                       CYN "�ֱۡ�\n" NOR;
        }

        ap = me->query_skill("cuff");
        dp = target->query_skill("dodge");
        msg += "\n" HIR "������$N" HIR "���桱��һ����������Ȼ̽�����������ץ��$n"
               HIR "��ǰ�ء�\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 25,
                                           HIR "$p" HIR "ֻ���ؿ�һ�飬�ѱ�$P"
                                           HIR "ץס�ؿڣ�����˳��һ˦����ʱƽ"
                                           "ƽ���˳�ȥ��\n" NOR);
        } else
        {
                msg += CYN "����$p" CYN "˿����Ϊ$P"
                       CYN "�����������񵲣����Ƚ���һ�мܿ���\n" NOR;
        }

        ap = me->query_skill("cuff");
        dp = target->query_skill("force");
        msg += "\n" HIR "�ּ�$N" HIR "����һ���������������Ȳ����ҽ���ɨ$n"
               HIR "���̣�������Ű�ȥ��\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30,
                                           HIR "���$p" HIR "�Բ����񣬶�ʱ��$P"
                                           HIR "���ڵأ�Ż��һ�����Ѫ��\n" NOR);
        } else
        {
                msg += CYN "Ȼ��$p" CYN "�����������ס���̣�����һ�ϣ�û��$P"
                       CYN "����\n" NOR;
        }
        me->start_busy(2 + random(3));
        me->add("neili", -200);
        message_combatd(msg, me, target);
        return 1;
}
