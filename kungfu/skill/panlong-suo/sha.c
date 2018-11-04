#include <ansi.h>

#define SHA "��" HIR "������ɱ" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon;
        string msg;
        int count;
        int i;

        if (userp(me) && ! me->query("can_perform/panlong-suo/sha"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail(SHA "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" SHA "��\n");

	if ((int)me->query_skill("force") < 220)
		return notify_fail("����ڹ���򲻹�������ʩչ" SHA "��\n");

	if ((int)me->query_skill("panlong-suo", 1) < 180)
		return notify_fail("��������������������ң�����ʩչ" SHA "��\n");

        if (me->query_skill_mapped("whip") != "panlong-suo")
                return notify_fail("��û�м�������������������ʩչ" SHA "��\n");

	if ((int)me->query("neili") < 300)
		return notify_fail("�����������������ʩչ" SHA "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIR "ͻȻ��$N" HIR "�͵�������ϣ�����" + weapon->name() +
              HIR "��ת�����Ʋ�Ҫ�������$n" HIR "�͹���ȥ��\n" NOR;

        if (random(me->query_skill("whip")) > target->query_skill("parry") / 2)
        {
                msg += HIR "$n" HIR "�䲻��������ʱ��æ���ң��м���"
                       "ɢ����æ�����Եֵ���\n" NOR;
                count = me->query_skill("whip") / 20;
        } else
        {
                msg += HIC "$n" HIC "�ĵ�һ������æȫ��Ӧ�ԣ�������"
                       "˿�����⡣\n" NOR;
                count = 0;
        }

	message_combatd(msg, me, target);
	me->add("neili", -180);
        me->add_temp("apply/attack", count);

        for (i = 0; i < 6; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(1);
        	COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -count);
	me->start_busy(1 + random(6));
	return 1;
}
