#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
    	set_name(HIW "��" NOR, ({ "yu dao", "yu", "dao", "blade" }));
    	set_weight(500);
    	if (clonep())
        	set_default_object(__FILE__);
    	else {
        	set("unit", "��");
        	set("long", HIW "һ���ð������ɵĵ������൱�ľ�����\n" NOR);
        	set("value", 5000);
        	set("material", "jade");
      	}
    	init_blade(10);
    	setup();
}

