#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name(WHT "����" NOR, ({"leizhen dang", "leizhen", "dang"}));
	set_weight(8000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", WHT "һ��ʮ�ֳ��ص����𵲡�\n" NOR);
		set("value", 10000);
                set("material", "iron");
		set("wield_msg", WHT "$N" WHT "���ִ������һ�����𵲡�\n" NOR);
		set("unwield_msg", WHT "$N" WHT "������һ�ۣ������𵲷������\n" NOR);
	}
	init_hammer(60);
	setup();
}
