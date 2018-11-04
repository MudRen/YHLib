#include <ansi.h>
#include <combat.h>

#define LAN "��" HIG "����������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/henshan-quan/lan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(LAN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("henshan-quan", 1) < 60)
                return notify_fail("���ɽȭ��������죬����ʩչ" LAN "��\n");

        if (me->query_skill_mapped("cuff") != "henshan-quan")
                return notify_fail("��û�м�����ɽȭ��������ʩչ" LAN "��\n");

        if (me->query_skill_prepared("cuff") != "henshan-quan")
                return notify_fail("��û��׼����ɽȭ��������ʩչ" LAN "��\n");

        if (me->query_skill("force") < 80)
                return notify_fail("����ڹ���Ϊ����������ʩչ" LAN "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" LAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("cuff");
        dp = target->query_skill("parry");

        msg = HIC "\n$N" HIC "˫ȭ�ӳ���ʩһ�С�" HIG "����������"
              HIC "����ȭ�ټ��죬��λ��׼��" HIC "��Ϯ$n" HIC "��"
              "�ź��ؿڡ�" NOR;
        
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
