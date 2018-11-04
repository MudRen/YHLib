#include <ansi.h>
#include <combat.h>

#define XING "��" HIW "�����岼" NOR "��"

inherit F_SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, damage;

        if (userp(me) && ! me->query("can_perform/sixiang-zhang/xing"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(XING "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(XING "ֻ�ܿ���ʩչ��\n");

        skill = me->query_skill("sixiang-zhang", 1);

        if (skill < 60)
                return notify_fail("��������Ʒ��ȼ�����������ʩչ" XING "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����������������ʩչ" XING "��\n");
 
        if (me->query_skill_mapped("strike") != "sixiang-zhang")
                return notify_fail("��û�м��������Ʒ�������ʩչ" XING "��\n");

        if (me->query_skill_prepared("strike") != "sixiang-zhang")
                return notify_fail("������û��׼��ʹ�������Ʒ����޷�ʹ��" XING "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "һ����Х��˫�Ʒ׷ɹ������Ӱ���ص�������ʵ��"
              "�棬ȫȫ����$n" HIW "ȫ��\n" NOR;

        ap = me->query_skill("strike");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -80);
                damage = ap / 3 + random(ap / 3);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 10,
                                           HIR "$n" HIR "һʱ�޷�������������Ʒ�"
                                           "�������������У��������У��޷��԰Ρ�\n"
                                           NOR);
                me->start_busy(2);
                if (ap / 2 + random(ap) > dp && ! target->is_busy())
                        target->start_busy(ap / 60 + 1);
        } else
        {
                msg += CYN "����$p" CYN "�Ŀ�����$P" CYN
                       "���Ʒ�������Ĳ��У�û¶�������"
                       "��\n" NOR;
                me->add("neili", -50);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}
