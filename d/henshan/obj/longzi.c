#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY "����" NOR, ({ "long zi","long", "zi" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "������Ӳ�̫�󣬿���ֻ��װ(zhuang)�½�С�Ķ�� \n");
		set("value", 100);
		set("material", "iron");
	}

	setup();
}

