#include <weapon.h>
#include <ansi.h>
#include <armor.h> 
inherit HANDS; 

void create()
{
        set_name(RED "��Ѫ����" NOR, ({ "canxue shoutao" , "shoutao" , "canxue", "hand", "tao" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("long", RED "��˵�е��Ϲ�������\n" NOR);
                set("value", 100000);
                set("rigidity", 8000);
                set("material", "steel");
                set("armor_prop/armor", 100); 
        }
        setup();
}

