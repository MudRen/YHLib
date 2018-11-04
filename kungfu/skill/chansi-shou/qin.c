#include <ansi.h>
#include <combat.h>

#define QIN "��" HIW "��˿����" NOR "��"

inherit F_SSERVER;

string final(object me, object target, int damage);

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, damage;

        if (userp(me) && ! me->query("can_perform/chansi-shou/qin"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(QIN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(QIN "ֻ�ܿ���ʩչ��\n");

        skill = me->query_skill("chansi-shou", 1);

        if (skill < 120)
                return notify_fail("���˿�����ֵȼ�����������ʩչ" QIN "��\n");
 
        if (me->query_skill_mapped("hand") != "chansi-shou")
                return notify_fail("��û�м�����˿�����֣�����ʩչ" QIN "��\n");

        if (me->query_skill_prepared("hand") != "chansi-shou")
                return notify_fail("��û��׼����˿�����֣�����ʩչ" QIN "��\n");

        if (me->query("neili") < 100)
                return notify_fail("�����ڵ���������������ʩչ" QIN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "��Ȼ����$n" HIW "��ʩ����˿���ã�˫�ֺ�"
              "�ۺ�Ť����ץ��˦��ֱ��$p" HIW "����Ҫ����\n" NOR;
 
        ap = me->query_skill("hand");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -80);
                damage = 50 + ap / 6 + random(ap / 6);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 35,
                                           (: final, me, target, damage :));
                me->start_busy(2);
        } else
        {
                msg += CYN "����$n" CYN "�Ŀ�����$N"
                       CYN "����ʽ��������мܲ�⣬û¶���������\n" NOR;
                me->add("neili", -20);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

string final(object me, object target, int damage)
{
        string msg;

        msg = HIR "ȴ��$n" HIR "�����ֿ������վ��޷�"
              "����$N" HIR "�Ĺ��ƣ��������ƣ�";

        if (random(3) >= 1 && ! target->is_busy())
        {
                target->start_busy(damage / 15);
                msg += "���Է�����\n" NOR;
        } else
                msg += "��Ѫ���硣\n" NOR;

        return  msg;
}

