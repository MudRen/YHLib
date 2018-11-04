#include <ansi.h>
#include <combat.h>

#define LIAN "��" HIY "��������" NOR "��"
 
inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, damage;

        if (userp(me) && ! me->query("can_perform/wusheng-zhao/lian"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(LIAN "ֻ����ս���жԶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("�������ֲ���ʹ��" LIAN "��\n");

        skill = me->query_skill("wusheng-zhao", 1);

        if (skill < 120)
                return notify_fail("�����ʥ��צ�ȼ�����������ʩչ" LIAN "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����������������ʩչ" LIAN "��\n");
 
        if (me->query_skill_mapped("claw") != "wusheng-zhao") 
                return notify_fail("��û�м�����ʥ��צ������ʩչ" LIAN "��\n");

        if (me->query_skill_prepared("claw") != "wusheng-zhao") 
                return notify_fail("��û��׼��ʹ����ʥ��צ������ʩչ" LIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "����һչ������$n" HIY "��ǰ����Ȼʩչ����"
              "����������˫צ����������⣬ֱ��$n" HIY "����Ҫ����\n" NOR;
 
        ap = me->query_skill("claw");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -150);
                damage = 60 + ap / 5 + random(ap / 5);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30,
                                           HIR "$p" HIR "�����ֿ��������������$P"
                                           HIR "��ץ����ʱ��Ѫ�ɽ����޷�������\n" NOR);
                me->start_busy(1);
                if (ap / 3 + random(ap) > dp && ! target->is_busy())
                        target->start_busy(ap / 25 + 2);
        } else
        {
                msg += CYN "����$p" CYN "�Ŀ�����$P" CYN
                       "����ʽ�������һһ��⣬û¶���������\n" NOR;
                me->add("neili",-50);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}
