inherit ITEM;
inherit F_FOOD;

#include <ansi.h>

void create()
{
        set_name(RED "�Ǵ��Ｙ" NOR, ({ "tangcu liji", "tangcu", "liji" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���������ڵ��Ǵ��Ｙ��\n");
                set("unit", "��");
                set("value", 160);
                set("food_remaining", 8);
                set("food_supply", 30);
                set("material", "meet");
        }
        setup();
}

