#include <ansi.h>
#include <combat.h>

#define SHA "��" HIR "�޺�ɱ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
 
        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/shiying-lianhuan/sha"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHA "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" SHA "��\n");

        if (me->query_skill("force") < 200)
                return notify_fail("����ڹ���Ϊ����������ʩչ" SHA "��\n");

        if (me->query_skill("shiying-lianhuan", 1) < 150)
                return notify_fail("��߱ӥ��������Ϊ����������ʩչ" SHA "��\n");

        if (me->query_skill_mapped("blade") != "shiying-lianhuan")
                return notify_fail("��û�м���߱ӥ������������ʩչ" SHA "��\n");

        if (me->query("neili") < 300)
                return notify_fail("�����ڵ��������㣬����ʩչ" SHA "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "��ת����" + weapon->name() + HIR "ʩ����" NOR +
              RED "�޺�ɱ" HIR "�������������ʱ����һ��Ѫɫ��â��ֱն$n"
              HIR "��ȥ��\n" NOR;

        ap = me->query_skill("blade");
        dp = target->query_skill("dodge");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap);
                me->add("neili", -250);
                me->start_busy(2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 70,
                                           HIR "ֻ����������һ����$n" HIR "��$N"
                                           HIR "�ĵ�â�������ţ���ʱʹ����������"
                                           "���ε���\n" NOR);
        } else
        {
                me->add("neili", -100);
                me->start_busy(4);
                msg += CYN "$n" CYN "��$P" CYN "������ӿ����æ��"
                       "�����Ų�����ߣ�����������\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
