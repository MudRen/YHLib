#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("��", ({ "chai dao", "chai", "blade", "dao" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ͨ�Ĳ񵶣������������������⡣\n");
                set("value", 80);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
        }
        init_blade(15);
        setup();
}

