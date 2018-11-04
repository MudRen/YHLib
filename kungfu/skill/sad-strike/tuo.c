// tuo.c
// �����ս���ַ���ʱ��ʩչ�ľ���ʤ��
// ��һ�С�

#include <ansi.h>
#include <combat.h>

#define TUO "��" HIM "�����ˮ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;
        int effqi, maxqi;
        string couple;

        if (userp(me) && ! me->query("can_perform/sad-strike/tuo"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(TUO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query("static/marry") > 1)
                return notify_fail("��������Ѳ��������ﻹ�����Ե�������Ȼ����ĸо���\n");

        if ((int)me->query_skill("force") < 360)
                return notify_fail("����ڹ���򲻹���ʹ����" TUO "��\n");

        if ((int)me->query_skill("sad-strike", 1) < 180)
                return notify_fail("�����Ȼ�����Ʋ�������������ʹ��" TUO "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("��������������޷�ʹ��" TUO "��\n");

        if (me->query_skill_prepared("unarmed") != "sad-strike")
                return notify_fail("��û��׼����Ȼ�����ƣ��޷�ʹ��" TUO "��\n");

        if (! stringp(couple = me->query("couple/id")))
                return notify_fail("��û�����ӣ���᲻�����������ҵĸо���\n");

        if (time() - me->query_temp("last_perform/sad-strike/tuo") < 60)
                return notify_fail("��ո�ʩչ��" TUO "����������û����ô�����ˡ�\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        effqi = me->query("eff_qi");
        maxqi = me->query("max_qi");

        ap = me->query_skill("unarmed") + me->query("force");
        dp = target->query_skill("parry") + target->query("force");
        me->start_busy(2 + random(5));

        if (random(5) == 1 && me->query("max_neili") > 5000)
        {
                msg = HIR "\n$N" HIR "���������ң���Ȼ����뵽�Լ�������" HIW
                      + me->query("couple/name") + HIR "��" HIR "���а����������ˣ�"
                      "���Լ����ء�������ʧ�����ǣ�����һ�У�ǡ��ʹ������"
                      "Ȼ�������еġ������ˮ����\n" NOR;
                ap += ap * 10 / 100;
        } else
        {
                msg = HIM "\nֻ��$N" HIM "û����ɵĻ����������ޱ��飬�����ĳ�һ�ƣ�����"
                      "��Ȼ�������еġ������ˮ����\n"NOR;
        }
        if (ap * 3 / 5 + random(ap) > dp)
        { 
                damage = ap + random(ap / 2);
                me->add("neili", -400);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 120,
                                           HIR "ֻ��$n" HIR "һ���ƺߣ����ۡ���һ"
                                           "������һ�����û���$p" HIR "��ͷ�� "
                                           NOR);
                me->set_temp("last_perform/sad-strike/tuo", time() - 60);
        } else
        {
                me->add("neili", -200);
                msg += HIC "����$p" HIC "С��Ӧ���������мܣ���������һ�С�\n"
                       NOR;
        }
        message_sort(msg, me, target);
        return 1;
}

