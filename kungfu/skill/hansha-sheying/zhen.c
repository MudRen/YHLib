#include <ansi.h>
#include <combat.h>

#define ZHEN "��" HIR "��Ӱ��" NOR "��"

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
        int skill, i, p;
        int n;
        int my_exp, ob_exp;
        string pmsg;
        string msg;
        object weapon;

        if (userp(me) && ! me->query("can_perform/hansha-sheying/zhen"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHEN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("handing")) ||
            (string)weapon->query("skill_type") != "throwing")
                return notify_fail("���������в�û�����Ű���������ʩչ" ZHEN "��\n");

        if (weapon->query_amount() < 10)
                return notify_fail("����Ҫ��ʮö��������ʩչ" ZHEN "��\n");

        if ((skill = me->query_skill("hansha-sheying", 1)) < 120)
                return notify_fail("��ĺ�ɳ��Ӱ������죬����ʩչ" ZHEN "��\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻹�������ʩչ" ZHEN "��\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("�����ڵ��������㣬����ʩչ" ZHEN "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        me->add("neili", -100);
        weapon->add_amount(-10);

        msg= HIR "ֻ�������쬡�������һ�ɾ����$N" HIR "�����������$N" HIR
             "����" + weapon->name() + HIR "���������$n" HIR "���ֹ�ȥ��\n";

        me->start_busy(2);
        my_exp = me->query("combat_exp") + skill * skill / 10 * skill;
        ob_exp = target->query("combat_exp");
        if (random(my_exp) > ob_exp)
        {
                n = 1 + random(2);
                if (random(my_exp) > ob_exp) n += 1 + random(2);
                if (random(my_exp / 2) > ob_exp) n += 1 + random(2);
                if (random(my_exp / 4) > ob_exp) n += 1 + random(2);

                msg += "���$p" HIR "��Ӧ����������$P" HIR +
                       chinese_number(n) + weapon->query("base_unit") +
                       weapon->name() + HIR "��\n" NOR;
                target->receive_wound("qi", skill / 2 + random(skill / 2), me);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
                while (n--)
                {
                        COMBAT_D->clear_ahinfo();
                        weapon->hit_ob(me, target,
                                       me->query("jiali") + 100 + n * 10);
                }
                if (stringp(pmsg = COMBAT_D->query_ahinfo()))
                        msg += pmsg;
                        msg += "( $n" + eff_status_msg(p) + " )\n";
                message_combatd(msg, me, target);
        } else
        {
                msg += NOR + CYN "����$p" CYN "�����$P" CYN "����������" +
                       weapon->name() + NOR + CYN "��\n" NOR;
                message_combatd(msg, me, target);
        }
        me->reset_action();
        return 1;
}
