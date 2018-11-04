#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";

#define XIAN "��" HIY "������Ӱ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int ap, dp, damage, p;
        string pmsg;
        string msg;
        object weapon;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/furong-jinzhen/xian"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(XIAN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("handing")) ||
            (string)weapon->query("skill_type") != "throwing")
                return notify_fail("���������в�û�����Ű�����\n");

        if ((int)me->query_skill("furong-jinzhen", 1) < 80)
                return notify_fail("���ܽ�ؽ��벻����죬����ʩչ" XIAN "��\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ���򲻹�������ʩչ" XIAN "��\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("�����������ˡ�\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        me->add("neili", -100);
        weapon->add_amount(-1);

        msg = HIY "ֻ��$N" HIY "��ָ��Ȼ���ţ�$n" HIY "������ǰ���һ"
              "�������ɾ����漴���������\n" NOR;

        me->start_busy(2);

        ap = me->query_skill("force") + me->query_skill("throwing");
        dp = target->query_skill("dodge") + target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 5 + random(ap / 5);

                msg += HIR "$n" HIR "΢΢һ㶣�ȴ�ѱ�$N" HIR
                       "��" + weapon->query("base_unit") +
                       weapon->name() + HIR "����ҪѨ������"
                       "���֮�\n" NOR;

                target->receive_wound("qi", damage, me);
                COMBAT_D->clear_ahinfo();
                weapon->hit_ob(me, target, me->query("jiali") + 100);

                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");

                if (stringp(pmsg = COMBAT_D->query_ahinfo()))
                        msg += pmsg;
                        msg += "( $n" + eff_status_msg(p) + " )\n";
                message_combatd(msg, me, target);

        } else
        {
                msg += CYN "����$p" CYN "���ϵ�$P" CYN
                       "�д�һ�ţ���æ����Ծ�𣬶���������"
                       "\n" NOR;
                message_combatd(msg, me, target);
        }
        me->reset_action();
        return 1;
}
