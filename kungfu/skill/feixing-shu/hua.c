// huayu.c

#include <ansi.h>
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;

#define YU "��" HIG "���컨��" NOR "��"

int perform(object me, object target)
{
        int skill, i;
        int n, p;
        int my_exp, ob_exp;
        string pmsg;
        string msg;
        object weapon;

       if (userp(me) && ! me->query("can_perform/feixing-shu/hua"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(YU "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("handing")) ||
            (string)weapon->query("skill_type") != "throwing")
                return notify_fail("���������в�û�����Ű�����\n");

        if (weapon->query_amount() < 10)
                return notify_fail("����Ҫ��ʮö���������ʩչ" YU "��\n");

        if ((skill = me->query_skill("feixing-shu", 1)) < 100)
                return notify_fail("��ķ�����������죬����ʹ��" YU "��\n");
 
        if ((int)me->query_skill("force", 1) < 120)
                return notify_fail("����ڹ���򲻹�������ʹ��" YU "��\n");

        if (me->query_skill_mapped("throwing") != "feixing-shu")
                return notify_fail("��û�м���������Ϊ�����������޷�ʩչ" YU "��\n");

        if ((int)me->query("neili") < 250)
                return notify_fail("�����������ˡ�\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        me->add("neili", -100);
        weapon->add_amount(-10);

        msg= HIG "ֻ��һ�ɾ����$N" HIG "���Ҳ෢����$N" HIG
             "���е�" + weapon->name() + HIG "���������$n"
             HIG "���ֹ�ȥ��\n" NOR;

        me->start_busy(2);
        my_exp = me->query("combat_exp") + skill * skill / 10 * skill;
        ob_exp = target->query("combat_exp");
        if (random(my_exp) > ob_exp)
        {
                me->add("neili", -100);
                n = 1 + random(2);
 
                if (random(my_exp) > ob_exp) n += 1 + random(2);
                if (random(my_exp / 2) > ob_exp) n += 1 + random(2);
                if (random(my_exp / 4) > ob_exp) n += 1 + random(2);
                msg += HIR "���$n" HIR "��Ӧ����������$N" HIR +
                       chinese_number(n) + weapon->query("base_unit") +
                       weapon->name() + HIR "��\n" NOR;

                target->receive_wound("qi", skill / 3 + random(skill / 3), me);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
                while (n--)
                {
                        COMBAT_D->clear_ahinfo();
                        weapon->hit_ob(me, target, me->query("jiali") + 100 + n * 10);
                }
                if (stringp(pmsg = COMBAT_D->query_ahinfo()))
                        msg += pmsg;
                        msg += "( $n" + eff_status_msg(p) + " )\n";
                
                message_combatd(msg, me, target);
        } else
        {
                msg += NOR + CYN "����$n" CYN  "���鶯�������$N" CYN  "����������" +
                       weapon->name() + CYN  "��\n" NOR;
                message_combatd(msg, me, target);
        }

        me->reset_action();
        return 1;
}
