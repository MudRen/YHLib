#include <ansi.h>
#include <combat.h>

#define JUAN "��" HIY "��������Ͼ���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if (userp(me) && ! me->query("can_perform/hua-quan/juan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(JUAN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("hua-quan", 1) < 120)
                return notify_fail("���������ȭ������죬����ʩչ" JUAN "��\n");

        if ((int)me->query_skill("force") < 180)
                return notify_fail("����ڹ���Ϊ����������ʩչ" JUAN "��\n");

        if ((int)me->query("neili") < 400)
                return notify_fail("��������������������ʩչ" JUAN "��\n");

        if (me->query_skill_mapped("cuff") != "hua-quan") 
                return notify_fail("��û�м���������ȭ������ʩչ" JUAN "��\n");

        if (me->query_skill_prepared("cuff") != "hua-quan")
                return notify_fail("������û��׼��ʹ��������ȭ������ʩչ" JUAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "ֻ��$N" HIY "���μ�ת��˫ȭ�����뷢��һʽ����������Ͼ��졹Я"
              "����������֮�ƹ���$n" HIY "��\n" NOR;

        if (random(me->query_skill("cuff")) > target->query_skill("dodge") / 2)
        {
                me->start_busy(2);
                damage = me->query_skill("cuff");
                damage = damage / 2 + random(damage);
                me->add("neili", -250);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 45,
                                           HIR "���$n" HIR "���ܲ�������$P" HIR
                                           "˫ȭ���У���Ȼһ���Һ���������Ѫ����"
                                           "�����ɳ�����\n" NOR);
        } else
        {
                me->start_busy(3);
                me->add("neili", -80);
                msg += CYN "$p" CYN "��$P" CYN "ȭ����ӿ������Ӳ"
                       "���ֵ�������ббһԾ�ܿ���\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
