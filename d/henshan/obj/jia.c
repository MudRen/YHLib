#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR "���޼�" NOR, ({ "bushou jia","jia", "bushou" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����ר��������׽�������޵ģ��гݷ����ޱȡ� \n");
		set("value", 1000);
		set("material", "iron");
	}

	setup();
}

