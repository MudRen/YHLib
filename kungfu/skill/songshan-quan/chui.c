#include <ansi.h>
#include <combat.h>

#define CHUI "��" HIG "ǧ�ﴸ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/songshan-quan/chui"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(CHUI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(CHUI "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("songshan-quan", 1) < 30)
                return notify_fail("����ɽȭ��������죬����ʩչ" CHUI "��\n");;

        if (me->query_skill_prepared("cuff") != "songshan-quan")
                return notify_fail("��û��׼����ɽȭ��������ʩչ" CHUI "��\n");

        if (me->query_skill("force") < 40)
                return notify_fail("����ڹ���Ϊ����������ʩչ" CHUI "��\n");

        if ((int)me->query("neili") < 120)
                return notify_fail("�����ڵ���������������ʩչ" CHUI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("cuff");
        dp = target->query_skill("parry");

        msg = HIC "\n$N" HIC "˫ȭ�ӳ���ʩһ�С�" HIG "ǧ�ﴸ"
              HIC "����ȭ�ټ��죬��λ��׼��" HIC "��Ϯ$n" HIC "��"
              "�ź��ؿڡ�\n" NOR;
        
        message_sort(msg, me, target);

        if (ap / 2 + random(ap) > dp)
        {
                damage = (int)me->query_skill("songshan-quan", 1);
                damage += random(damage / 2);

                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 35,
                                          HIR "$N" HIR "���ּȿ죬��λ���棬$n"
                                          HIR "���ܲ������ƺ�һ������Ȼ��ȭ��\n" NOR);

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
