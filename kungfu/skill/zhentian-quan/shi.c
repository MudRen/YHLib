#include <ansi.h>
#include <combat.h>

#define SHI "��" HIY "ʯ���쾪" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if (userp(me) && ! me->query("can_perform/zhentian-quan/shi"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(SHI "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("zhentian-quan", 1) < 80)
                return notify_fail("�������ȭ��������죬����ʩչ" SHI "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����������������ʩչ" SHI "��\n");
 
        if (me->query_skill_mapped("cuff") != "zhentian-quan")
                return notify_fail("��û�м�������ȭ��������ʩչ" SHI "��\n");

        if (me->query_skill_prepared("cuff") != "zhentian-quan")
                return notify_fail("������û��׼��ʹ������ȭ��������ʩչ" SHI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "�����ھ�����������һȭ�ӳ�����������ʯ���쾪��"
              "Я�ź�Х֮����$n" HIY "ֱ���ȥ��\n" NOR;

        if (random(me->query_skill("cuff")) > target->query_skill("dodge") / 2)
        {
                me->start_busy(2);
                damage = me->query_skill("cuff");
                damage = damage / 2 + random(damage / 2);
                me->add("neili", -150);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 45,
                                           HIR "���$p" HIR "���ܲ�������$P" HIR
                                           "���д��˸����У�ȭ���ƾ���ʱ͸�����"
                                           "����ʱ������Ѫ������������\n" NOR);
        } else
        {
                me->start_busy(3);
                me->add("neili", -50);
                msg += CYN "����$p" CYN "ʶ����$P"
                       CYN "��һ�У�ббһԾ�ܿ���\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
