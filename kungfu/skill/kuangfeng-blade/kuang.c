// kuang.c -������ʮһʽ��

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á�����ʮһʽ����\n");

        if ((int)me->query_skill("kuangfeng-blade", 1) < 70)
                return notify_fail("��Ŀǰ������ʹ����������ʮһʽ����\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�������������\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        me->add("neili", -60);
        msg = HIC "$N" HIC "��ȻһЦ�����Ϳ�ݾ��׵ĵ�����Ȼ��"
              "�ø���������������һ˲֮�䣬$N" HIC "��������ʮ"
              "һ����\n�������ŷ磬���ﺬ�ŵ�Ӱ��$n"
              HIC "ֻ����������ֹͣ�ˣ�\n" NOR;
        me->start_busy(2);

        if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2)
        {
                target->start_busy(3);
                damage = (int)me->query_skill("blade");
                damage = damage / 2 + random(damage / 2);

                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40, 
                                           HIR "ֻ��$n" HIR "�ѱ�$N" HIR
                                           "�е����������Ѫ�������ȫ�����������\n" NOR);
        } else
        {
                msg += HIC "����$p" HIC "��æ����㿪��ʹ$P"
                       HIC "����û�еóѡ�\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

