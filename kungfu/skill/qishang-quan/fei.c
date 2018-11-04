// ���־�

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define PO "��" HIR "���Ƿ���" NOR "��"

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
        int ap, dp;

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

        if (userp(me) && ! me->query("can_perform/qishang-quan/fei"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target || ! me->is_fighting(target))
		return notify_fail(PO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if ((int)me->query_skill("qishang-quan", 1) < 160)
		return notify_fail("�������ȭ������죬�޷�ʩչ" PO "��\n");
	                        
	if ((int)me->query_skill("force", 1) < 160)
		return notify_fail("����ڹ���Ϊ���������޷�ʩչ" PO "\n");

        if (me->query("max_neili") < 2200)
                return notify_fail("��������Ϊ���㣬�޷�ʩչ" PO "\n");
			
	if ((int)me->query("neili") < 350)
		return notify_fail("�����������������޷�ʩչ" PO "��\n");

        if (me->query_skill_prepared("cuff") != "qishang-quan")
                return notify_fail("��û��׼��ʹ������ȭ���޷�ʩչ" PO "��\n");

        if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "\n$N" HIY "����һ���𣬽���������˫ȭ֮�ϣ�ʩ�����С�" HIR "���Ƿ���" HIY
              "������ȭƽƽһȭֱ����������ͨһȭ֮���̺��������������ȭδ������������Ȼ"
              "��Ϯ��$n" HIY "��\n" NOR;

        ap = me->query_skill("cuff") + me->query_skill("force");
        dp = target->query_skill("force") + target->query_skill("parry");
	if (ap / 2 + random(ap) > dp)
	{
		damage = ap + random(ap / 2);

                me->add("neili", -320);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 80,
		                           HIR "ֻ�����顱��һ����$N" HIR "һȭ���ô���$n" HIR "��"
                                           "�ڣ�$n" HIR "�ֽ�һ�����³�һ����Ѫ��\n" NOR);
		me->start_busy(2);
	} else 
	{
		msg += HIC "����$p" HIC "�����мܣ�Ӳ�����ĵ�����$P"
                       HIC "��һ�С�\n"NOR;
		me->add("neili", -180);
		me->start_busy(3);
	}
	message_sort(msg, me, target);

	return 1;
}
