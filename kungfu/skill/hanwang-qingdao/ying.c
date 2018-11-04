#include <ansi.h>
#include <combat.h>

#define YING "��" HIC "��Ӱ����" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
 
        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/hanwang-qingdao/ying"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(YING "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" YING "��\n");

        if (me->query_skill("force") < 120)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" YING "��\n");

        if (me->query_skill("hanwang-qingdao", 1) < 80)
                return notify_fail("��ĺ����൶��Ϊ����������ʩչ" YING "��\n");

        if (me->query("neili") < 100)
                return notify_fail("��Ŀǰ���������㣬����ʩչ" YING "��\n");

        if (me->query_skill_mapped("blade") != "hanwang-qingdao")
                return notify_fail("��û�м��������൶������ʩչ" YING "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "��ʱֻ��$N" HIC "����" + weapon->name() +
              HIC "һ�񣬶�ʱ�ó����ص�Ӱ����$n" HIC "���Ź�ס��\n" NOR;

        ap = me->query_skill("blade");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 3 + random(ap / 3);
                me->start_busy(1);
                me->add("neili", -80);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 20,
                                           HIR "ֻ��$p" HIR "һ���Һ���һ��Ѫ����" HIR
                                           "Ѫɫ��Ӱ�м��������\n" NOR);
        } else
        {
                me->add("neili", -40);
                me->start_busy(3);
                msg += CYN "����$n" CYN "����һЦ����Ȼ����$N"
                       CYN "���ص�Ӱ�������У����⽫֮�ܿ���\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}