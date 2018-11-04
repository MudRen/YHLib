// liu.c

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";

#define LIU "��" HIY "���ǵ���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, i, p;
        int n;
        int my_exp, ob_exp;
        string pmsg;
        string msg;
        object weapon;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/kunlun-qifa/liu"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(LIU "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("handing")) ||
            (string)weapon->query("skill_type") != "throwing")
                return notify_fail("���������в�û�����Ű������޷�ʩչ" LIU "��\n");

        if (weapon->query_amount() < 20)
                return notify_fail("����Ҫ�ж�ʮö���������ʩչ" LIU "��\n");

        if ((skill = me->query_skill("kunlun-qifa", 1)) < 120)
                return notify_fail("������������в���죬����ʩչ" LIU "��\n");

        if ((int)me->query_skill("force") < 200)
                return notify_fail("����ڹ���򲻹�������ʩչ" LIU "��\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("����������������ʩչ" LIU "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg= HIY "$N" HIY "һ����Ц������Ծ�𣬰����ʮָ��Ȼ���ţ����е�"
             + weapon->name() + HIY "��������һ����$n" HIY "��ȥ��\n";

        p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
        my_exp = me->query("combat_exp") + skill * skill / 10 * skill;
        ob_exp = target->query("combat_exp");

        if (random(my_exp) > ob_exp)
        {
                n = 5 + random(5);
                if (random(my_exp) > ob_exp) n += 5 + random(5);
                if (random(my_exp / 2) > ob_exp) n += 5 + random(5);
                if (random(my_exp / 4) > ob_exp) n += 5 + random(10);
                if (weapon->query_amount() < n) n = weapon->query_amount();

                msg += "$p" HIY "ֻ����ǰ����һ����������Ӧ��������������$P"
                       HIY + chinese_number(n) + weapon->query("base_unit") +
                       weapon->name() + HIY "��\n" NOR;
                target->receive_wound("qi", skill / 3 + random(skill / 2), me);
                while (n--)
                {
                        COMBAT_D->clear_ahinfo();
                        weapon->hit_ob(me, target,
                                       me->query("jiali") + 100 + n * 15);
                }
                if (stringp(pmsg = COMBAT_D->query_ahinfo()))
                        msg += pmsg;
                        msg += "( $n" + eff_status_msg(p) + " )\n";
                message_combatd(msg, me, target);
        } else
        {
                msg += NOR + CYN "����$p" CYN "�����ֿ죬�����$P" CYN "����"
                       "������" + weapon->name() + CYN "��\n" NOR;
                message_combatd(msg, me, target);
        }

        weapon->set_amount(0);
        me->add("neili", -100);
        me->start_busy(2);
        me->reset_action();
        return 1;
}
