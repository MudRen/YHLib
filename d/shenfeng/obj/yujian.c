#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    	set_name(HIW "��" NOR, ({ "yu jian", "yu", "jian", "sword" }));
    	set_weight(500);
    	if (clonep())
        	set_default_object(__FILE__);
    	else {
        	set("unit", "��");
        	set("long", HIW "һ���ð������ɵĳ������൱�ľ�����\n" NOR);
        	set("value", 5000);
        	set("material", "jade");
      	}
    	init_sword(10);
    	setup();
}

