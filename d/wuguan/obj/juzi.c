#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name(YEL "����" NOR, ({ "ju zi", "ju", "zi" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", YEL "����һ������ľͷ�ľ��ӣ���ͨ���յ��ճ���Ʒ��\n" NOR);
                set("value", 30);
                set("material", "steel");
        	set("wield_msg", YEL "$N" YEL "�ó�һ�Ѿ����������С�\n" NOR);
                set("unwield_msg", YEL "$N" YEL "�����еľ��ӿ��ڼ��ϡ�\n" NOR);
        }
        init_blade(4);
        setup();
}
