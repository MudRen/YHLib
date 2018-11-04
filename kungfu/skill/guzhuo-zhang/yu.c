#include <ansi.h>
#include <combat.h>

#define YU "��" HIR "��������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/guzhuo-zhang/yu"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(YU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(YU "ֻ�ܿ���ʹ�á�\n");

        if ((int)me->query_skill("force") < 260)
                return notify_fail("���ڹ���Ϊ����������ʩչ" YU "��\n");

        if ((int)me->query("max_neili") < 2800)
                return notify_fail("��������Ϊ����������ʩչ" YU "��\n");

        if ((int)me->query_skill("guzhuo-zhang", 1) < 180)
                return notify_fail("���׾�Ʒ���򲻹�������ʩչ" YU "��\n");

        if (me->query_skill_mapped("strike") != "guzhuo-zhang")
                return notify_fail("��û�м�����׾�Ʒ�������ʩչ" YU "��\n");

        if (me->query_skill_prepared("strike") != "guzhuo-zhang")
                return notify_fail("��û��׼����׾�Ʒ�������ʩչ" YU "��\n");

        if ((int)me->query("neili") < 600)
                return notify_fail("��������������������ʩչ" YU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "���������ŷ������һ����˫����$n" HIR "ƽƽ��"
              "ȥ��������ʵ�޻������ް�㻨�ɿ��ԡ�\n" NOR;  

        ap = me->query_skill("strike") + me->query("int") * 10;
        dp = target->query_skill("force") + target->query("int") * 10;

        me->start_busy(3);

        if (ap / 2 + random(ap) > dp)
        { 
                damage = ap + random(ap / 2);
                me->add("neili", -300);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 70,
                                           HIR "$n" HIR "���Ʋ�͸������ʵ��$N" HIR
                                           "˫������$p" HIR "ǰ�أ������꿦�ꡱ��"
                                           "�����������߹ǡ�\n" NOR);
        } else
        {
                msg += CYN "$n" CYN "��$N" CYN "�������ƷǷ�������"
                       "�����мܣ�����������Ծ������\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

