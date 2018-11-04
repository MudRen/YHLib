#include <ansi.h>

#define DIAN "��" HIW "���쾢����Ծ��" NOR "��"

int exert(object me, object target)
{
        if (userp(me) && ! me->query("can_perform/taiji-shengong/dian"))
                return notify_fail("����ѧ���ڹ���û�����ֹ��ܡ�\n");

        if (! target)
                return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");

        if (target == me)
                return notify_fail(DIAN "ֻ�ܶԱ���ʩչ��\n");

        if (me->is_fighting() || target->is_fighting())
                return notify_fail("ս�����޷��˹����ˡ�\n");

        if (target->query("not_living"))
                return notify_fail("���޷���" + target->name() + "���ˡ�\n");

        if ((int)me->query_skill("taiji-shengong", 1) < 100)
                return notify_fail("���̫���񹦲�����죬����ʩչ" DIAN "��\n");

        if ((int)me->query("max_neili") < 1500)
                return notify_fail("���������Ϊ̫ǳ������ʩչ" DIAN "��\n");

        if ((int)me->query("neili") < 1000)
                return notify_fail("�����ڵ��������㣬����ʩչ" DIAN "��\n");

        if ((int)me->query("jing") < 100)
                return notify_fail("�����ھ���״̬���ѣ�����ʩչ" DIAN "��\n");

        if (target->query("eff_qi") >= target->query("max_qi") &&
            target->query("eff_jing") >= target->query("max_jing"))
                return notify_fail("�Է�û�����ˣ�����Ҫ�������ơ�\n");

        message_sort(HIW "\nֻ��$N" HIW "˫��ʳָ��Ĵָ���ã��ɺ��쾢"
                     "�ƣ���ʳָָ�����$n" HIW "�������ִ�����Ծ�ϣ�"
                     "�����ڹ���΢΢�ڶ������к��쾢����Ծ��ʹ��������"
                     "�����¶���֮��Ҳ�ܻ���Ƭ�̡�����һ������$p��ͷ"
                     "��ð�������飬ͷ��ð�����������۵�һ���³���"
                     "Ѫ����ɫ��ʱ������������ˡ�\n" NOR, me, target);

        me->add("neili", -800);
        me->receive_damage("qi", 100);
        me->receive_damage("jing", 50);

        target->receive_curing("qi", 100 + (int)me->query_skill("force") +
                                     (int)me->query_skill("taiji-shengong", 1) * 3);

        if (target->query("qi") <= 0)
                target->set("qi", 1);

        target->receive_curing("jing", 100 + (int)me->query_skill("force") / 3 +
                                       (int)me->query_skill("taiji-shengong", 1));

        if (target->query("jing") <= 0)
                target->set("jing", 1);

        if (! living(target))
                target->revive();

        if (! target->is_busy())
                target->stary_busy(2);

        message_vision("\n$N��Ŀڤ������ʼ�˹���Ϣ��\n", me);
        me->start_busy(10);
        return 1;
}
