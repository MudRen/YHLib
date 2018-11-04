#include <ansi.h>
#include <combat.h>

#define PAN "��" HIR "��������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/kuimang-dao/pan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(PAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" PAN "��\n");

        if ((int)me->query_skill("force") < 60)
                return notify_fail("����ڹ���򲻹�������ʩչ" PAN "��\n");

        if ((int)me->query_skill("kuimang-dao", 1) < 40)
                return notify_fail("������������������ң�����ʩչ" PAN "��\n");

        if (me->query_skill_mapped("blade") != "kuimang-dao")
                return notify_fail("��û�м�����������������ʩչ" PAN "��\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("�����������������ʩչ" PAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIR "$N" HIR "����" + weapon->name() +  HIR "��ת��������Ȼֻ����"
              "��һ������������$n" HIR "бб��ȥ��\n" NOR;

        ap = me->query_skill("blade");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
	{
		damage = ap / 3 + random(ap / 3);
                me->add("neili", -30);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 20,
                                           HIR "$n" HIR "΢΢һ㶼䣬�ѱ�$N" HIR
                                           "������У�����һ����Ѫ������˿ڣ�\n" NOR);
		me->start_busy(2);
	} else 
	{
		msg += CYN "����$p" CYN "΢΢һЦ�����ӳ�һ��ƫ�������㿪$P"
                       CYN "��һ����\n" NOR;
                me->add("neili", -10);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}
