#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(CYN "����׿�" NOR, ({ "xuanwu jiake", "jiake"}));
	set_weight(25000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", CYN "һ����������ļ׿ǣ��൱�ļ��͡�\n" NOR);
		set("unit", "��");
		set("value", 120000);
              set("item_origin", 1);
              set("material_attrib", "silk");
              set("material_name", CYN "����׿�" NOR);
              set("can_make", ({ "��" }));
              set("power_point", 100);
	}
}

