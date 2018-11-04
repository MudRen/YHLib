#include <ansi.h>

#define HEAL "��" HIR "��������" NOR "��"

int perform(object me, object target)
{
        string force;

        if (userp(me) && ! me->query("can_perform/yiyang-zhi/heal"))
                return notify_fail("����ѧ���⹦��û�����ֹ��ܡ�\n");

        if (! target)
                return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");

        if (target == me)
                return notify_fail(HEAL "ֻ�ܶԱ���ʩչ��\n");

        if (me->is_fighting() || target->is_fighting())
                return notify_fail("ս�����޷��˹����ˡ�\n");

        if (target->query("not_living"))
                return notify_fail("���޷���" + target->name() + "���ˡ�\n");

        if ((int)me->query_skill("yiyang-zhi", 1) < 100)
                return notify_fail("���һ��ָ��������죬����ʩչ" HEAL "��\n");

        if ((int)me->query_skill("jingluo-xue", 1) < 100)
                return notify_fail("��Ծ���ѧ���˽ⲻ��������ʩչ" HEAL "��\n");

        if (me->query_skill_mapped("finger") != "yiyang-zhi")
                return notify_fail("��û�м���һ��ָ������ʩչ" HEAL "��\n");

        if (me->query_skill_prepared("finger") != "yiyang-zhi")
                return notify_fail("��û��׼��һ��ָ������ʩչ" HEAL "��\n");

        if (! (force = me->query_skill_mapped("force")))
                return notify_fail("����뼤��һ���ڹ�����ʩչ" HEAL "��\n");

        if ((int)me->query("max_neili") < 1500)
                return notify_fail("���������Ϊ̫ǳ������ʩչ" HEAL "��\n");

        if ((int)me->query("neili") < 1000)
                return notify_fail("�����ڵ��������㣬����ʩչ" HEAL "��\n");

        if ((int)me->query("jing") < 100)
                return notify_fail("�����ڵ�״̬���ѣ�����ʩչ" HEAL "��\n");

        if (target->query("eff_qi") >= target->query("max_qi") &&
            target->query("eff_jing") >= target->query("max_jing"))
                return notify_fail("�Է�û�����ˣ�����Ҫ�������ơ�\n");

        message_sort(HIY "\nֻ��$N" HIY "ĬĬ��ת" + to_chinese(force) +
                     HIY "����������һ������ͷ������ð��������Ȼʩչ��"
                     "һ��ָ�����Դ���ָ��˲ʱ�����$n" HIY "ȫ����ʮ��"
                     "����Ѩ������һ�ᣬ�����$n" HIY "���ۡ���һ���³�"
                     "������Ѫ����ɫ��ʱ������������ˡ�\n" NOR, me, target);

        me->add("neili", -800);
        me->receive_damage("qi", 100);
        me->receive_damage("jing", 50);

        target->receive_curing("qi", 100 + (int)me->query_skill("force") +
                                     (int)me->query_skill("yiyang-zhi", 1) * 3);

        if (target->query("qi") <= 0)
                target->set("qi", 1);

        target->receive_curing("jing", 100 + (int)me->query_skill("force") / 3 +
                                       (int)me->query_skill("yiyang-zhi", 1));

        if (target->query("jing") <= 0)
                target->set("jing", 1);

        if ((int)target->query_condition("tiezhang_yin")
           || (int)target->query_condition("tiezhang_yang"))
        {
                target->clear_condition("tiezhang_yin");
                target->clear_condition("tiezhang_yang");
                tell_object(target, HIC "\n��ֻ�����ڲд�������ƾ�����"
                                    "���ˣ��о��ö��ˡ�\n" NOR);
        }

        if ((int)target->query_condition("freezing"))
        {
                target->clear_condition("freezing");                
                tell_object(target, HIC "\n��ֻ��������תů����������֮������ʧ����Ӱ���١�\n" NOR);
        }

        if (! living(target))
                target->revive();

        if (! target->is_busy())
                target->stary_busy(2);

        message_vision("\n$N��Ŀڤ������ʼ�˹���Ϣ��\n", me);
        me->start_busy(10);
        return 1;
}
