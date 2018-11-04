#include <ansi.h>
#include <combat.h>

#define PO "��" HIR "����ʽ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        string *learned;
        object weapon, weapon2;
        string type;
        mapping prepare;
        int n;
        int skill, ap, dp, damage, ss;

        if (me->query("can_learn/dugu-jiujian/nothing"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");                

        if (userp(me) && me->query("can_perform/dugu/po") < 100)
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        me->clean_up_enemy();
        if (! target) target = me->select_opponent();

        skill = me->query_skill("dugu-jiujian", 1);

        if (! me->is_fighting(target))
                return notify_fail(PO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (skill < 150)
                return notify_fail("��Ķ��¾Ž��ȼ��������޷�ʩչ" PO "��\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ��޷�ʩչ" PO "��\n");

        if (me->query_skill_mapped("sword") != "dugu-jiujian") 
                return notify_fail("��û�м������¾Ž����޷�ʩչ" PO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        weapon2 = target->query_temp("weapon");
        prepare = target->query_skill_prepare();

        if (weapon2) type = weapon2->query("skill_type");
        else if (! prepare || sizeof(prepare) == 0) type = "unarmed";
        else if (sizeof(prepare) == 1) type = (keys(prepare))[0];
        else if (sizeof(prepare) == 2) 
                type = (keys(prepare))[target->query_temp("action_flag")];

        ap = skill + me->query_skill("sword", 1);

        learned = me->query("can_perform/dugu-jiujian");

        if (arrayp(learned) && member_array(type, learned) != -1)
                ap *= 2;

        ss = target->query_skill("pixie-jian", 1);

        if (ss < target->query_skill("dugu-jiujian", 1))
                  ss = target->query_skill("dugu-jiujian", 1);

        dp = target->query_skill(type, 1) * 2 + ss;

        if (ap + random(ap) > dp)
        {
                msg = HIC "$N" HIC "����������е�" + weapon->name() +
                      HIC "�����дӳ��䲻��ķ�λֱָ$n" 
                      HIC + to_chinese(type)[4..<1] + "�е�������\n" NOR;

                n = 7 + random(7);
                if ((target->is_busy() && ap / 2 + random(ap) > dp)
                   || ap / 2 + random(ap) > dp)
                {
                        msg += HIY "$n" HIY "���һ��������֮������������"
                               "$N" HIY "��������" + chinese_number(n)
                               + "����\n" NOR;
                        message_combatd(msg, me, target);

                        me->start_busy(1 + random(n));
                        while (n-- && me->is_fighting(target))
                        {
                                if (! target->is_busy() && random(2))
                                        target->start_busy(1);
                                COMBAT_D->do_attack(me, target, weapon, 0);
                        }

                        if (weapon2 && random(ap) > dp && type != "pin")
                        {
                                msg = HIW "$n" HIW "������ǰ�ۻ����ң�����"
                                      "��" + weapon2->name() + HIW "һʱ��"
                                      "Ȼ����ס�����ֶ�����\n" NOR;
                                weapon2->move(environment(me));
                        } else
                        {
                                msg = HIY "$n" HIY "�Եÿ�϶��Ϣ��һʱ��ȴ"
                                      "Ҳ����������\n" NOR;
                        }
                } else
                {
                        msg += HIY "$n" HIY "��æ�ֵ���һʱ�䲻����æ���ң�"
                               "��Ͼ������\n" NOR;
                        me->start_busy(1);
                        target->start_busy(1 + random(skill / 30));
                }
        } else
        {
                msg = HIC "$N" HIC "�������е�" + weapon->name() +
                      HIC "��������ָ������$n" HIC "���ص��쳣���ܣ�$N"
                      HIC "һʱ��Ȼ�޷��ҵ�������\n" NOR;
                me->start_busy(3 + random(2));
                target->start_busy(1);
        }
        message_combatd(msg, me, target);
        return 1;
}
