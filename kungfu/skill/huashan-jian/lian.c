// jianzhang.c  ����������

#include <ansi.h>

inherit F_SSERVER;

#define LIAN "��" HIW "����������" NOR "��"
 
int perform(object me, object target)
{
	object weapon;
        string msg;
        int i;
	int count;
 
        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

        if (userp(me) && ! me->query("can_perform/huashan-jian/lian"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target || ! me->is_fighting(target))
		return notify_fail(LIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԣ�\n");

	if ((int)me->query("neili") < 160)
		return notify_fail("��������������޷�ʩչ" LIAN "��\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("����ڹ���򲻹�������ʩչ" LIAN "��\n");

	if ((int)me->query_skill("huashan-jian", 1) < 50)
		return notify_fail("��Ļ�ɽ�����������ң��޷�ʩչ" LIAN "��\n");

        if (me->query_skill_mapped("sword") != "huashan-jian")
                return notify_fail("��û�м�����ɽ�������޷�ʩչ" LIAN "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "$N" HIY "ʹ����ɽ�ɾ�����" HIW "����������" HIY"��������Ȼ�ӿ죡\n" NOR;
	message_combatd(msg, me);
	me->add("neili", -120);

	count = me->query_skill("sword") / 10;
	me->add_temp("apply/attack", count);

        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (! target->is_busy() && random(3) == 1)
                        target->start_busy(1);
        	COMBAT_D->do_attack(me, target, weapon, 0);
        }

	me->add_temp("apply/attack", -count);
	me->start_busy(1 + random(3));
	return 1;
}
