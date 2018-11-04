#include <ansi.h>
#include <combat.h>

#define DIAN "��" HIR "���ǵ�Ԫ" NOR "��"

inherit F_SSERVER;

string final(object me, object target, int damage);

int perform(object me, object target)
{
        object weapon;
        int ap, dp, damage;
        string wn, msg;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/baxian-jian/dian"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(DIAN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" DIAN "��\n");

        if (me->query_skill("force") < 150)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" DIAN "��\n");

        if (me->query_skill("baxian-jian", 1) < 100)
                return notify_fail("��İ��ɽ�����Ϊ����������ʩչ" DIAN "��\n");

        if (me->query_skill_mapped("sword") != "baxian-jian")
                return notify_fail("��û�м������ɽ���������ʩչ" DIAN "��\n");

        if (me->query("neili") < 250)
                return notify_fail("��������������������ʩչ" DIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();

        msg = HIC "$N" HIC "ʩ����" HIR "���ǵ�Ԫ" HIC "������������" + wn +
              HIC "΢������������ų�һ����������$n" HIC "��\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap * 2 / 3);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 30,
                                           (: final, me, target, damage :));
                me->start_busy(2);
                me->add("neili", -150);
        } else
        {
                msg += CYN "����$p" CYN "�������ң�������������񵲿���$P"
                       CYN "�Ľ��С�\n"NOR;
                me->start_busy(3);
                me->add("neili", -60);
        }
        message_combatd(msg, me, target);

        return 1;
}

string final(object me, object target, int damage)
{
        target->add("neili", -damage);

        if (target->query("neili") < 0)
                target->set("neili", 0);

        return  HIR "���$n" HIR "������$N" HIR "���⵴����"
                "���������͹�Ѩ��ȫ������������й������\n" NOR;
}
