// newbie.c

#include <ansi.h>
#include <command.h>

inherit ITEM;

void create()
{
        set_name(HIY "��ת��" NOR, ({ "jiuzhuan jindan", "dan" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIY "һ�Ž�ɫ���ɵ�����˵��̫���Ͼ�"
                            "�����������鵤��ҩ��\n" NOR);
                set("unit", "��");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
	return HELP_CMD->main(this_player(), "feature");
}

