#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(RED "����" NOR, ({ "zhu yu", "yu", "yumao"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", RED "һ��������ȸ����ë����֪����ʲô�á�\n" NOR);
		set("unit", "��");
		set("value", 1000);
	}
}

