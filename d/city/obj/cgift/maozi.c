// nixie.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name( HIR "ʥ��" HIW "ñ" NOR, ({ "mao zi", "mao",  "zi" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ʥ��ñ�ӣ������Ž��յ����ա�\n");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/dodge", 5);
	}
	setup();
}
