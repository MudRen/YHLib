#include <ansi.h>

#define CANG "��" HIW "�˷��ص���" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon;
        string msg;
        int count;
        int i;

        if (userp(me) && ! me->query("can_perform/hujia-daofa/cang"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail(CANG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" CANG "��\n");

	if ((int)me->query_skill("force") < 250)
		return notify_fail("����ڹ���򲻹�������ʩչ" CANG "��\n");

	if ((int)me->query_skill("hujia-daofa", 1) < 180)
		return notify_fail("��ĺ��ҵ����������ң�����ʩչ" CANG "��\n");

        if (me->query_skill_mapped("blade") != "hujia-daofa")
                return notify_fail("��û�м������ҵ���������ʩչ" CANG "��\n");

	if ((int)me->query("neili") < 200)
		return notify_fail("�����������������ʩչ" CANG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "$N" HIW "����Գ�ۣ�ʩ����ս�˷��ص�ʽ�������е�" + weapon->name() +
              HIW "�������£��仯Ī�⣬������$n" HIW "����Ҫ����\n" NOR;

        if (random(me->query_skill("blade")) > target->query_skill("parry") / 2)
        {
                msg += HIY "$n" HIY "������ʵ���Ǳ��Ī�⣬���ɵ���"
                       "�����⣬��ʽ��ʱ����������\n" NOR;
                count = me->query_skill("hujia-daofa", 1) / 4;
        } else
        {
                msg += HIC "$n" HIC "�ĵ�΢΢һ����������С�Ľ��С�\n" NOR;
                count = 0;
        }

	message_combatd(msg, me, target);
	me->add("neili", -220);
        me->add_temp("apply/attack", count);

        for (i = 0; i < 8; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(1);
        	COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -count);
	me->start_busy(1 + random(8));
	return 1;
}
