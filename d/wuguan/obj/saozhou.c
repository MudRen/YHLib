#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name(HIY "ɨ��" NOR, ({ "sao zhou", "sao", "zhou" }));
        set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", HIY "����һ��ɨ�㣬��ͨ���յ��ճ���Ʒ��\n" NOR);
                set("value", 10);
		set("material", "steel");
		set("wield_msg", HIY "$N" HIY "�ó�һ��ɨ���������С�\n" NOR);
                set("unwield_msg", HIY "$N" HIY "�����е�ɨ�㿹�ڼ��ϡ�\n" NOR);
	}
        init_hammer(4);
	setup();
}
