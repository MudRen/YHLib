#include <ansi.h>
#include <combat.h>

#define  ZHU "��" HIW "����ɲ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon, weapon2;
        int damage;
        string  msg;
        string  pmsg;
        string *limbs;
        string  limb;
        int ap, dp;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/zhuihun-jian/zhu"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" ZHU "��\n");

        if (me->query_skill_mapped("sword") != "zhuihun-jian") 
                return notify_fail("��û�м���׷�������������ʩչ" ZHU "��\n");

        if ((int)me->query_skill("zhuihun-jian", 1) < 160)
                return notify_fail("���׷���������������죬����ʩչ" ZHU "��\n");

        if ((int)me->query("neili", 1) < 300)
                return notify_fail("����������̫��������ʩչ" ZHU "��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "ͻȻ$N" HIW "һ����ߣ�һ���粽������" + weapon->name() +
              NOR + HIW "�й�ֱ����������һ�����$n" HIW "��\n" NOR;
        me->add("neili", -50);

        ap = me->query_skill("zhuihun-jian", 1) +
             me->query_skill("sword", 1);
        dp = target->query_skill("parry");

        me->want_kill(target);
        if (ap / 3 + random(ap) > dp)
        {
                me->start_busy(2);
                me->add("neili", -200);
                damage = 0;

                if (me->query("max_neili") > target->query("max_neili") * 2)
                {
                        msg += HIR "ֻ��$N" HIR "��һ�����ƺÿ죬��������"
                               "����һ����������û��$n" HIR "�ʺ��ߣ�$n"
                               HIR "���������������������̱����ȥ��\n" NOR
                               "( $n" RED "���˹��أ��Ѿ�������в�����"
                               "ʱ�����ܶ�����" NOR ")\n";
                        damage = -1;
                } else

                if (objectp(weapon2 = target->query_temp("weapon")) &&
                   me->query_skill("force") > target->query_skill("parry"))
                {
                        msg += HIR "ֻ����������һ����$n" HIR "���ѱ�$N"
                               HIR + weapon->name() + NOR + HIR "�Դ�����"
                               "������" + weapon2->name() + NOR + HIR
                               "��Ҳ׽�ò�ס�����ֶ��ɣ�\n" NOR;
                        me->start_busy(random(2));
                        target->start_busy(4);
                        weapon2->move(environment(target));
                } else
                {
                        target->start_busy(1 + random(3));
        
                        damage = ap + (int)me->query_skill("force");
                        damage = damage / 2 + random(damage / 2);
                        
                        if (arrayp(limbs = target->query("limbs")))
                                limb = limbs[random(sizeof(limbs))];
                        else
                                limb = "Ҫ��";
                        pmsg = HIR "$n" HIR "���������Ȼ��ֻ����������"
                               "һ����$N" HIR + weapon->name() + NOR +
                               HIR "��û��$n" HIR + limb + "��磬��Ѫ"
                               "�񽦶�����\n" NOR;
                        msg += COMBAT_D->do_damage(me, target,
                               WEAPON_ATTACK, damage, 70, pmsg);
                }
        } else 
        {
                me->start_busy(3);
                msg += CYN "����$p" CYN "������$P"
                       CYN "����ͼ���ܿ�����һ�С�\n"NOR;
        }

        message_combatd(msg, me, target);
        if (damage < 0) target->die(me);

        return 1;
}

