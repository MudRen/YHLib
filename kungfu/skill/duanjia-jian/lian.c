#include <ansi.h>
#include <combat.h>

#define LIAN "��" HIR "�������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg, skill;
        int i;

        if (userp(me) && ! me->query("can_perform/duanjia-jian/lian"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(LIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || ((string)weapon->query("skill_type") != "staff"
           && (string)weapon->query("skill_type") != "sword"))
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" LIAN "��\n");

        if ((int)me->query_skill("duanjia-jian", 1) < 120)
                return notify_fail("��Ķμҽ���������죬����ʩչ" LIAN "��\n");

        skill = weapon->query("skill_type");

        if (me->query_skill_mapped(skill) != "duanjia-jian")
                return notify_fail("������û�м����μҽ�������ʩչ" LIAN "��\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���Ϊ����������ʩչ" LIAN "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�����ڵ���������������ʩչ" LIAN "��\n");
        
        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "����һ���������²�������������֮�������е�" +
              weapon->name() + HIY "ʹ���������һ�㣬������$n" HIY "��\n" NOR;
        message_combatd(msg, me, target);

        me->add("neili", -100);

        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(5) == 0 && ! target->is_busy())
                        target->start_busy(1);
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->start_busy(1 + random(5));
        return 1;
}
