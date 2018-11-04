#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define TONG "��" HIW "������" NOR "��"
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp, damage;

        if (userp(me) && ! me->query("can_perform/yinhu-zhang/lao"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail(TONG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "staff")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" TONG "��\n");

        if ((int)me->query_skill("force") < 140)
                return notify_fail("����ڹ���򲻹�������ʩչ" TONG "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" TONG "��\n");

        if ((int)me->query_skill("yinhu-zhang", 1) < 100)
                return notify_fail("�������ȷ���򲻹�������ʩչ" TONG "��\n");

        if (me->query_skill_mapped("staff") != "yinhu-zhang")
                return notify_fail("��û�м��������ȷ�������ʩչ" TONG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIM "\n$N" HIM "һ�����ȣ���Ȼ���ڿն���ʩ�����С�" HIW "����"
              "��" HIM "��������" + weapon->name() + HIM "������������ƾ��˵�"
              "Ϯ��$n" HIM "��\n" NOR;

        message_sort(msg, me, target);

        ap = me->query_skill("staff");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap / 2);

                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 75,
                                           HIR "$n" HIR "��ȫ�޷�����������ʵ��ֻ"
                                           "�����ء���һ�����ѱ�$N" HIR "���м��\n" NOR);
                me->start_busy(3);
                me->add("neili", -180);
        } else 
        {
                msg = CYN "����$n" CYN "�����мܣ������ұܣ��ò���"
                       "�׵ֵ�ס��$N" CYN "�Ĺ�����\n" NOR;
                me->start_busy(4);
                me->add("neili", -100);
        }
        message_vision(msg, me, target);

        return 1;
}
