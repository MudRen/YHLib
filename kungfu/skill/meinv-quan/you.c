#include <ansi.h>
#include <combat.h>

#define YOU "��" HIG "��Ĺ�ľ�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        string pmsg;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/meinv-quan/you"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(YOU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (me->query_temp("weapon"))
		return notify_fail("�������ֲ���ʩչ" YOU "��\n");

        if ((int)me->query_skill("meinv-quan", 1) < 80)
                return notify_fail("�����Ůȭ���𲻹�������ʹ��" YOU "��\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ���δ��죬����ʹ��" YOU "��\n");

        if ((int)me->query("neili") < 180)
                return notify_fail("��������������������ʹ��" YOU "��\n");

        if (me->query_skill_mapped("unarmed") != "meinv-quan")
                return notify_fail("��û�м�����Ůȭ��������ʩչ" YOU "��\n");

        if (me->query_skill_prepared("unarmed") != "meinv-quan")
                return notify_fail("��û��׼����Ůȭ��������ʩչ" YOU "��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "\n$N" HIW "����֧�ã���������ӳ�����̾һ����ʹ"
              "����Ĺ�ɾ�ѧ����Ĺ�ľӡ���һ�����ּ���֮�⡣\n" NOR;

        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {
                me->start_busy(2 + random(2));

                damage = (int)me->query_skill("unarmed");
                damage = damage / 2 + random(damage / 2);

                me->add("neili", -100);

                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 45, 
                                           HIR "����$N" HIR "˫ȭϮ�������д��գ�Ѹ"
                                           "���ޱȣ����·��̲��������������$n" HIR
                                           "�����ɼ䣬 $N" HIR "ȴ����ȭ���ƺ�һ������"
                                           "�˼�����һ����Ѫ�����\n" NOR);
        } else
        {
                me->start_busy(3);
                msg += CYN "����$p" CYN "������$P" CYN
                       "����ͼ������̩ɽ��̧��һ�ܸ���$P"
                       CYN "��һȭ��\n"NOR;
        }
        message_sort(msg, me, target);

        return 1;
}
