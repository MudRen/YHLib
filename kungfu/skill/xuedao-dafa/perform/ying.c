#include <ansi.h>
#include <combat.h>

#define YING "��" HIR "��Ӱ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;

        if (userp(me) && ! me->query("can_perform/xuedao-dafa/ying"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(YING "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" YING "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((int)me->query_skill("force") < 160)
                return notify_fail("����ڹ���򲻹�������ʩչ" YING "��\n");

        if ((int)me->query_skill("xuedao-dafa", 1) < 120)
                return notify_fail("���Ѫ���󷨻������ң�����ʩչ" YING "��\n");

        if (me->query_skill_mapped("force") != "xuedao-dafa")
                return notify_fail("��û�м���Ѫ����Ϊ�ڹ�������ʩչ" YING "��\n");

        if (me->query_skill_mapped("blade") != "xuedao-dafa")
                return notify_fail("��û�м���Ѫ����Ϊ����������ʩչ" YING "��\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�����������������ʩչ" YING "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = WHT "$N" WHT "һ����Ц�������е�" + weapon->name() +
              WHT "�趯���֣����漤����" HIR "Ѫ��" NOR +
              WHT "����$n" WHT "��ȥ��\n" NOR;

        me->add("neili", -80);
        if (random(me->query_skill("blade")) > target->query_skill("parry") / 2)
        {
                msg += HIR "���$p" HIR "��$P" HIR "�Ƶ���æ��"
                       "�ң�ֻ�ܽ����Ż��������ö���\n" NOR;
                target->start_busy((int)me->query_skill("blade") / 27 + 2);
        } else
        {
                msg += CYN "����$p" CYN "������$P" CYN "����ͼ"
                       "���������ţ�Ӧ�����硣\n" NOR;
                me->start_busy(1);
        }
        message_combatd(msg, me, target);

        return 1;
}
