#include <ansi.h> 
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(NOR + YEL "���" NOR, ({ "yu chang", "yu", "chang" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", NOR + YEL "����һ����ͺӥ����֯�͵Ĵ�멡�\n" NOR);
                set("material", "cloth");
                set("armor_prop/armor", 15);
        }
        setup();
}

