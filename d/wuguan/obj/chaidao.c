#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name(YEL "��" NOR, ({ "chai dao", "chai", "dao" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", YEL "����һ�������Ŀ��񵶣���ͨ���յ��ճ���Ʒ��\n" NOR);
                set("value", 10);
                set("material", "steel");
                set("wield_msg", YEL "$N" YEL "��ৡ���һ�����һ�����������С�\n" NOR);
                set("unwield_msg", YEL "$N" YEL "�����еĲ񵶲�����䡣\n" NOR);
        }
        init_blade(4);
        setup();
}
