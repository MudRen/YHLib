#include <ansi.h>
#include <combat.h>

#define LUO "��" HIW "�������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int i;

        if (userp(me) && ! me->query("can_perform/biyan-dao/luo"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LUO "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("����������ԣ�����ʩչ" LUO "��\n");

        if ((int)me->query_skill("biyan-dao", 1) < 80 )
                return notify_fail("����̵���������죬����ʩչ" LUO "��\n");

        if ((int)me->query_skill("force") < 120 )
                return notify_fail(RED"���ڹ���򲻹�������ʩչ" LUO "��\n");

        if (me->query_skill_mapped("blade") != "biyan-dao")
                return notify_fail("��û�м������̵���������ʩչ" LUO "��\n");

        if ((int)me->query("neili") < 80)
                return notify_fail(HIC"��������������������ʩչ" LUO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "���һ��������" + weapon->name() + HIW
              "һ�񣬱������һ����$n" HIW "ϯ���ȥ��\n" NOR;
        message_combatd(msg, me, target);

        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;
        	COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add("neili", -80);
        me->start_busy(1 + random(3));
        return 1;
}
