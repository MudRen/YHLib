#include <ansi.h>
#include <combat.h>

#define JU "��" HIM "������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/dulong-shenzhua/ju"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(JU "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("dulong-shenzhua", 1) < 130)
                return notify_fail("�㶾����צ��������죬����ʩչ" JU "��\n");

        if (me->query_skill_mapped("claw") != "dulong-shenzhua")
                return notify_fail("��û�м���������צ��������ʩչ" JU "��\n");

        if (me->query_skill_prepared("claw") != "dulong-shenzhua")
                return notify_fail("��û��׼��������צ��������ʩչ" JU "��\n");

        if (me->query_skill("force") < 180)
                return notify_fail("����ڹ���Ϊ����������ʩչ" JU "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�����ڵ���������������ʩչ" JU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("claw") + me->query("force");
        dp = target->query_skill("parry") + target->query("force");

        msg = HIC "\n$N" HIC "��ת����������������������˫צ�䣬��Ȼ��˫צ��"
              "�ն��£����������㻮��$n" HIC "������������ڤ�Ⱦ�ѧ��" HIM "��"
              "����" HIC "����\n" NOR;

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap / 2);
                
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 65,
                                           HIR "����$N" HIR "˫צ������$n" HIR "�����ܲ������ؿڱ�$N" HIR
                                           "ץ��ʮ��Ѫ�ۡ�\n" NOR);

                me->start_busy(3);
                me->add("neili", -220);
        } else
        {
                msg += CYN "$n" CYN "�����мܣ�����$N" CYN "���л��⡣\n" NOR;

                me->start_busy(4);
                me->add("neili", -100);
        }
        message_sort(msg, me, target);
        return 1;
}
