#include <ansi.h>
#include <combat.h>

#define KONG "��" HIR "�����ɽ" NOR "��"

inherit F_SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, damage;

        if (userp(me) && ! me->query("can_perform/kunlun-zhang/kong"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(KONG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(KONG "ֻ�ܿ���ʩչ��\n");

        skill = me->query_skill("kunlun-zhang", 1);

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if (skill < 120)
                return notify_fail("�������Ʒ��ȼ�����������ʩչ" KONG "��\n");
 
        if (me->query_skill_mapped("strike") != "kunlun-zhang")
                return notify_fail("��û�м��������Ʒ�������ʩչ" KONG "��\n");

        if (me->query_skill_prepared("strike") != "kunlun-zhang")
                return notify_fail("��û��׼�������Ʒ�������ʩչ" KONG "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" KONG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "��Ȼʩ�������Ʒ�������" NOR + HIR "�����ɽ"
              NOR + HIW "����һ����Ȼ�ĳ�����Ӱ���ص���������$n" HIW "��"
              "��˷���\n" NOR;

        ap = me->query_skill("strike");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -150);
                damage = ap / 3 + random(ap / 3);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 20,
                                           HIR "$n" HIR "ֻ��$P" HIR "��������Ӱ"
                                           "���Լ�ѹ����һʱ��֪����εֵ�����ʱ"
                                           "�������У���Ͼ������\n" NOR);
                me->start_busy(1);
                target->start_busy(ap / 30 + 2);
        } else
        {
                msg += CYN "����$p" CYN "�Ŀ�����$P" CYN
                       "����ͼ������Ĳ��У�û¶�������"
                       "��\n" NOR;
                me->add("neili", -80);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

