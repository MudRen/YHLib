#include <ansi.h>
#include <combat.h>

#define FEN "��" HIW "��������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int ap, dp, damage;
        string msg;

        if (userp(me) && ! me->query("can_perform/xiantian-gong/fen"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(FEN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(FEN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("xiantian-gong", 1) < 240)
                return notify_fail("������칦��Ϊ����������ʩչ" FEN "��\n");

        if (me->query("max_neili") < 4000)
                return notify_fail("���������Ϊ���㣬����ʩչ" FEN "��\n");

        if (me->query_skill_mapped("unarmed") != "xiantian-gong")
                return notify_fail("��û�м������칦Ϊȭ�ţ�����ʩչ" FEN "��\n");

        if (me->query_skill_mapped("force") != "xiantian-gong")
                return notify_fail("��û�м������칦Ϊ�ڹ�������ʩչ" FEN "��\n");

        if (me->query_skill_prepared("unarmed") != "xiantian-gong")
                return notify_fail("��û��׼��ʹ�����칦������ʩչ" FEN "��\n");

        if (me->query("neili") < 600)
                return notify_fail("�����ڵ��������㣬����ʩչ" FEN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "������������������ת������һ�������Ķ�ʱ����һ����"
              "�ţ���$n" HIW "���Ķ�ȥ��\n" NOR;

        ap = me->query_skill("unarmed") +
             me->query_skill("force");

        dp = target->query_skill("parry") +
             target->query_skill("force");

        if (ap / 2 + random(ap) > dp)
        {
                damage = 0;
                if (me->query("max_neili") > target->query("max_neili") * 2)
                {
                	me->start_busy(2);
                        msg += HIR "$n" HIR "��ֱ����䣬$N" HIR "һ��������$p"
                               HIR "���ţ�����������ʱ���Զ��롣\n" NOR "( $n"
                               RED "���˹��أ��Ѿ�������в�����ʱ�����ܶ���"
                               "��" NOR ")\n";
                        damage = -1;
                } else
		{
                	me->start_busy(4);
                	damage = ap / 2 + random(ap);
                	me->add("neili", -500);
                	msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 90,
                        	                   HIR "���$N" HIR "��������$n" HIR "��"
                                                   "�ڣ�����������ʱ͸����룬���������"
                                                   "����Ѫ��\n" NOR);
		}
        } else
        {
                me->start_busy(5);
                me->add("neili", -120);
                msg += CYN "����$p" CYN "ʶ����$P"
                       CYN "��һ�У�ббһԾ��ܿ�����\n" NOR;
        }
        message_combatd(msg, me, target);

        if (damage < 0)
                target->die(me);

        return 1;
}
