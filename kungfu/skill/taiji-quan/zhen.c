#include <ansi.h>
#include <combat.h>

#define ZHEN "��" HIW "���־�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, ap, dp, damage;
	string msg;

        if (userp(me) && ! me->query("can_perform/taiji-quan/zhen"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHEN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(ZHEN "ֻ�ܿ���ʩչ��\n");

        skill = me->query_skill("taiji-quan", 1);

        if (skill < 150)
                return notify_fail("���̫��ȭ�ȼ�����������ʩչ" ZHEN "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����������������ʩչ" ZHEN "��\n");
 
        if (me->query_skill_mapped("unarmed") != "taiji-quan")
                return notify_fail("��û�м���̫��ȭ������ʩչ" ZHEN "��\n");

        if (me->query_skill_prepared("unarmed") != "taiji-quan")
                return notify_fail("������û��׼��ʹ��̫��ȭ���޷�ʹ��" ZHEN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "$N" HIW "ʹ��̫��ȭ�����־������ָߣ����ֵͣ���Ȼ"
              "��Ȧ����ͼ����������$n" HIW "��\n" NOR;
	me->add("neili", -50);

	if (random(me->query_skill("force")) > target->query_skill("force") / 2)
	{
		me->start_busy(3);
		target->start_busy(random(3));
		
		damage = (int)me->query_skill("force", 1);
                damage = damage / 2 + random(damage / 2);
		
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 50,
                                           HIR "ֻ��$N" HIR "��һȭ�仯�޷�������"
                                           "����$n" HIR "���е���·��һȭ��������"
                                           "��\n:����@?");
	} else 
	{
		me->start_busy(3);
		msg += CYN "����$p" CYN "������$P"
                       CYN "����ͼ����û���ϵ���\n" NOR;
	}
	message_combatd(msg, me, target);
	return 1;
}
