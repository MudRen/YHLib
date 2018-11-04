// feng.c

#include <ansi.h>
#include <combat.h>

#define FENG "��" HIW "�������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;

        if (userp(me) && ! me->query("can_perform/xueshan-jian/feng"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(FENG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" FENG "��\n");

        if (me->query_skill("force") < 240)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" FENG "��\n");

        if (me->query_skill("xueshan-jian", 1) < 160)
                return notify_fail("���ѩɽ������Ϊ����������ʩչ" FENG "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����������������ʩչ" FENG "��\n");

        if (me->query_skill_mapped("sword") != "xueshan-jian")
                return notify_fail("��û�м���ѩɽ����������ʩչ" FENG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "ֻ��$N" HIW "һ����Х������" + weapon->name() +
              HIW "������ֹ���ų�����⻪��������������������ϯ��"
              "$n" HIW "��ȥ��\n" NOR;

        ap = me->query_skill("sword") + me->query_skill("force");
        dp = target->query_skill("dodge") + target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 3 + random(ap / 3);
                me->add("neili", -100);
                me->start_busy(2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 90,
                                           HIR "$n" HIR "ֻ�к���Ϯ�壬ȫ��һ���"
                                           "�����ѱ�$N" HIR "�������ˡ���ʱ����һ"
                                           "�����һ�����Ѫ��\n" NOR);
        } else
        {
                me->add("neili", -50);
                me->start_busy(3);
                msg += CYN "����$n" CYN "����" CYN "$N" CYN
                       "������������Ծ���������ڽ���������"
                       "���������Ρ�\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
