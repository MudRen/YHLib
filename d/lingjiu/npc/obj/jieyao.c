#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC "ҩ��" NOR, ({"yao wan", "yao", "wan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIC "һ�Ż�Բ��ҩ�裬�������ϴ������ƵĶ��Ž�ҩ��\n" NOR);
                set("unit", "��");
                set("value", 300);
                set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{
        message_vision(HIC "$N" HIC "һ����������һ��ҩ�衣\n" NOR, me);
        if ((int)me->query_condition("lb_poison"))
        {
                me->clear_condition("lb_poison");
                me->start_busy(2);
                tell_object(me, HIY "��е���Ϣһ�������ڵ��̲��綾��ʼ�������ˡ�\n" NOR);

        }
        destruct(this_object());
        return 1;
}
