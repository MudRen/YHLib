#include <ansi.h>
#include <combat.h>

#define TIAN "��" HIW "�����޹�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
        int ap, dp, count;
        int i, attack_time;

        if (userp(me) && ! me->query("can_perform/dagou-bang/tian"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(TIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "staff")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" TIAN "��\n");

        if (me->query_skill("dagou-bang", 1) < 220)
		return notify_fail("��򹷰���������죬����ʩչ" TIAN "��\n");

        if (me->query_skill_mapped("staff") != "dagou-bang")
                return notify_fail("��û�м����򹷰���������ʩչ" TIAN "��\n");

	if ((int)me->query_skill("force") < 300)
		return notify_fail("����ڹ�����㣬����ʩչ" TIAN "��\n");

        if (me->query("neili") < 500)
                return notify_fail("�����ڵ���������������ʩչ" TIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "$N" HIW "����" + weapon->name() + HIW "һ����"
              "���������������ǧ�ٸ����ƣ���������$n" HIW "����"
              "���С�\n" NOR;

        ap = me->query_skill("staff") +
             me->query_skill("martial-cognize");

        dp = target->query_skill("dodge") +
             target->query_skill("martial-cognize");

        attack_time = 5;

        if (ap / 2 + random(ap) > dp)
        {
                msg += HIR "$n" HIR "ֻ���ۻ����ң���������˷�������"
                       "Ӱ���ĵ׺���������м�ɢ�ҡ�\n" NOR;
                count = ap / 8;
                me->add_temp("apply/attack", count);
                me->add_temp("apply/damage", count / 2);
                attack_time += random(ap / 45);
        } else
        {
                msg += HIY "$n" HIY "ֻ����ǰһ������������˷�������"
                       "Ӱ����æ����������ϸ�мܡ�\n" NOR;
                count = 0;
        }
        message_combatd(msg, me, target);

        if (attack_time > 9)
                attack_time = 9;

        me->add("neili", -attack_time * 30);

        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;

                COMBAT_D->do_attack(me, target, weapon, 0);
        }
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/damage", -count / 2);
        me->start_busy(1 + random(attack_time));

        return 1;
}
