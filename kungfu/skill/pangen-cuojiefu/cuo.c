#include <ansi.h>
#include <combat.h>

#define CUO "��" HIR "���־�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int level;
	string msg;

        if (userp(me) && ! me->query("can_perform/pangen-cuojiefu/cuo"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(CUO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "hammer")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" CUO "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((level = me->query_skill("pangen-cuojiefu", 1)) < 100)
                return notify_fail("���̸���ڸ�������죬����ʩչ" CUO "��\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ���򲻹�������ʩչ" CUO "��\n");

        if ((int)me->query("max_neili") < 800)
                return notify_fail("���������Ϊ����������ʩչ" CUO "��\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("��������������������ʩչ" CUO "��\n");

        if (me->query_skill_mapped("hammer") != "pangen-cuojiefu")
                return notify_fail("��û�м����̸���ڸ�������ʩչ" CUO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIR "$N" HIR "�߾�����" + weapon->name() + HIR "����Ȼһ���Ϻȣ�����$n"
              HIR "�ͻ�������������硣\n" NOR;

        me->add("neili", -30);
        if (random(level) > (int)target->query_skill("parry", 1) / 2)
        {
		msg += HIR "$p" HIR "��$P" HIR "������ӿ�����ò���;"
                       "���У���һ�µ�ʱ��ʧ���Ȼ���\n" NOR;
                target->start_busy(level / 18 + 1);
	} else
        {
		msg += CYN "����$p" CYN "����$P" CYN "��ʽ����·��б"
                       "б������ʹ����δ��˿�����á�\n" NOR;
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}
