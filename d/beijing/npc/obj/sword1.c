#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name( "����",  ({ "chang jian", "sword", "jian" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ͨ�ĳ�����\n");
                set("value", 1000);
                set("material", "gold");
        }
        init_sword(10);
        setup();
}

