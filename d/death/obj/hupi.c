#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "�׻�Ƥ" NOR, ({ "baihu pi", "pi"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW "һ�Ŵ����ް׻����ϰ��µ�Ƥ��ѩ����Ͼ���ޱȵļ��͡�\n" NOR);
		set("unit", "��");
		set("value", 1000000);
              set("item_origin", 1);
              set("material_attrib", "silk");
              set("material_name", HIW "�׻�ëƤ" NOR);
              set("can_make", ({ "��" }));
              set("power_point", 120);
	}
}

