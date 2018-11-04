#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";

#define SHE "��" HIR "���վ�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, i;
        int n, p;
        int my_exp, ob_exp;
        string pmsg;
        string msg;
        object weapon;

        if (userp(me) && ! me->query("can_perform/fenglei-zifa/she"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHE "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("handing")) ||
            (string)weapon->query("skill_type") != "throwing" ||
            weapon->query_amount() < 1)
                return notify_fail("���������в�û�����Ű������޷�ʩչ��" SHE "��\n");

        if ((skill = me->query_skill("fenglei-zifa", 1)) < 100)
                return notify_fail("��ķ����ӷ�������죬�޷�ʩչ" SHE "��\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("���������㣬�޷�ʩչ" SHE "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        me->add("neili", -80);
        weapon->add_amount(-1);

        msg = HIR "$N" HIR "����΢΢һչ������һ�Σ�ֻ����쬡���һ����һ" +
             weapon->query("base_unit") + weapon->name() + HIR "�������" +
             "����$n" HIR "��ȥ��\n" NOR;

        me->start_busy(2);
        my_exp = me->query("combat_exp") + skill * skill / 10 * skill;
        ob_exp = target->query("combat_exp");
        p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
        if (random(my_exp) > ob_exp * 2 / 3)
        {
                msg += HIR "$n" HIR "���ܲ�������ʱ�����д��˸�Ѫ��ģ��"
                       "�Ŀ������������۵ü�����Ҫɢ�ܡ�\n" NOR;
                target->receive_wound("qi", skill / 2 + random(skill / 2), me);
                COMBAT_D->clear_ahinfo();
                weapon->hit_ob(me, target, me->query("jiali") + 150);
                if (stringp(pmsg = COMBAT_D->query_ahinfo()))
                        msg += pmsg;
                        msg += "( $n" + eff_status_msg(p) + " )\n";
                message_combatd(msg, me, target);
        } else
        {
                msg += CYN "����$p" CYN "����һ�ݣ���������$P" CYN "������" +
                       weapon->name() + CYN "��\n" NOR;
                message_combatd(msg, me, target);
        }

        me->reset_action();
        return 1;
}
