// six.c ��������

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        mapping prepare;
        string msg;
        int skill;
        int delta;
        int i;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_skill_mapped("finger") != "six-finger")
                return notify_fail("��û�м��������񽣣��޷�ʩչ��������������\n");

        if (me->query_skill_prepared("finger") != "six-finger")
                return notify_fail("��û��׼��ʹ�������񽣣��޷�ʩչ��������������\n");

        skill = me->query_skill("six-finger", 1);

        if (skill < 200)
                return notify_fail("�����������Ϊ���ޣ��޷�ʹ�á�������������\n");

        if (me->query_skill("force") < 360)
                return notify_fail("����ڹ���򲻹�������ʩչ��������������\n");

        if (me->query("max_neili") < 7500)
                return notify_fail("���������Ϊû�дﵽ�Ǹ����磬�޷���ת�����γɡ�������������\n");

        if (me->query("neili") < 500)
                return notify_fail("������������������޷�ʩչ��������������\n");

        if (me->query_temp("weapon"))
                return notify_fail("������ǿ��ֲ���ʩչ��������������\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "̯��˫�֣���ָ��������ʱ��������ȣ���"
              "�����ڣ���������������Ѩ��һ��ɱ��$n" HIY "��\n" NOR;

        if (random(me->query("combat_exp")) > target->query("combat_exp") / 3 * 2)
        {
                msg += HIR "$n" HIR "���˽����ݺᣬ΢һ��񣬲����������⡣\n" NOR;
                delta = -skill / 6;
        } else
                delta = 0;

        message_combatd(msg, me, target);

        me->add("neili", -300);
        target->add_temp("apply/parry", delta);
        target->add_temp("apply/dodge", delta);
        for (i = 0; i < 6; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(1);
                me->set_temp("six-action", i);
                COMBAT_D->do_attack(me, target, 0, 0);
        }
        target->add_temp("apply/parry", -delta);
        target->add_temp("apply/dodge", -delta);
        me->delete_temp("six-action");
        me->start_busy(1 + random(5));

        return 1;
}

