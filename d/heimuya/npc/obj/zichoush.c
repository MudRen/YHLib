#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(MAG "�ϳ���" NOR, ({ "zichou shan", "zichou", "shan", "cloth" }) );
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("value", 400);
                set("armor_prop/armor", 10);
        }
        setup();
}

