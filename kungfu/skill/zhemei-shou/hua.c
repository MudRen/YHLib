#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

#define HUA "��" HIR "������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp, p;
        int lv, cost_neili;

        if (userp(me) && ! me->query("can_perform/zhemei-shou/hua"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
        if (! target || ! me->is_fighting(target))
                return notify_fail(HUA "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(HUA "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("beiming-shengong", 1) < 220)
                return notify_fail("��ı�ڤ�񹦻�򲻹�������ʩչ" HUA "��\n");

        if (lv = (int)me->query_skill("zhemei-shou", 1) < 220)
                return notify_fail("����ң��÷�ֵȼ�����������ʩչ" HUA "��\n");

        if (me->query("max_neili") < 4000)
                return notify_fail("���������Ϊ���㣬����ʩչ" HUA "��\n");

        if (me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("��û�м�����ڤ�񹦣�����ʩչ" HUA "��\n");

        if (me->query_skill_mapped("hand") != "zhemei-shou")
                return notify_fail("��û�м�����ң��÷�֣�����ʩչ" HUA "��\n");

        if (me->query_skill_prepared("hand") != "zhemei-shou")
                return notify_fail("��û��׼����ң��÷�֣�����ʩչ" HUA "��\n");

        if (me->query("neili") < 800)
                return notify_fail("�������������㣬����ʩչ" HUA "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIM "$N" HIM "��������һ���������ֻӳ�����Ե��ʱϼ�����������"
              "��ɫ�����$n" HIM "ϯ�������\n" NOR;

        ap = me->query_skill("dodge", 1) + me->query_skill("hand");
        dp = target->query_skill("dodge", 1) + target->query_skill("parry");

        if (target->is_bad() || ! userp(target))
                ap += ap / 10;

        if (ap * 2 / 3 + random(ap) + random(20) > dp)
        {
                damage = 0;
                lv = me->query_skill("zhemei-shou", 1);
                if (lv >= 220)cost_neili = -500;
                if (lv >= 240)cost_neili = -470;
                if (lv >= 260)cost_neili = -440;
                if (lv >= 280)cost_neili = -400;
                if (lv >= 300)cost_neili = -360;
                if (lv >= 320)cost_neili = -320;
                if (lv >= 340)cost_neili = -300;
                if (lv >= 360)cost_neili = -270;
                if (lv >= 400)cost_neili = -200; 
                if (me->query("max_neili") > target->query("max_neili") * 2)
                {
                        msg += HIM "ֻ��$n" HIM "һ����Х��$N" HIM "����ɫ��"
                               "���Ѿ���ע��$p" HIM "���ڣ���ʱ��$p" HIM "��"
                               "Ϊһ̲Ѫˮ��\n" NOR "( $n" RED "���˹��أ���"
                               "��������в�����ʱ�����ܶ�����" NOR ")\n";
                        damage = -1;
                        me->add("neili", cost_neili);
                        me->start_busy(1);
                } else
                {
                        damage = ap;
                        damage += me->query_temp("apply/unarmed_damage");
                        damage += random(damage);

                        target->receive_damage("qi", damage, me);
                        target->receive_wound("qi", damage / 2, me);
                        target->receive_damage("jing", damage / 4, me);
                        target->receive_wound("jing", damage / 8, me);
                        p = (int)target->query("qi") * 100 / (int)target->query("max_qi");

                        msg += HIM "$n" HIM "ֻ��΢΢һ㶣�$N" HIM "����ɫ�ƾ��������"
                               "�룬$p" HIM "���������ú�¯һ�㣬��Ż������Ѫ��\n" NOR;
                        msg += "( $n" + eff_status_msg(p) + " )\n";
                        
                        me->add("neili", cost_neili);
                        me->start_busy(3);
                }
        } else
        {
                msg += CYN "$p" CYN "��״��ʧɫ����ȫ���Ʋ�͸$P"
                       CYN "���а��أ���������Ծ����������������\n" NOR;
                me->add("neili", -200);
                me->start_busy(4);
        }
        message_combatd(msg, me, target);

        if (damage < 0)
                target->die(me);

        return 1;
}
