#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG "����" NOR, ({"du nang", "dunang", "du", "nang"}));
        set("unit", "��");
        set("long", HIG "����һ������Ķ��ң����г����˶�Һ�������׹⡣\n" NOR);
        set("value", 100);
        set_weight(10);
        set("only_do_effect", 1);
        setup();
}

int do_effect(object me)
{
        message_vision("$Nһ�����������ҵĶ�Һ�����������С�\n", me);
        me->set_temp("die_reason", "���˶���ȥ���ڰ��޳���");
        me->die();
        destruct(this_object());
        return 1;
}

