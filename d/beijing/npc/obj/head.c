#include <armor.h>

inherit HEAD;

void create()
{
        set_name("�ֿ�", ({ "gang kui", "gangkui", "kui", "helmet" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "steel");
                set("long", "һ����ʵ�ĸֿ���\n");
                set("value", 0);
                set("armor_prop/armor", 5);
        }
        setup();
}

