#include <ansi.h>
#include <combat.h>

#define LIAN "��" HIW "��������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int count;
        int lvl;
        int i;

        if (userp(me) && ! me->query("can_perform/lianhuan-mizongtui/lian"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((lvl = (int)me->query_skill("lianhuan-mizongtui", 1)) < 120)
                return notify_fail("������������Ȳ�����죬����ʩչ" LIAN "��\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(LIAN "ֻ�ܿ���ʩչ��\n");
                
        if (me->query("max_neili") < 1800)
                return notify_fail("�����������Ϊ�����������޷�ʹ��" LIAN "��\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻹�������ʩչ" LIAN "��\n");

        if ((int)me->query_skill("dodge") < 150)
                return notify_fail("����Ṧ��򲻹�������ʩչ" LIAN "��\n");

        if (me->query_skill_prepared("unarmed") != "lianhuan-mizongtui")
                return notify_fail("������û��׼��ʹ�����������ȣ�����ʩչ" LIAN "��\n");

        if ((int)me->query("neili", 1) < 200)
                return notify_fail("����������̫��������ʩչ" LIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "����$N" HIW "ȫ�������ת��˫�Ⱥ�ǰ���󣬽���������ȣ����ǰ㼲��$n"
              HIW "�ؿڡ�\n" NOR;

        me->add("neili", -150);

        if (random(me->query_skill("dodge") + me->query_skill("unarmed")) >
            target->query_skill("parry"))
        {
                msg += HIR "$n" HIR "��ʱ�����ۻ����ң���������"
                       "���Լ�������ֻ��ƴ���˶��ֵ���\n" NOR;
                count = lvl / 5;
                me->add_temp("apply/attack", count);
        } else
        {
                msg += HIC "����$n" HIC "��������������ֵ���˿"
                       "��������Ӱ�ĸ��ţ���\n" NOR;
                count = 0;
        }
        message_combatd(msg, me, target);

        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, 0, 0);
        }
        me->start_busy(random(5));
        me->add_temp("apply/attack", -count);
        return 1;
}
