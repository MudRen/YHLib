#include <ansi.h>
#include <combat.h>

#define DU "��" YEL "����ɽ�" NOR "��"

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

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/pomie-jinzhen/du"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(DU "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("handing"))
           || (string)weapon->query("skill_type") != "throwing")
                return notify_fail("���������в�û�����Ű�����\n");

        if (weapon->query_amount() < 30)
                return notify_fail("������Ҫ���ж�ʮö��������ʩչ" DU "��\n");

        if ((skill = me->query_skill("pomie-jinzhen", 1)) < 150)
                return notify_fail("���������벻����죬����ʩչ" DU "��\n");

        if ((int)me->query_skill("force") < 200)
                return notify_fail("����ڹ���򲻹�������ʩչ" DU "��\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("�����ڵ��������㣬����ʩչ" DU "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = YEL "ֻ��$N" YEL "����һ�ʩ����" HIR "����ɽ�" NOR +
              YEL "��������" + weapon->name() + YEL "�缱�籩�����$n"
              YEL "��ȥ��\n" NOR;

        my_exp = me->query("combat_exp") + skill * skill / 10 * skill;
        ob_exp = target->query("combat_exp");

        if (random(my_exp) > ob_exp)
        {
                n = 4 + random(4);
                if (random(my_exp) > ob_exp) n += 4 + random(4);
                if (random(my_exp / 2) > ob_exp) n += 4 + random(4);
                if (random(my_exp / 4) > ob_exp) n += 4 + random(8);
                if (weapon->query_amount() < n) n = weapon->query_amount();

                msg += HIR "��ʱ��һƬ��â����$n" HIR "�ķ�������һ��"
                       "�ҽУ�" + chinese_number(n) + "����Ѫ�ɽ�����"
                       "��\n" NOR;

                target->receive_damage("qi", skill + random(skill), me);
                target->receive_wound("qi", skill / 2 + random(skill / 2), me);
	        p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
                while (n--)
                {
                        COMBAT_D->clear_ahinfo();
                        weapon->hit_ob(me, target, me->query("jiali") * 2 + 300 + n * 15);
                }
                if (stringp(pmsg = COMBAT_D->query_ahinfo()))
                        msg += pmsg;
                        msg += "( $n" + eff_status_msg(p) + " )\n";
                message_combatd(msg, me, target);
        } else
        {
                msg += CYN "����$n" CYN "˿�����Ҵ��⣬����������"
                       "�ܣ��㿪�����еİ�����\n" NOR;
                message_combatd(msg, me, target);
        }
        weapon->set_amount(0);
        me->add("neili", -100);
        me->start_busy(2);
        me->reset_action();
        return 1;
}
