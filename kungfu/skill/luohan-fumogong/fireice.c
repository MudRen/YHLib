#include <ansi.h>

inherit F_CLEAN_UP;

#define FIREICE "��" HIW "��" HIR "��" HIW "������" NOR "��"

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;
        string fam;
        fam = me->query("family/family_name");

        if (userp(me) && ! me->query("skybook/item/xuanbingjiu"))
                return notify_fail("����ѧ���ڹ���û�����ֹ��ܡ�\n");

        if (target != me)
                return notify_fail("��ֻ����" FIREICE "�������Լ���ս������\n");

        if ((int)me->query_temp("fireice"))
                return notify_fail("����������ʩչ" FIREICE "��\n");

        if ((int)me->query_skill("luohan-fumogong", 1) < 180)
                return notify_fail("���޺���ħ������㣬����ʩչ" FIREICE "��\n");

        if ((int)me->query("max_neili") < 4000)
                return notify_fail("���������Ϊ���㣬����ʩչ" FIREICE "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����ڵ��������㣬����ʩչ" FIREICE "��\n");

        skill = me->query_skill("luohan-fumogong", 1);
        me->add("neili", -300);
        me->receive_damage("qi", 0);

        message_combatd(HIC "$N" HIC "������Х����ת��" HIW "��"
                        HIR "��" HIW "������" HIC "������������"
                        "���Ƽ䣬�⻪������ɷΪ׳�ۡ�\n" NOR, me);

        me->add_temp("apply/unarmed_damage", skill / 4);
        me->add_temp("apply/damage", skill / 4);
        me->add_temp("apply/armor", skill / 2);
        me->set_temp("fireice", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect",
                              me, skill / 4 :), skill);

        if (me->is_fighting())
                me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if (me->query_temp("fireice"))
        {
                me->add_temp("apply/unarmed_damage", -amount);
                me->add_temp("apply/damage", -amount);
                me->add_temp("apply/armor", -amount * 2);
                me->delete_temp("fireice");
                tell_object(me, "���" FIREICE "������ϣ��������ջص��\n");
        }
}
