#include <ansi.h>

#define HUA "��" MAG "����" NOR "��"

inherit F_SSERVER;

inherit F_CLEAN_UP;

void remove_effect(object me, int amount, int amount1);

int perform(object me, object target)
{
        object weapon;  
        string msg;
        int count, cnt, skill;

        if (userp(me) && ! me->query("can_perform/zhuangzi-wu/hua"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if ((int)me->query_temp("hua_die"))
                return notify_fail("���Ѿ�����" HUA "�ˡ�\n");

        if ((int)me->query_skill("zhuangzi-wu", 1) < 150)
                return notify_fail("���ׯ����ȼ�����������ʩչ" HUA "��\n");

        if ((int)me->query_dex() < 32)
                return notify_fail("���������������ʩչ" HUA "��\n");

        if ((int)me->query_skill("force", 1) < 150)
                return notify_fail("����ڹ���򲻹�������ʩչ" HUA "��\n");

        if ((int)me->query_skill("dodge", 1) < 150)
                return notify_fail("����Ṧ��Ϊ����������ʩչ" HUA "��\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("���������Ϊ����������ʩչ" HUA "��\n");

        if ((int)me->query("neili") < 250)
                return notify_fail("���ʱ���������㣬����ʩչ" HUA "��\n");

        msg = MAG "$N" MAG "һ����Х������һչ���貽����������ˮ���ʵ���"
              "��ٶȱ���쳣���ݡ�\n\n" NOR;
        
        message_combatd(msg, me, target);
        skill = me->query_skill("zhuangzi-wu", 1);
        cnt = (int)((int)me->query_condition("drunk") / 3);

        count = skill / 50;

        if (me->is_fighting())
                me->start_busy(2);

        me->add_temp("dex", count);
        me->set_temp("hua_die", 1);
        me->start_call_out((: call_other,  __FILE__, "remove_effect", me, count :), skill / 2);

        me->add("neili", -200);
        return 1;
}

void remove_effect(object me, int amount, int amount1)
{
        if ((int)me->query_temp("hua_die"))
        {
                me->add_temp("dex", -amount);
                me->delete_temp("hua_die");
                tell_object(me, "���" HUA "������ϣ��������ջص��\n");
        }
}
