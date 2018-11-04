#include <ansi.h>
#include <combat.h>

#define ZHUAN "��" HIW "��ת����" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp, i;

        if (userp(me) && ! me->query("can_perform/murong-jian/xing"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
                return notify_fail(ZHUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" ZHUAN "��\n");

	if ((int)me->query_skill("murong-jian", 1) < 80)
		return notify_fail("���Ľ�ݽ���������죬����ʩչ" ZHUAN "��\n");

        if (me->query_skill_mapped("sword") != "murong-jian")
                return notify_fail("��û�м���Ľ�ݽ���������ʩչ" ZHUAN "��\n");

	if ((int)me->query_skill("dodge") < 120)
		return notify_fail("����Ṧ��Ϊ�������޷�ʩչ" ZHUAN "��\n");

	if (me->query("neili") < 200)
		return notify_fail("��Ŀǰ����������������ʩչ" ZHUAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIM "$N" HIM "ʹ��Ľ�ݼҾ�����" HIW "��ת����" HIM "��������"
              + weapon->name() + HIM "���ϱ������Ƿ�λ������������仯Ī�⣡\n" NOR;

	me->add("neili", -210);

        message_vision(msg, me, target);

        for (i = 0; i < 7; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (! target->is_busy() && random(2) == 1)
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, weapon, 13);
        }

	me->start_busy(3 + random(5));

        return 1;
}
