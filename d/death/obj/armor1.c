#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name( HIY "�����Ӽ�" NOR, ({"jinhuan jia","jinhuan", "jia", "armor"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIC"һ������֯�͵ı��ף�\n"NOR);
                set("material", "steel");
                set("value", 400000);
                set("armor_prop/armor", 30);
                set("armor_prop/dodge", -5);
        }
        setup();
}
