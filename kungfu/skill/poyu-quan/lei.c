// leidong �׶�����
// by winder 98.12
// modify by rcwiz 2003

#include <ansi.h>

inherit F_CLEAN_UP;

#define LEI "��" HIM "�׶�����" NOR "��"

void remove_effect(object me, int amount);

int perform(object me)
{
	int skill, count, count1;


        if (userp(me) && ! me->query("can_perform/poyu-quan/lei"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if ((int)me->query_temp("lei"))
		return notify_fail("���Ѿ����˹����ˡ�\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("�����ڵ�����������\n");

	skill = me->query_skill("cuff");

	if (skill < 120)
		return notify_fail("�����ʯ����ȭ��Ϊ�������޷�ʩչ" LEI "\n");

	me->add("neili", -400);
	message_combatd(HIM "$N" HIM "��������һ���������϶�ʱ"
                        "������ʢ������Խ��Խ�أ�\n" NOR, me);

	count = skill / 10;

        if (me->is_fighting())
                me->start_busy(2);

	me->add_temp("str", count);
	me->add_temp("dex", count);
	me->set_temp("lei", 1);
	me->start_call_out((: call_other,  __FILE__, "remove_effect", me, count :), skill / 3);

	return 1;
}

void remove_effect(object me, int amount)
{
	if ((int)me->query_temp("lei"))
	{
		me->add_temp("str", -amount);
		me->add_temp("dex", -amount);
		me->delete_temp("lei");
		tell_object(me, CYN "����׶�����������ϣ��������ջص��\n" NOR);
	}
}
