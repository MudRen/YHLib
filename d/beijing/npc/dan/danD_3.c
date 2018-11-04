#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(HIC"��Ԫ��"NOR, ({"guiyuan dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("base_unit", "��");
                set("base_value", 70);
                set("only_do_effect", 1);
        }
        setup();
        set_amount(1);
}

int do_effect(object me)
{
        mapping my;
        int nl, mn;

        if (time() - me->query_temp("last_eat/dan(D)") < 180)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        my = me->query_entire_dbase();
        nl = (int)me->query("neili") + 500;
        mn = (int)me->query("max_neili") * 2;

        if (nl > mn)
        {
                write("������������Ϊ�������" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/dan(D)", time());

        message_vision(HIC "$N����һ����Ԫ�����е������������䡣\n" NOR, me);
        me->add("neili", 500);

        me->start_busy(3);

        add_amount(-1);
        if (query_amount() < 1)
                destruct(this_object());

        return 1;
}
