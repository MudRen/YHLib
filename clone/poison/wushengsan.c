#include <ansi.h>
inherit ITEM;

void create()
{
        set_weight(100);
        set_name(HIW "��ʥɢ" NOR, ({"wusheng san", "wusheng", "san"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIW "������嶾�̵Ķ�����ҩ��ʥɢ�������������ء�\n" NOR);
                set("value", 50);
		set("poison_type", "poison");
                set("can_pour", 1);
                set("can_daub", 1);
                set("can_drug", 1);
                set("poison", ([
                        "level" : 250,
                        "id"    : "he tieshou",
                        "name"  : "��ʥɢ�綾",
                        "duration": 20,
                ]));
                set("no_sell", 1);
		set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{
        message_vision("$Nһ����������ʥɢ���������С�\n", me);
        me->set_temp("die_reason", "������ʥɢȥ���ڰ��޳���");
        me->die();
        destruct(this_object());
        return 1;
}