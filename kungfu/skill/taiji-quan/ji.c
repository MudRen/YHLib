#include <ansi.h>
#include <combat.h>

#define JI "��" HIW "���־�" NOR "��"

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object target;
        int skill, ap, dp, damage;

        if (userp(me) && ! me->query("can_perform/taiji-quan/ji"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(JI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(JI "ֻ�ܿ���ʩչ��\n");

        skill = me->query_skill("taiji-quan", 1);

        if (skill < 150)
                return notify_fail("���̫��ȭ�ȼ�����������ʩչ" JI "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����������������ʩչ" JI "��\n");
 
        if (me->query_skill_mapped("unarmed") != "taiji-quan")
                return notify_fail("��û�м���̫��ȭ������ʩչ" JI "��\n");

        if (me->query_skill_prepared("unarmed") != "taiji-quan")
                return notify_fail("������û��׼��ʹ��̫��ȭ���޷�ʹ��" JI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "ʹ��̫��ȭ�������־����ҽ�ʵ������飬ճ��ճ"
              "�棬�����Ѵ�ס$n" HIW "���󣬺ᾢ������\n" NOR;

        damage = skill / 2 + random(skill / 2);

        ap = me->query_skill("unarmed");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -30);
                me->start_busy(2);
                target->receive_damage("jing", damage);
                target->receive_wound("jing", damage);
                msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK,
                       damage, 0, HIR "$n" HIR "�Բ�������$N" HIR
                       "��ôһ����ֻ��ȫ������������������󺣣���Ӱ"
                       "���١�\n" NOR);
        }
        else
        {
                me->add("neili", -10);
                msg += CYN "$n" CYN "��״���һ������æ�������������"
                       "���ڱܿ���$N" CYN "��һ����\n" NOR;
                me->start_busy(4);
        }
        message_combatd(msg, me, target);
        return 1;
}
