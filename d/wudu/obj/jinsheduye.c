#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL "���߶�Һ" NOR, ({"jinshe duye", "jinshe", "duye"}));
        set("unit", "ƿ");
        set("long", YEL "����һƿ�綾�Ľ��߶�Һ��\n" NOR);
        set("value", 100);
        set_weight(100);
        set("only_do_effect", 1);
        setup();
}

int do_effect(object me)
{
        message_vision("$Nһ�������ѽ��߶�Һ���������С�\n", me);
        me->set_temp("die_reason", "���˽��߶�Һȥ���ڰ��޳���");
        me->die();
        destruct(this_object());
        return 1;
}

