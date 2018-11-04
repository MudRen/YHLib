#include <ansi.h>
#include <combat.h>

#define TAI "��" HIW "̩ɽѹ��" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp, damage;
 
        if (userp(me) && ! me->query("can_perform/poshui-zhang/tai"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(TAI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "staff")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" TAI "��\n");

        if ((int)me->query_skill("force") < 180)
                return notify_fail("����ڹ���򲻹�������ʩչ" TAI "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�����ڵ���������������ʩչ" TAI "��\n");

        if ((int)me->query_skill("poshui-zhang", 1) < 120)
                return notify_fail("���ʮһ·��ˮ�Ȼ�򲻹�������ʩչ" TAI "��\n");

        if (me->query_skill_mapped("staff") != "poshui-zhang") 
                return notify_fail("��û�м�����ʮһ·��ˮ�ȣ�����ʩչ" TAI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "\n$N" HIW "һ�����ȣ���Ȼ���ڿն�������" 
              + weapon->name() + HIW "������������ƾ��ˣ�"
              "����̩ɽѹ�����Ϯ��$n" HIW "��\n" NOR;
        message_sort(msg, me, target);

        ap = me->query_skill("staff");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap / 2);

                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 45,
                                           HIR "$n" HIR "��ȫ�޷�����������ʵ��ֻ"
                                           "���������项�������ѱ�$N" HIR "������"
                                           "�ȡ�\n" NOR);
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
