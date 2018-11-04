#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;
        string fam;
        fam = me->query("family/family_name");

        // Ҫ��ֻ�кȹ������̻�ƻ�����������Ҳ���ʩչ
        if (userp(me)
           && fam != "������"
           && ! me->query("skybook/item/xuanbingjiu"))
                return notify_fail("����ѧ���ڹ���û�����ֹ��ܡ�\n");

        if (target != me)
                return notify_fail("��ֻ�����޺���ħ���������Լ���ս������\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("�������������\n");

        if ((int)me->query_temp("powerup"))
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("force");
        me->add("neili", -100);
        me->receive_damage("qi", 0);

        if (me->query("skybook/item/xuanbingjiu")
           && fam == "������")
	        message_combatd(HIY "$N" HIY "�ߺ�һ����ţ������޺���ħ��"
                                "����ȫ��Ƥ��һ�����" NOR + HIB "����" HIY
                                "ɫ����һ��ȴΪ" HIR "Ѫ��" HIY "ɫ��\n"
                                NOR, me);
        else

        if (fam == "������")
	        message_combatd(HIY "$N" HIY "�ߺ�һ����ţ������޺���ħ��"
                                "����ȫ���������ȣ�������֮���͡�\n"
                                NOR, me);

        else
	        message_combatd(HIY "$N" HIY "΢һ���������޺���ħ�񹦣�"
                                "ȫ������������ֳ�" NOR + HIB "����" HIY
                                "��" HIR "Ѫ��" HIY "��ɫ��\n" NOR, me);

 
        me->add_temp("apply/attack", skill / 3);
        me->add_temp("apply/defense", skill / 3);
        me->set_temp("powerup", 1);
       

        me->start_call_out((: call_other, __FILE__, "remove_effect",
                              me, skill / 3 :), skill);

        if (me->is_fighting())
                me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        if (me->query_temp("powerup"))
        {
                me->add_temp("apply/attack", -amount);
                me->add_temp("apply/defense", -amount);
                me->delete_temp("powerup");
                tell_object(me, "����޺���ħ��������ϣ��������ջص��\n");
        }
}
