#include <ansi.h>

inherit F_SSERVER;

#define YING "��" HIY "��Ӱ��" NOR "��"

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
        int skill, i;
        int n;
        int my_exp, ob_exp, p;
        string pmsg;
        string msg;
        object weapon;

        if (! target) target = offensive_target(me);

        if (! me->query("can_perform/yufeng-zhen/ying"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(YING "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("handing")) ||
            (string)weapon->query("skill_type") != "throwing")
                return notify_fail("���������в�û�������룬��ôʩչ" YING "��\n");

        if (weapon->query_amount() < 1)
                return notify_fail("������û���룬�޷�ʩչ" YING "��\n");

        if ((skill = me->query_skill("yufeng-zhen", 1)) < 100)
                return notify_fail("���������ַ�������죬����ʹ��" YING "��\n");

        if (me->query_skill("force") < 100)
                return notify_fail("����ڹ���򲻹����޷�ʩչ" YING "��\n");

        if (me->query_skill_mapped("throwing") != "yufeng-zhen")
                return notify_fail("��û�м�������룬����ʹ��" YING "��\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�������������޷�ʩչ" YING "\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        me->add("neili", -80);
        weapon->add_amount(-1);

        msg= HIY "$N" HIY "���ţ��㲻�ƣ�����ֻ������һ����ֻ��"
             "һ�㺮������������������$n" HIY "��\n" NOR;

        me->start_busy(2 + random(2));

        my_exp = me->query_skill("throwing");
        ob_exp = target->query_skill("dodge");
        if (my_exp / 2 + random(my_exp) > ob_exp)
        {
                msg += HIR "���$p" HIR "��Ӧ����������$P" + HIR "һ" +
                       weapon->query("base_unit") + weapon->name() +
                       HIR "��\n" NOR;
                target->receive_wound("qi", skill + random(skill / 3), me);

                COMBAT_D->clear_ahinfo();
                weapon->hit_ob(me, target, me->query("jiali") + 100);
    
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
