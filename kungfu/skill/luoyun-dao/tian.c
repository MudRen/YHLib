#include <ansi.h>
#include <combat.h>

#define LIAN "��" HIW "�쵶����ʽ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg, wn;
	int ap, dp;
        int i, attack_time;

        if (userp(me) && ! me->query("can_perform/luoyun-dao/tian"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
                return notify_fail(LIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "blade")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" LIAN "��\n");

	if ((int)me->query_skill("luoyun-dao", 1) < 100)
		return notify_fail("������Ƶ���������죬����ʩչ" LIAN "��\n");

        if (me->query_skill_mapped("blade") != "luoyun-dao")
                return notify_fail("��û�м������Ƶ���������ʩչ" LIAN "��\n");

	if (me->query("neili") < 300)
		return notify_fail("��Ŀǰ����������������ʩչ" LIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();

	msg = HIY "\n$N" HIY "������" + wn + HIY "������ǰ��ʩ�����С�" HIW "��"
              "������ʽ" HIY "����$N����Ȼ�ӿ죬����" + wn + HIY "�����ӳ�����"
              "�������ڰ�Ϯ��$n" HIY "��" NOR;

        message_sort(msg, me, target);

        attack_time = 4;

	ap = me->query_skill("blade");
	dp = target->query_skill("dodge");

        attack_time += random(ap / 40);

        if (attack_time > 8)
                attack_time = 8;

	me->add("neili", -attack_time * 20);

	if (ap / 2 + random(ap) > dp)
	{
		msg = HIG "$n" HIG "��$P" HIG "����������ӿ���Ʋ���"
                     "������$N" HIG "�����������ˡ�\n" NOR;
        } else
        {
                msg = HIC "$n" HIC "��$N" HIC "�⼸������Ѹ���ޱȣ���"
                      "��������ֻ��С��Ӧ����\n" NOR;
        }

        message_combatd(msg, me, target);

        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;

                COMBAT_D->do_attack(me, target, weapon, 0);
        }

	me->start_busy(1 + random(attack_time));

        return 1;
}
