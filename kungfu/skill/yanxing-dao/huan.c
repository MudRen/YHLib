#include <ansi.h>
#include <combat.h>

#define HUAN "��" HIY "���λ�Ӱ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int i;

        if (userp(me) && ! me->query("can_perform/yanxing-dao/huan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUAN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("����������ԣ�����ʩչ" HUAN "��\n");

        if ((int)me->query_skill("yanxing-dao", 1) < 60 )
                return notify_fail("�����е���������죬����ʩչ" HUAN "��\n");

        if ((int)me->query_skill("force") < 120 )
                return notify_fail(RED"���ڹ���򲻹�������ʩչ" HUAN "��\n");

        if (me->query_skill_mapped("blade") != "yanxing-dao")
                return notify_fail("��û�м������е���������ʩչ" HUAN "��\n");

        if ((int)me->query("neili") < 80)
                return notify_fail(HIC"��������������������ʩչ" HUAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "$N" HIC "���һ����ȫ���Ĵ��ζ���$n"
              HIC "ֻ����$N" HIC "����������Ӱ�����쵶"
              HIC "��ϯ�������\n"NOR;
        message_combatd(msg, me, target);

        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;
        	COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add("neili", -80);
        me->start_busy(1 + random(4));
        return 1;
}
