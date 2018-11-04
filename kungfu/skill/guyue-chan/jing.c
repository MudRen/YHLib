#include <ansi.h>
#include <combat.h>

#define JING "��" HIY "��¾��� " NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int ap, dp, wn;

        if (userp(me) && ! me->query("can_perform/guyue-chan/jing"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JING "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "staff")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" JING "��\n");

        if ((int)me->query_skill("guyue-chan", 1) < 80)
                return notify_fail("����²���������죬����ʩչ" JING "��\n");

        if (me->query_skill_mapped("staff") != "guyue-chan")
                return notify_fail("��û�м������²���������ʩչ" JING "��\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���򲻹�������ʩչ" JING "��\n");

        if ((int)me->query("max_neili") < 600)
                return notify_fail("���������Ϊ����������ʩչ" JING "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ��������㣬����ʩչ" JING "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();

        msg = HIW "$N" HIW "ŭ��һ���������е�" + wn + HIW "����ú������죬"
              "��Ȼ����$n" HIW "��ȥ��\n" NOR;

        ap = me->query_skill("staff");
        dp = target->query_skill("dodge");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap / 2);
                damage += random(damage / 3);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 30,
                                           HIR "$n" HIR "ֻ���ۻ����ң��������Ѳ�����"
                                           "��" + wn + HIR "�����ؿڣ���ʱ���һ����"
                                           "Ѫ��\n" NOR);
                me->start_busy(3);
                me->add("neili", -80);
        } else
        {
                msg += CYN "$n" CYN "��$N" CYN "���и����ޱȣ�����Ӳ�ӣ�ֻ��\n" 
                       "����һ���Ŷ�����С�\n"NOR;
                me->start_busy(4);
                me->add("neili", -200);
        }

        message_combatd(msg, me, target);
        return 1;
}
