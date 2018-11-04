#include <ansi.h>
#include <combat.h>

#define SUO "��" HIY "���Ž���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
	int level;

        if (userp(me) && ! me->query("can_perform/jinguan-yusuo/suo"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SUO "ֻ����ս���в���ʹ�á�\n");

        if ((level = me->query_skill("jinguan-yusuo", 1)) < 150)
                return notify_fail("��Ľ��������������������ʩչ" SUO "��\n" NOR);

        if ((int)me->query_skill("force") < 200)
                return notify_fail("����ڹ�����㣬����ʩչ" SUO "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����ڵ��������㣬����ʩչ" SUO "��\n" NOR);

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "ͻȻ��$N" HIY "˫����Ļ�Ȧ��ʹ����" HIR "���Ž���"
              HIY "����������ͼ����$n" HIY "��������\n" NOR;

        if (random(level) > (int)target->query_skill("parry", 1) / 2)
        {
                msg += HIR "��ʱ$n" HIR "ֻ������һ����˫��̱��ȫ��"
                       "�������Ʊ�$N" HIR "������ס��\n" NOR;
                target->start_busy(level / 16);
                me->add("neili", -100);
                me->start_busy(1);
        } else
        {
                msg += HIC "����$n" HIC "�������ܣ�˿����Ϊ$N"
                       HIC "���������ҡ�\n" NOR;
                me->add("neili", -50);
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}
