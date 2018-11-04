#include <ansi.h>
#include <combat.h>

#define TAN "��" HIW "����̽צ" NOR "��"
 
inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, damage;

        if (userp(me) && ! me->query("can_perform/panlong-zhao/tan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(TAN "ֻ����ս���жԶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("�������ֲ���ʹ��" TAN "��\n");

        skill = me->query_skill("panlong-zhao", 1);

        if (skill < 130)
                return notify_fail("���Խ������צ�ȼ�����������ʩչ" TAN "��\n");
 
        if (me->query_skill_mapped("claw") != "panlong-zhao") 
                return notify_fail("��û�м���Խ������צ������ʩչ" TAN "��\n");

        if (me->query_skill_prepared("claw") != "panlong-zhao") 
                return notify_fail("��û��׼��Խ������צ������ʩչ" TAN "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����������������ʩչ" TAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "������ƣ���$n" HIW "��ȥ����������;��ȴ����Ϊצ��������"
              "�����Ϯ��$n" HIW "����Ҫ����\n" NOR;
 
        ap = me->query_skill("claw");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -150);
                damage = 60 + ap / 3 + random(ap / 3);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 45,
                                           HIR "$p" HIR "���$P" HIR "�����ʯ��"
                                           "��˫ץ�������޴��мܣ���ʱ��ץ��Ѫ���"
                                           "����\n" NOR);
                me->start_busy(1);
        } else
        {
                msg += CYN "����$p" CYN "�Ŀ�����$P" CYN
                       "����ʽ��������мܿ�����û¶���������\n" NOR;
                me->add("neili",-50);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}
