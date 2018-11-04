#include <ansi.h>
#include <combat.h>

#define SHE "��" HIR "��ǹ�������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int i;

        if (userp(me) && ! me->query("can_perform/gun/she"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
                return notify_fail(SHE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "hammer")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" SHE "��\n");

        if ((int)me->query_skill("gun", 1) < 80)
                return notify_fail("���ǹе������������������ʩչ" SHE "��\n");

        if (me->query_skill_mapped("hammer") != "gun")
                return notify_fail("�㲢û������ǹе����������ʩչ" SHE "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "ʩ���ذ��塸��ǹ���������������" + weapon->name() +
              HIR "������ǹ��ͬʱ�����ʮ����������$n" HIR "���ܣ�\n\n" NOR;
        message_combatd(msg, me, target);

        for (i = 0; i < 18; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->start_busy(1);
        return 1;
}
