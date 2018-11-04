#include <ansi.h>
#include <combat.h>

#define ZHAN "��" HIW "ճ�־�" NOR "��"

inherit F_SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, damage;

        if (userp(me) && ! me->query("can_perform/taiji-quan/zhan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(ZHAN "ֻ�ܿ���ʩչ��\n");

        skill = me->query_skill("taiji-quan", 1);

        if (skill < 150)
                return notify_fail("���̫��ȭ�ȼ�����������ʩչ" ZHAN "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����������������ʩչ" ZHAN "��\n");
 
        if (me->query_skill_mapped("unarmed") != "taiji-quan")
                return notify_fail("��û�м���̫��ȭ������ʩչ" ZHAN "��\n");

        if (me->query_skill_prepared("unarmed") != "taiji-quan")
                return notify_fail("������û��׼��ʹ��̫��ȭ���޷�ʹ��" ZHAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "��������˫�ֳ�Բ�λ�������"
              "����̫��ȭ��Բת���ϡ����ֵľ��⡣ֻ\n��$N"
              HIW "�漴ƽȦ����Ȧ����Ȧ��бȦ��һ������һ"
              "����һ����̫��ԲȦ��ʱ��\n��$n" HIW "����"
              "�˷���\n" NOR;

        ap = me->query_skill("unarmed");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap * 4 / 3) > dp)
        {
                me->add("neili", -30);
                damage = ap / 4 + random(ap / 4);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 20,
                                           HIR "$n" HIR "��ʱ�㱻�׵õ���ײײ����"
                                           "�����������㲻�ȣ������оƻ��ԡ�\n"
                                           NOR);
                me->start_busy(2);
                if (ap / 2 + random(ap) > dp && ! target->is_busy())
                        target->start_busy(ap / 50 + 1);
        } else
        {
                msg += CYN "����$p" CYN "�Ŀ�����$P" CYN
                       "����ͼ������Ĳ��У�û¶�������"
                       "��\n" NOR;
                me->add("neili", -10);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

