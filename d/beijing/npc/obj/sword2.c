#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name( HIW "�ֽ�" NOR,  ({ "gang jian", "sword", "jian" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�������ĳ�����\n");
                set("value", 3000);
                set("material", "gold");
        }
        init_sword(20);
        setup();
}

