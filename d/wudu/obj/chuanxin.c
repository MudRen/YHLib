#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC "������" NOR, ({"chuanxin lian", "chuanxin", "lian"}));
        set("unit", "��");
        set("long", HIC "����һ�����ɫ�����������綾��\n" NOR);
        set("value", 10);
        set_weight(100);
        set("only_do_effect", 1);
        setup();
}

int do_effect(object me)
{
        message_vision("$Nһ�����������������������С�\n", me);
        me->set_temp("die_reason", "���˴�����ȥ���ڰ��޳���");
        me->die();
        destruct(this_object());
        return 1;
}

