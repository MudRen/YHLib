#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIW "������" NOR, ({ "silver armor", "silver", "armor", "jia" }));
	set_weight(80000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIW "һ��ȫ���Ƶ������ף�����ԭ���Ѽ�����\n" NOR);
		set("value", 20000);
		set("material", "boots");
                set("armor_prop/armor", 200);
		set("armor_prop/dodge", -80);
	}
	setup();
}
