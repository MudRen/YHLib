#include <ansi.h>
#include <combat.h>

#define HAN "��" HIW "���캮��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/hanbing-zhang/han"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(HAN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("hanbing-zhang", 1) < 160)
                return notify_fail("�㺮���Ʋ�����죬����ʩչ" HAN "��\n");

        if (me->query_skill_prepared("strike") != "hanbing-zhang")
                return notify_fail("��û��׼�������ƣ�����ʩչ" HAN "��\n");

        if (me->query_skill("force") < 180)
                return notify_fail("����ڹ���Ϊ����������ʩչ" HAN "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����ڵ���������������ʩչ" HAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("strike");
        dp = target->query_skill("parry");

        msg = HIY "\n$N" HIY "��ת������������ע�����ϣ�ʩ��"
              "���С�" HIW "���캮��" HIY "����˫����Ȼ����$n" 
              HIY "���Ʒ������ޱȣ�͸���������������������"
              "ѩ����һ�㣬���˲���������\n" NOR;

        if (ap / 2 + random(ap) > dp)
        {
                damage = (int)me->query_skill("hanbing-zhang", 1);
                damage += random(damage);

                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 60,
                                           HIR "����$N" HIR "˫���������Ʒ����죬"
                                           "�������ˡ�$n" HIR "�پ��ľ���ս��"
                                           "�����м�֮����΢���ɼ�$N" HIR "����"
                                           "������$n" HIR "�ؿڣ��ٽ�$p����������"
                                           " \n" NOR);

                me->start_busy(3);
                me->add("neili", -220);
        } else
        {
                msg += CYN "$n" CYN "��$N" CYN "��������������"
                       "��ӯ���������ˣ�ֻ�÷������һ�ݣ��Ŷ�"
                       "����һ�ơ�\n" NOR;

                me->start_busy(4);
                me->add("neili", -120);
        }
        message_sort(msg, me, target);
        return 1;
}
