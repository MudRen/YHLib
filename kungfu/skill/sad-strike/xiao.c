// xiao.c ��Ȼ����

#include <ansi.h>

inherit F_SSERVER;

#define XIAO "��" HIW "��Ȼ����" NOR "��"

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int count;
        int i;
 
        if (userp(me) && ! me->query("can_perform/sad-strike/xiao"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(XIAO "ֻ����ս���жԶ���ʹ�á�\n");
 
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(XIAO "ֻ�ܿ���ʹ�á�\n");
                
        if ((int)me->query("neili") < 500)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("sad-strike", 1) < 150)
                return notify_fail("�����Ȼ�����ƻ�򲻹����޷�ʩչ" XIAO "��\n");

        if ((int)me->query_skill("force") < 320)
                return notify_fail("����ڹ���Ϊ�������޷�ʩչ" XIAO "��\n");

        if (me->query_skill_prepared("unarmed") != "sad-strike")
                return notify_fail("������û��׼��ʹ����Ȼ�����ƣ��޷�ʩչ" XIAO "��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIM "\n$N" HIM "һ������������Ȼ�����ߣ�Ψ������ӣ�������ʱ����"
              "ֹˮ����Ȼ���ˣ��ڲ�����������ʹ����" HIR "����Ȼ���꡻" HIM "��\n" NOR;

        ap = me->query_skill("unarmed") + me->query("force");
        dp = target->query_skill("parry") + target->queru_skill("force");

        if (ap / 2 + random(ap) > dp)
        {
                count = ap / 10;
                msg += HIY "$n" HIY "��$P" HIY "��һ�б仯Ī�⣬�����"
                       "�������ɴ��һ��������������������\n" NOR;
        } else
        {
                msg += HIC "$n" HIC "����С��$P" HIC
                       "�����У���Ų������С���мܡ�\n" NOR;
                count = 0;
        }

        message_sort(msg, me, target);
        me->add_temp("apply/attack", count);

        me->add("neili", -400);
        for (i = 0; i < 8; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(2) && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->start_busy(2 + random(5));
        me->add_temp("apply/attack", -count);

        return 1;
}

