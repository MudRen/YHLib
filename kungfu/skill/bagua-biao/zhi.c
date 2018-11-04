#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";

#define ZHI "��" HIY "Ǭ��һ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, i, p;
        int n;
        int my_exp, ob_exp;
        string pmsg;
        string msg;
        object weapon;

        if (userp(me) && ! me->query("can_perform/bagua-biao/zhi"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHI "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("handing")) ||
            (string)weapon->query("skill_type") != "throwing")
                return notify_fail("���������в�û�����Ű�����\n");

        if (weapon->query_amount() < 30)
                return notify_fail("����Ҫ����ʮö���������ʩչ" ZHI "��\n");

        if ((skill = me->query_skill("bagua-biao", 1)) < 120)
                return notify_fail("��İ����ھ�������죬����ʩչ" ZHI "��\n");

        if ((int)me->query_skill("force") < 200)
                return notify_fail("����ڹ���򲻹�������ʩչ" ZHI "��\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("�������������㣬����ʩչ" ZHI "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg= HIY "ֻ��$N" HIY "����һԾ����һ�����ȣ�ʮָ���ţ�����������"
             "��" + weapon->name() + HIY "���˳�ȥ��\n";

        my_exp = me->query("combat_exp") + skill * skill / 10 * skill;
        ob_exp = target->query("combat_exp");

        if (random(my_exp) > ob_exp)
        {
                n = 5 + random(5);
                if (random(my_exp) > ob_exp) n += 5 + random(5);
                if (random(my_exp / 2) > ob_exp) n += 5 + random(5);
                if (random(my_exp / 4) > ob_exp) n += 5 + random(10);
                if (weapon->query_amount() < n) n = weapon->query_amount();

                msg += "$p" HIY "ɲʱֻ����ǰ����������Ӧ��������������$P"
                       HIY + chinese_number(n) + weapon->query("base_unit") +
                       weapon->name() + HIY "��\n" NOR;
                target->receive_damage("qi", skill * 3 / 2 + random(skill * 3 / 2), me);
                target->receive_wound("qi", skill * 2 / 3 + random(skill * 2 / 3), me);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");

                while (n--)
                {
                        COMBAT_D->clear_ahinfo();
                        weapon->hit_ob(me, target, me->query("jiali") + 150 + n * 30);
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
