#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";

#define PO "��" HIW "�ƾ���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int ap, dp, damage, p;
        string pmsg;
        string msg;
        object weapon, weapon2;

        if (userp(me) && ! me->query("can_perform/tanzhi-shentong/po"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(PO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("handing"))
           || (string)weapon->query("skill_type") != "throwing")
                return notify_fail("������û�����Ű���������ʩչ" PO "��\n");

        if ((int)me->query_skill("tanzhi-shentong", 1) < 180)
                return notify_fail("�㵯ָ��ͨ��Ϊ����������ʩչ" PO "��\n");

        if ((int)me->query_skill("throwing", 1) < 180)
                return notify_fail("�����������Ϊ����������ʩչ" PO "��\n");

        if (me->query_skill_mapped("finger") != "tanzhi-shentong")
                return notify_fail("��û�м�����ָ��ͨ������ʩչ" PO "��\n");

        if (me->query_skill_prepared("finger") != "tanzhi-shentong")
                return notify_fail("��û��׼����ָ��ͨ������ʩչ" PO "��\n");

        if (me->query("max_neili") < 2400)
                return notify_fail("���������Ϊ���㣬����ʩչ" PO "��\n");

        if (me->query("neili") < 500)
                return notify_fail("�����ڵ���������������ʩչ" PO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        me->add("neili", -300);
        weapon->add_amount(-1);

        msg = HIW "����$N" HIW "˫Ŀ�������䣬�����ƿ���������һ" +
              weapon->query("base_unit") + weapon->name() + HIW "��"
              "ָ�ⵯ������������$n" HIW "��\n" NOR;

        ap = me->query_skill("finger") + me->query_skill("throwing");
        dp = target->query_skill("dodge") + target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
	        me->start_busy(2);
               	damage = ap / 2 + random(ap / 3);

                msg += HIR "ֻ����" + weapon->query("base_unit") +
                       weapon->name() + HIR "����Ѹ��֮����$n" HIR
                       "������Ͼ���ܣ������л������У�\n" NOR;

                target->receive_wound("qi", damage, me);
       	        COMBAT_D->clear_ahinfo();
               	weapon->hit_ob(me, target, me->query("jiali") + 300);

                if ((weapon2 = target->query_temp("weapon"))
                   && ap / 3 + random(ap) > dp)
                {
                        msg += HIW "$n" HIW "����һ�飬����" + weapon2->name() +
                               HIW "�������ֶ�����\n" NOR;
                        weapon2->move(environment(me));
                }

                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
                if (stringp(pmsg = COMBAT_D->query_ahinfo()))
       	                msg += pmsg;
               	        msg += "( $n" + eff_status_msg(p) + " )\n";
               	message_combatd(msg, me, target);
        } else
        {
	        me->start_busy(3);
                msg += CYN "����$p" CYN "���ϵ�$P" CYN "�д�һ�ţ���"
                       "æ����Ծ�𣬶���������\n" NOR;
                message_combatd(msg, me, target);
        }
        me->reset_action();
        return 1;
}
