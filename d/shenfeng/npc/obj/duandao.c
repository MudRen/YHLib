#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("�������䵶", ({ "hasake wandao", "hasake", "wandao", "dao", "blade" }));
        set_weight(4000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����λεĹ����˶̵�, �ǹ������˵ķ���������\n");
                set("value", 500);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ��������γ�һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        init_blade(15);
        setup();
}
