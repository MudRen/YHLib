#include <ansi.h>
#include <combat.h>

#define JIN "��" HIY "��ս���" NOR "��"

inherit F_SSERVER;

string final(object me, object target, int damage);

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/canhe-zhi/jin"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(JIN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("�������ֲ���ʹ��" JIN "��\n");

        if ((int)me->query_skill("canhe-zhi", 1) < 160)
                return notify_fail("��Ĳκ�ָ��Ϊ���ޣ�����ʩչ" JIN "��\n");

        if (me->query_skill_prepared("finger") != "canhe-zhi")
                return notify_fail("������û��׼��ʹ�òκ�ָ������ʩչ" JIN "��\n");

        if ((int)me->query("max_neili") < 2500)
                return notify_fail("���������Ϊ���㣬����ʩչ" JIN "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����������������ʩչ" JIN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "˫�ֺ�ʮ��΢΢һЦ���ĵ��黨֮�⡣ʳָ����ָ"
              "����һ������ʱһ����������������$n" HIY "Ϯȥ��\n" NOR;  

        ap = me->query_skill("canhe-zhi", 1) + me->query_skill("force");
        dp = target->query_skill("buddhism", 1) + target->query_skill("force");
        me->start_busy(3);

        if ((int)target->query_skill("buddhism", 1) >= 200
            && random(5) == 1)
        {
                me->add("neili", -400);
                me->start_busy(4);
                msg += HIY "����$n" HIY "Ҳ����¶Ц�ݣ���������һ����˳��"
                       "���ϣ��ٽ�$N" HIY "��ָ�����Ŵ�����\n" NOR;
        } else
        if (ap * 2 / 3 + random(ap) > dp)
        { 
                damage = ap + random(ap / 2);
                me->add("neili", -400);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 75,
                                           (: final, me, target, damage :));
        } else
        {
                me->add("neili", -200);
                me->start_busy(4);
                msg += CYN "$n" CYN "��$N" CYN "������ӿ����������"
                       "�мܣ���æ����Ծ����\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

string final(object me, object target, int damage)
{
        target->receive_damage("jing", damage / 6, me);
        target->receive_wound("jing", damage / 10, me);
        return  HIR "ֻ�������͡�һ����ָ������$n" HIR
                "��ǰ����һ��Ѫ��ģ���Ĵ󶴣�͸����롣\n" NOR;
}
