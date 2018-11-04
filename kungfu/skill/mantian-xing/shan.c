#include <ansi.h>
#include <combat.h>

#define SHAN "��" HIY "�ǹ���˸" NOR "��"

#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, i, p, n;
        int my_exp, ob_exp;
        string pmsg;
        string msg;
        object weapon;

        if (userp(me) && ! me->query("can_perform/mantian-xing/shan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHAN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("handing")) ||
            (string)weapon->query("skill_type") != "throwing")
                return notify_fail("����������û�����Ű���������ʩչ" SHAN "��\n");

        if (weapon->query_amount() < 3)
                return notify_fail("����Ҫ����ö��������ʩչ" SHAN "��\n");

        if ((skill = me->query_skill("mantian-xing", 1)) < 100)
                return notify_fail("��������ǲ�����죬����ʩչ" SHAN "��\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�������������㣬����ʩչ" SHAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        me->add("neili", -80);
        weapon->add_amount(-3);

        msg= HIY "$N" HIY "ͻȻ�������һ�����������ڿ���ص�һ˲"
             "�䣬$n" HIY "��Ȼ���ּ��㺮����˸������Ϯ���Լ���\n" NOR;

        me->start_busy(2);
        my_exp = me->query("combat_exp") + skill * skill / 10 * skill;
        ob_exp = target->query("combat_exp");
        if (random(my_exp) > ob_exp)
        {
                msg += HIR "���$p" HIR "��Ӧ����������$P" + HIR "һ" +
                       weapon->query("base_unit") + weapon->name() +
                       HIR "��\n" NOR;
                target->receive_wound("qi", skill / 3 + random(skill / 3), me);
                COMBAT_D->clear_ahinfo();
                weapon->hit_ob(me, target, me->query("jiali") + 120);

                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");

                if (stringp(pmsg = COMBAT_D->query_ahinfo()))
                        msg += pmsg;
                        msg += "( $n" + eff_status_msg(p) + " )\n";
                message_combatd(msg, me, target);
        } else
        {
                msg += HIG "����$p" HIG "���ݲ��ȣ����ɵ�������$P" HIG "������" +
                       weapon->name() + HIG "��\n" NOR;
                message_combatd(msg, me, target);
        }

        me->reset_action();
        return 1;
}
