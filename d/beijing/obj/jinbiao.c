// jinbiao.c
#include <ansi.h>
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name(HIY"����"NOR, ({"jinbiao", "biao" }));
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
     		set("long", "����һ���ô������ɵķ��ڣ��۸񰺹��������⡣\n");
		set("unit", "Щ");
           	set("base_value", 200);
		set("material", "gold");
         	set("base_unit", "ö");
		set("base_weight", 50); 
	}	
       set_amount(1);
       init_throwing(80,100010);
       setup();
}