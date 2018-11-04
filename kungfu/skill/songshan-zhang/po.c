#include <ansi.h>
#include <combat.h>

#define PO "��" HIW "��ɽ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/songshan-zhang/po"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(PO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(PO "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("songshan-zhang", 1) < 30)
                return notify_fail("����ɽ�Ʒ�������죬����ʩչ" PO "��\n");

        if (me->query_skill_prepared("strike") != "songshan-zhang")
                return notify_fail("��û��׼����ɽ�Ʒ�������ʩչ" PO "��\n");

        if (me->query_skill("force") < 40)
                return notify_fail("����ڹ���Ϊ����������ʩչ" PO "��\n");

        if ((int)me->query("neili") < 120)
                return notify_fail("�����ڵ���������������ʩչ" PO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("strike");
        dp = target->query_skill("parry");

        msg = HIC "\n$N" HIC "���Ƹ߾٣�ʩһ�С�" HIW "��ɽ��"
              HIC "�������ټ��죬����һ������������£�����$n\n" 
              HIC "��" NOR;
        
        message_sort(msg, me, target);

        if (ap / 2 + random(ap) > dp)
        {
                damage = (int)me->query_skill("songshan-zhang", 1);
                damage += random(damage / 2);

                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30,
                                          HIR "$N" HIR "���ּȿ죬��λ���棬$n"
                                          HIR "���ܲ�����ȴ�����ơ�\n" NOR);

                me->add("neili", -100);
	        me->start_busy(2 + random(2));                                         
        } else
        {
                msg = CYN "$n" CYN "���Ų�æ���Կ��죬��$N"
                      CYN "���л�ȥ��\n" NOR;

                me->add("neili", -30);
	        me->start_busy(2 + random(3));
        }
        message_vision(msg, me, target);
        return 1;
}
