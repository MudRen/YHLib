#include <ansi.h>
#include <combat.h>

#define QIAN "��" HIW "ǧͷ����" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        string wname;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/jiandun-zhusuo/qian"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(QIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" QIAN "��\n");

        if (me->query_skill("force") < 180)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" QIAN "��\n");

        if (me->query_skill("jiandun-zhusuo", 1) < 120)
                return notify_fail("��Ľ���������Ϊ����������ʩչ" QIAN "��\n");

        if (me->query("neili") < 400)
                return notify_fail("�����������������ʩչ" QIAN "��\n");

        if (me->query_skill_mapped("whip") != "jiandun-zhusuo")
                return notify_fail("��û�м�����������������ʩչ" QIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wname = weapon->name();

        damage = me->query_skill("jiandun-zhusuo", 1) / 4;
        damage += random(damage / 4);

        ap = me->query_skill("whip");
        dp = target->query_skill("parry");

        msg = HIW "$N" HIW "һ����ߣ����ֺ�ӣ�����" + wname +
              HIW "һ�С�ǧͷ��������׼$n" HIW "�ҵ�������\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 10,
                                           HIR "$p" HIR "������ˣ�ȴ��Ȼ��������"
                                           "$P" HIR "���е���ҪѨ����ʱ������Ѫ��\n"
                                           NOR);
        } else
        {
                msg += CYN "$p" CYN "���������Ӳ������$P"
                       CYN "��һ�޼ܿ���˿������\n" NOR;
        }

        ap = me->query_skill("whip");
        dp = target->query_skill("dodge");

        msg += "\n" HIW "ȴ��$N" HIW "�粽��ǰ������" + wname +
               HIW "����һ�䣬��ת���ʣ�����$n" HIW "��ȥ��\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 10,
                                           HIR "����$p" HIR "΢΢һ��䣬�ѱ�$P"
                                           HIR "���г��У���Ѫ�Ĵ��ɽ���\n" NOR);
        } else
        {
                msg += CYN "����$p" CYN "��æ����һ��������"
                       "��Ծ�𣬶㿪����һ�С�\n" NOR;
        }

        ap = me->query_skill("whip");
        dp = target->query_skill("force");

        msg += "\n" HIW "�������ּ�$N" HIW "������𣬵��ֽ�" + wname +
               HIW "�����趯����ճ���$n" HIW "Ȧȥ��\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 10,
                                           HIR "��ʱ������ž����һ�����죬$n" HIR
                                           "����" + wname + HIR "������գ�����"
                                           "ˤ�£���Ҳ��������\n" NOR);
        } else
        {
                msg += CYN "��$p" CYN "һ������������ʱ����"
                       "�����⣬�㽫��ʽ���������Ρ�\n" NOR;
        }
        me->start_busy(3 + random(3));
        me->add("neili", -300);
        message_combatd(msg, me, target);
        return 1;
}
