inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIW "������" NOR, ({"ningbing dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 3000);
                set("long", HIW "�嶾�̵��񵤣��ܽ�󸶾��ɰ����\n" NOR);
                set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{
        message_vision(HIW "$N" HIW "��������һ����������\n" NOR, me);

        if ((int)me->query_condition("tianchan_zhang")
           || (int)me->query_condition("sha_poison"))
        {
                if (me->query_condition("tianchan_zhang"))
                        me->clear_condition("tianchan_zhang");

                if (me->query_condition("sha_poison"))
                        me->clear_condition("sha_poison");

                me->start_busy(2);
                tell_object(me, HIC "��е���Ϣһ�������ڵĶ��ؿ�ʼ�������ˡ�\n" NOR);
        }
        destruct(this_object());
        return 1;
}
