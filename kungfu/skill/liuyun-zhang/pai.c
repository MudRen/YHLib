#include <ansi.h>
#include <combat.h>

#define PAI "��" HIM "��ɽ����" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/liuyun-zhang/pai"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(PAI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(PAI "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("liuyun-zhang", 1) < 140)
                return notify_fail("�������Ʋ�����죬����ʩչ" PAI "��\n");

        if (me->query_skill_mapped("strike") != "liuyun-zhang")
                return notify_fail("��û�м��������ƣ�����ʩչ" PAI "��\n");

        if (me->query_skill_prepared("strike") != "liuyun-zhang")
                return notify_fail("��û��׼�������ƣ�����ʩչ" PAI "��\n");

        if (me->query_skill("force") < 180)
                return notify_fail("����ڹ���Ϊ����������ʩչ" PAI "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�����ڵ���������������ʩչ" PAI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("strike");
        dp = target->query_skill("parry");

        msg = HIC "\n$N" HIC "��ת������������ע���Ʒ�֮�У�˫����"
              "Ȼ����$n" HIC "���ۻ����������ư��磬�����ʹ�������"
              "��ɽ�ɾ�ѧ��" HIM "��ɽ����" HIC "����" NOR;

        message_sort(msg, me, target); 

        if (ap / 2 + random(ap) > dp)
        {
                damage = (int)me->query_skill("liuyun-zhang", 1);
                damage += random(damage);

                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 60,
                                           HIR "����$N" HIR "˫���������Ʒ����죬"
                                           "����Ѹ���ޱȡ�$n" HIR "�پ��ľ���ս��"
                                           "�����м�֮����΢�����ɼ�$N" HIR "����"
                                           "������$n" HIR "�ؿڣ��ٽ�$p����������"
                                           " \n" NOR);

                me->start_busy(3);
                me->add("neili", -200);
        } else
        {
                msg = CYN "$n" CYN "��$N" CYN "��������������"
                      "��ӯ��ֻ�����һ�ݣ��Ŷ����һ�ơ�\n" NOR;

                me->start_busy(4);
                me->add("neili", -100);
        }
        message_combatd(msg, me, target);
        return 1;
}
