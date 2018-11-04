#include <ansi.h>
#include <combat.h>

#define JIE "��" HIR "�ؽ����" NOR "��"

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object target;
        int skill, ap, dp, damage;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (userp(me) && ! me->query("can_perform/jieshou-jiushi/jie"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        skill = me->query_skill("jieshou-jiushi", 1);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JIE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(JIE "ֻ�ܿ���ʩչ��\n");

        if (skill < 100)
                return notify_fail("��Ľ��־�ʽ�ȼ�����������ʩչ" JIE "��\n");

        if (me->query("max_neili") < 800 )
                return notify_fail("���������Ϊ���㣬����ʩչ" JIE "��\n");

        if (me->query("neili") < 200 )
                return notify_fail("�����������������ʩչ" JIE "��\n");

        if (me->query_skill_mapped("hand") != "jieshou-jiushi")
                return notify_fail("��û�м������־�ʽ������ʩչ" JIE "��\n");

        if (me->query_skill_prepared("hand") != "jieshou-jiushi")
                return notify_fail("������û��׼��ʹ�ý��־�ʽ������ʩչ" JIE "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "����һչ����ȻԾ��$n" HIR "��ǰ��ʮָ���ţ�ֱ��$n"
              HIR "ҪѨ�����ǽ��־�ʽ�������ؽ��������\n" NOR;

        damage = skill / 2 + random(skill / 3);

        ap = me->query_skill("hand");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -200);
                me->start_busy(3);

                target->receive_damage("jing", damage);
                target->receive_wound("jing", damage);
                target->receive_damage("qi", damage * 3 / 2);
                target->receive_wound("qi", damage * 3 / 2);
                target->start_busy(1);

                msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK,
                       damage, 10, HIR "$n" HIR "�����񵲣��ɻ��Ǳ�$N"
                                   HIR "��ס��ҪѨ��ֻ����ǰһ�ڣ�"
                                   "�����ε���\n" NOR);
        }
        else
        {
                me->add("neili", -100);
                msg += CYN "$n" CYN "��״���һ������æ�������������"
                       "���ڱܿ���$N" CYN "��һ����\n" NOR;
                me->start_busy(4);
        }
        message_combatd(msg, me, target);
        return 1;
}
