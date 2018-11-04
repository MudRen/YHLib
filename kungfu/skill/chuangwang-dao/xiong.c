#include <ansi.h>
#include <combat.h>

#define XIONG "��" HIY "�۰�Ⱥɽ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/chuangwang-dao/xiong"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(XIONG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" XIONG "��\n");

        if ((int)me->query_skill("force") < 60)
                return notify_fail("����ڹ���򲻹�������ʩչ" XIONG "��\n");

        if ((int)me->query_skill("chuangwang-dao", 1) < 40)
                return notify_fail("��Ĵ��������������ң�����ʩչ" XIONG "��\n");

        if (me->query_skill_mapped("blade") != "chuangwang-dao")
                return notify_fail("��û�м�����������������ʩչ" XIONG "��\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("�����������������ʩչ" XIONG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "$N" HIY "һ��ŭ�ȣ�����" + weapon->name() +  HIY "�����ն"
              "�����������ʱ����������$n" HIY "��\n" NOR;

        ap = me->query_skill("blade");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
	{
		damage = ap / 3 + random(ap / 3);
                me->add("neili", -30);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 15,
                                           HIR "$n" HIR "�������ɣ����뱻$N" HIR
                                           "һ�����У���ʱһ���Һ���Ѫ���岽��\n" NOR);
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
