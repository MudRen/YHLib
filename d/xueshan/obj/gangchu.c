#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("����", ({ "gang chu", "gang", "chu" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ȫ������ĸ��ơ�\n");
		set("value", 3000);
		set("material", "steel");
		set("wield_msg", "$N��������һ�����һ��$n�߾������С�\n");
		set("unwield_msg","$N�����е�$n���ر��ϡ�\n");
                set("stable", 40);
	}
	init_hammer(50);
	setup();
}
