#include <ansi.h>
#include <combat.h>

#define GUA "��" HIM "���԰���ȭ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/bagua-quan/gua"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(GUA "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(GUA "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("bagua-quan", 1) < 70)
                return notify_fail("��İ���ȭ��������죬����ʩչ" GUA "��\n");

        if (me->query_skill_mapped("cuff") != "bagua-quan") 
                return notify_fail("��û�м�������ȭ��������ʩչ" GUA "��\n");

        if (me->query_skill_prepared("cuff") != "bagua-quan") 
                return notify_fail("��û��׼������ȭ��������ʩչ" GUA "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("��������������������ʩչ" GUA "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIM "$N" HIM "ͻȻ����һ�࣬˫������һ������������һ��������$n"
              HIM "��˫��бб����ȥ��\n" NOR;

        ap = me->query_skill("cuff");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                damage = 50 + ap / 2 + random(ap / 2);
                me->add("neili", -100);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 20,
                                           HIR "ֻ������ʵ��̫�����$p" HIR "��"
                                           "$P" HIR "���˸����ֲ��������һ������"
                                           "��һ����Ѫ��\n" NOR);
                me->start_busy(2);
        } else 
        {
                msg += CYN "����$p" CYN "������$P" CYN
                       "����һ�У��򶨽��У�һ˿���ҡ�"
                       "\n" NOR;
                me->add("neili", -50);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}
