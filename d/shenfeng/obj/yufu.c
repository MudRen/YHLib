#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
    	set_name(HIW "��" NOR, ({ "yu fu", "yu", "fu" }));
    	set_weight(500);
    	if (clonep())
        	set_default_object(__FILE__);
    	else {
        	set("unit", "��");
        	set("long", HIW "һ���ð������ɵĸ�ͷ���൱�ľ�����\n" NOR);
        	set("value", 5000);
        	set("material", "jade");
      	}
    	init_hammer(10);
    	setup();
}

