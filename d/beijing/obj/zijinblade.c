// zijinblade.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name( MAG "�Ͻ���Ե�" NOR , ({ "zijin bagua blade", "zijin blade", "bagua blade", "blade" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIY "����һ�ѽ�����������͸վ��ı��������������������Ϲ⡣\n" NOR );
		set("value", 2000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	}
	init_blade(80,110);
	setup();
}