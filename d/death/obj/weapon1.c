#include <ansi.h>

#include <weapon.h>

inherit CLUB;

void create()
{
        set_name(HIY"����������"NOR, ({ "panlong gun","gun", "panlong" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 250000);
                set("material", "steel");
                set("long", "һ���������������ĳ�����\n");
        }
        init_club(50);
        setup();
}

