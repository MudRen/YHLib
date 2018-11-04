#include <ansi.h>
#include <combat.h>

#define KAI "��" HIW "�Ƽ���ɽ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/tiexian-quan/tui"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(KAI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(KAI "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("tiexian-quan", 1) < 60)
                return notify_fail("������ȭ��������죬����ʩչ" KAI "��\n");

        if (me->query_skill_mapped("cuff") != "tiexian-quan")
                return notify_fail("��û�м�������ȭ��������ʩչ" KAI "��\n");

        if (me->query_skill_prepared("cuff") != "tiexian-quan")
                return notify_fail("��û��׼������ȭ��������ʩչ" KAI "��\n");

        if (me->query_skill("force") < 80)
                return notify_fail("����ڹ���Ϊ����������ʩչ" KAI "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" KAI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("cuff");
        dp = target->query_skill("parry");

        msg = HIC "\n$N" HIC "��Хһ����ʩ�����С�" HIW "��ɽ��" HIC "����һ"
              "ȭ�ӳ����ƿն��죬ֱ��$n" HIC "���ź��ؿڡ�\n" NOR;
        
        message_sort(msg, me, target);

        if (ap / 2 + random(ap) > dp)
        {
                damage = (int)me->query_skill("henshan-quan", 1);
                damage += random(damage / 2);

                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 40,
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
        message_combatd(msg, me, target);
        return 1;
}
