#include <ansi.h>
#include <combat.h>

#define YIN "��" HIY "���ӡ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int skill, ap, dp, damage;

        if (userp(me) && ! me->query("can_perform/dashou-yin/yin"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(YIN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(YIN "ֻ�ܿ���ʩչ��\n");

        skill = me->query_skill("dashou-yin", 1);

        if (skill < 100)
                return notify_fail("��Ĵ���ӡ��Ϊ����������ʩչ" YIN "��\n");

        if (me->query("neili") < 150)
                return notify_fail("�����������������ʩչ" YIN "��\n");

        if (me->query_skill_mapped("hand") != "dashou-yin")
                return notify_fail("��û�м�������ӡ������ʩչ" YIN "��\n");

        if (me->query_skill_prepared("hand") != "dashou-yin")
                return notify_fail("��û��׼������ӡ������ʩչ" YIN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "����ׯ�أ�����Я�ž��糯$n" HIY "��Ȼ�ĳ�����"
              "�����ھ�ѧ�����ӡ����\n" NOR;

        ap = me->query_skill("hand", 1) / 2 + skill;
        dp = target->query_skill("parry");
        if (dp < 1) dp = 1;
        if (ap / 2 + random(ap * 4 / 5) > dp)
        {
                me->add("neili", -100);
                me->start_busy(2);
                damage = 10 + skill / 3 + random(skill / 2);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30,
                                           HIR "���$p" HIR "�мܲ�������$P" HIR
                                           "��һ�´���������̣���Ѫ������\n" NOR);
        } else
        {
                me->add("neili",-40);
                msg += CYN "����$p" CYN "���Ų�æ������ļܿ���$P"
                       CYN "�Ľ��ӡ��\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

