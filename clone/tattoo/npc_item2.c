#include <weapon.h>
#include <ansi.h>

inherit PIN;

void create()
{
        set_name(HIY "����" NOR, ({ "jin zhen", "jin", "zhen", "pin" }));
        set_weight(24);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIY "���켫Ϊ��ϸ�Ľ��룬���Ÿ�����;��\n" NOR);
                set("value", 120);
                set("material", "silver");
                set("wield_msg", HIY "$N��һ��������һ��$n��\n" NOR);
                set("unwield_msg", HIY "$N������$n��\n" NOR);
        }

        init_pin(20);
        setup();
}
