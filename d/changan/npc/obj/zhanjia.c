//zhanjia.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("ս��", ({"zhan armor","zhanjia","jia","armor"}));
      	set_weight(40000);
      	if (clonep())
      		set_default_object(__FILE__);
      	else 
	{
      		set("unit", "��");
      		set("long", "һ��������͵�ս�ס�\n");
      		set("value", 3000);
      		set("material", "steel");
      		set("armor_prop/armor", 40);
      		set("armor_prop/dodge", -10);
	}

        setup();
}
