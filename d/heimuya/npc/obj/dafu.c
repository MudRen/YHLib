#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name(WHT "��ɽ��" NOR, ({"kaishan fu", "kaishan", "fu"}));
	set_weight(5000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", WHT "һ��ʮ�ַ����Ĵ󸫡�\n" NOR);
		set("value", 100);
		set("material", "iron");
		set("wield_msg", WHT "$N" WHT "���ִ������һ���󸫡�\n" NOR);
		set("unwield_msg", WHT "$N" WHT "������һ�𣬰Ѵ󸫲��ں����ϡ�\n" NOR);
	}
	init_hammer(60);
	setup();
}
