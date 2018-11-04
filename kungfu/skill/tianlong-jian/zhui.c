#include <ansi.h>
#include <combat.h>

#define ZHUI "��" HIM "����˫׶" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp, damage;
        object ob;

        if (userp(me) && ! me->query("can_perform/tianlong-jian/zhui"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHUI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" ZHUI "��\n");

        if ((int)me->query_skill("tianlong-jian", 1) < 120)
                return notify_fail("��������������̫ǳ������ʩչ" ZHUI "��\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���Ϊ̫ǳ������ʩչ" ZHUI "��\n");

        if ((int)me->query("max_neili") < 1500)
                return notify_fail("���������Ϊ̫ǳ������ʩչ" ZHUI "��\n");

        if (me->query_skill_mapped("sword") != "tianlong-jian")
                return notify_fail("��û�м�����������������ʩչ" ZHUI "��\n");

        if ((int)me->query("neili", 1) < 500)
                return notify_fail("�����ڵ��������㣬������ʩչ" ZHUI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

	damage = ap / 3 + random(ap / 2);

        msg = HIM "$N" HIM "һ����Х������" + weapon->name() + HIM "������ת������"
              "��׶�������ʱ����һ�����磬��$n" HIM "��ȥ��\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 30,
                                           HIR "$n" HIR "�мܲ�ס�����һ����$N"
                                           HIR "���е�" + weapon->name() + HIR
                                           "��ʱ�������룬��Ѫ�Ľ���\n" NOR);
        } else
        {
                msg += CYN "����$n" CYN "�����񵲣����ڼܿ���$N"
                       CYN "����һ����\n" NOR;
        }

        msg += HIM "\n$N" HIM "�漴�齣��ת���������ϣ�����" + weapon->name() + HIM 
               "����һ�����ּ�����һ�����о�����$n" HIM "��\n" NOR;
        if (ap * 2 / 5 + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40,
                                           HIR "$n" HIR "��æ������ˣ���ֻ��$N"
                                           HIR + weapon->name() + HIR "��âһ��"
                                           "���ؿڱ����һ��Ѫ����\n" NOR);
        } else
        {
        	msg += CYN "����$n" CYN "�������������һԾ���𣬱ܿ���$N"
                       CYN "��ɱ�š�\n" NOR;
	}
        me->start_busy(2 + random(3));
        me->add("neili", -350);
        message_combatd(msg, me, target);
        return 1;
}
