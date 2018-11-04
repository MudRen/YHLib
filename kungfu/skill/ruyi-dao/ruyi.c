#include <ansi.h>
#include <combat.h>

#define RUYI "��" HIC "��������" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon;
        string msg;
        int i;
 
        if (userp(me) && ! me->query("can_perform/ruyi-dao/ruyi"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail(RUYI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (!objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "blade")
                return notify_fail("����������ԣ�����ʩչ" RUYI "��\n");

	if ((int)me->query("neili") < 250)
		return notify_fail("�����������������ʩչ" RUYI "��\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("����ڹ���򲻹�������ʩչ" RUYI "��\n");

	if (me->query_skill("ruyi-dao", 1) < 100)
		return notify_fail("������⵶���������ң�����ʩչ" RUYI "��\n");

        if (me->query_skill_mapped("blade") != "ruyi-dao")
                return notify_fail("��û�м������⵶��������ʩչ" RUYI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "ʹ����ң����������������������Ȼ����ޱȣ����Ī�⣡\n" NOR;
	message_combatd(msg, me);
	me->add("neili", -120);

        for (i = 0; i < 6; i++)
        {
                if (! me->is_fighting(target))
                        break;
        	COMBAT_D->do_attack(me, target, weapon, 0);
        }

	me->start_busy(1 + random(6));

	return 1;
}
