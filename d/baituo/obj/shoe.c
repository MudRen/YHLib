#include <ansi.h> 
#include <armor.h>
inherit ITEM;

void create()
{
        set_name(HIM "�廨Ь" NOR, ({ "xiuhua xie", "xiuhua", "xie", "shoe" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", HIM "����һֻƯ�����廨Ь��\n" NOR);
                set("value", 50);
                set("material", "cloth");
                set("female_only", 1);
                set("armor_prop/armor", 3);
        }
}
