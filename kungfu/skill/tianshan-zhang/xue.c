// xue.c ��ѩ�׷�

#include <ansi.h>

inherit F_SSERVER;

#define XUE "��" HIW "��ѩ�׷�" NOR "��"
 
int perform(object me, object target)
{
	object weapon;
        string msg;
        int i;

       if (userp(me) && ! me->query("can_perform/tianshan-zhang/fugu"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");
 
        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail(XUE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԣ�\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("�������������\n");

	if ((int)me->query_skill("force", 1) < 100)
		return notify_fail("��Ļ����ڹ���򲻹���\n");

	if ((int)me->query_skill("tianshan-zhang", 1) < 100)
		return notify_fail("�����ɽ�ȷ��������ң��޷�ʹ��" XUE "��\n");

        if (me->query_skill_mapped("staff") != "tianshan-zhang")
                return notify_fail("��û�м�����ɽ�ȷ���ʹ����" XUE "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "$N" HIW "ʹ�����޾�������ѩ�׷ɡ�����ʽ��ù����쳣��\n" NOR;
	message_combatd(msg, me);
	me->add("neili", -120);

        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;
        	COMBAT_D->do_attack(me, target, weapon, 0);
        }

	me->start_busy(1 + random(3));
	return 1;
}
