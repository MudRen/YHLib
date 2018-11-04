#include <ansi.h>
#include <combat.h>

#define FEI "��" HIY "������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int ap, dp, wn;

        if (userp(me) && ! me->query("can_perform/feilong-zhang/fei"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(FEI "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "staff")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" FEI "��\n");

        if ((int)me->query_skill("feilong-zhang", 1) < 160)
                return notify_fail("������ȷ�������죬����ʩչ" FEI "��\n");

        if (me->query_skill_mapped("staff") != "feilong-zhang")
                return notify_fail("��û�м��������ȷ�������ʩչ" FEI "��\n");

        if ((int)me->query_skill("force") < 240)
                return notify_fail("����ڹ���򲻹�������ʩչ" FEI "��\n");

        if ((int)me->query("max_neili") < 2500)
                return notify_fail("���������Ϊ����������ʩչ" FEI "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����ڵ��������㣬����ʩչ" FEI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();

        msg = HIW "$N" HIW "��Ŀ��ȣ���ȫ���������ұۣ�����" + wn +
              HIW "��ʱ�����������$n" HIW "��ȥ��\n" NOR;

        ap = me->query_skill("staff");
        dp = target->query_skill("dodge");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap / 2);
                damage += random(damage);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 55,
                                           HIR "$n" HIR "ֻ��һ�ɾ���Ϯ��������"
                                           "�������Ǹ�" + wn + HIR "���û����ؿ�"
                                           "��ײ�������߹ǡ�\n" NOR);
                me->start_busy(3);
                me->add("neili", -300);
        } else
        {
                msg += CYN "$n" CYN "��$N" CYN "������磬����Ӳ"
                       "�ӣ��������������ߣ�����������\n" NOR;
                me->start_busy(4);
                me->add("neili", -200);
        }

        msg += HIY "ֻ���Ǹ�" + wn + HIY "���Ʋ���������ǰ�ɳ���"
               "�ɣ�����û�����С�\n" NOR;
        weapon->move(environment(me));

        message_combatd(msg, me, target);
        return 1;
}
