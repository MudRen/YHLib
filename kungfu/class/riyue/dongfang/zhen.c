
#include <ansi.h>
#include <weapon.h>

inherit PIN;

void create()
{
        set_name(HIY "����" NOR, ({ "zhen" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",HIY "����һ��ϸ�����롣\n" NOR);
                set("value", 300);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
                set("stable", 0);
        }

        init_pin(55);
        setup();
}
