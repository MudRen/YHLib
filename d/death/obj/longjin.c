#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "����" NOR, ({ "long jin", "jin"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW "һ����������������ȡ���Ľ�൱�ļ��͡���Ө��͸����Ȼ�����׹⡣\n" NOR);
		set("unit", "��");
		set("value", 200000);
              set("item_origin", 1);
              set("material_attrib", "silk");
              set("material_name", HIW "����" NOR);
              set("can_make", ({ "��" }));
              set("power_point", 120);
	}
}

