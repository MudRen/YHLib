#include <ansi.h>
#include <combat.h>

#define JIANG "��" HIR "���޽���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int angry;
        string msg;
        int skill, ap, dp, damage;

        if (userp(me) && ! me->query("can_perform/yujiamu-quan/jiang"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(JIANG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(JIANG "ֻ�ܿ���ʩչ��\n");

        skill = me->query_skill("yujiamu-quan", 1);

        if (skill < 100)
                return notify_fail("�������ĸȭ��Ϊ����������ʩչ" JIANG "��\n");

        if (me->query_skill_mapped("cuff") != "yujiamu-quan")
                return notify_fail("��û�м���������ĸȭ������ʩչ" JIANG "��\n");

        if (me->query_skill_prepared("cuff") != "yujiamu-quan")
                return notify_fail("��û��׼��������ĸȭ������ʩչ" JIANG "��\n");

        if (me->query("neili") < 180)
                return notify_fail("��Ŀǰ���������㣬����ʩչ" JIANG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        if (angry = me->query("qi") < me->query("max_qi") / 2)
                msg = HIR "$N" HIR "Ŀ�����ѣ�һ�����ȣ�ȫ�������ž���죬ȭ"
                      "ͷ����������$n" HIR "��Ҫ����\n" NOR;
        else
                msg = HIR "$N" HIR "���һ������ɫ��죬ȫ�������ž���죬ȭ"
                      "ͷ����������$n" HIR "��Ҫ����\n" NOR;

        ap = me->query_skill("cuff", 1) / 2 + skill;
        dp = target->query_skill("dodge");
        if (dp < 1) dp = 1;
        if (ap / 2 + random(ap * 4 / 5) > dp)
        {
                me->add("neili", -100);
                me->start_busy(1);
                damage = 10 + skill / 3 + random(skill / 2);
                if (angry) damage += random(damage / 2);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 35,
                                           HIR "���$p" HIR "�޷��ֵ�$P" HIR "����"
                                           "��һ������ʱ������������ҡ�β�����\n" NOR);
        } else
        {
                me->add("neili",-40);
                msg += CYN "����$p" CYN "��δ�����������壬����"
                       "�Ų����㿪��$P" CYN "�Ĺ�����\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}
