
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("ľ��", ({ "mu zhang" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ͷľ�ȡ�\n");
                set("value", 200);
                set("material", "wood");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�����ڵ��ϡ�\n");
        }
        init_staff(60);
        setup();
}
