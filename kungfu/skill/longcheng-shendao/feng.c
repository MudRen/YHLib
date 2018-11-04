#include <ansi.h>
#include <combat.h>

#define FENG "��" HIW "���꽻��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
        int i, attack_time;

        if (userp(me) && ! me->query("can_perform/longcheng-shendao/feng"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
                return notify_fail(FENG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "blade")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" FENG "��\n");

	if ((int)me->query_skill("longcheng-shendao", 1) < 120)
		return notify_fail("��������񵶲�����죬����ʩչ" FENG "��\n");

	if ((int)me->query_skill("force", 1) < 150)
		return notify_fail("����ڹ���Ϊ���㣬����ʩչ" FENG "��\n");

        if (me->query_skill_mapped("blade") != "longcheng-shendao")
                return notify_fail("��û�м��������񵶣�����ʩչ" FENG "��\n");

	if (me->query("neili") < 270)
		return notify_fail("��Ŀǰ����������������ʩչ" FENG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "���һ����ʩ�����С�" HIW "���꽻��" HIC "����"
              "�е�" + weapon->name() + HIC "�����һ����$n" HIC "��ȥ��$n" HIC 
              "��ͬС��һ���ڵ�����Ư��������\n" NOR;

        attack_time = 3;

	ap = me->query_skill("blade");
	dp = target->query_skill("dodge");

        attack_time += random(ap / 40);

        if (attack_time > 7)
                attack_time = 7;

	me->add("neili", -attack_time * 25);

	if (ap / 2 + random(ap) > dp)
	{
		msg += HIR "$n" HIR "��$P" HIR "����������ӿ���Ʋ���"
                      "������$N" HIR "�����������ˡ�\n" NOR;
        } else
        {
                msg += CYN "$n" CYN "��$N" CYN "�⼸������Ѹ���ޱȣ���"
                       "��������ֻ��С��Ӧ����\n" NOR;
        }

        message_combatd(msg, me, target);

        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;

                COMBAT_D->do_attack(me, target, weapon, 20);
        }

	me->start_busy(1 + random(attack_time));

        return 1;
}
