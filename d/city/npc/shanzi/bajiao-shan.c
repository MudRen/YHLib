#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
        set_name(HIG "�Ž���" NOR, ({ "bajiao shan", "bajiao", "shan" }));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIG "�Ž������ȣ�����󣬼۸������\n" NOR);
                set("value", 1000);
                set("material", "wood");
                set("wield_msg", "$N����һ��$n�������\n");
                set("unwield_msg", "$N����$n���ջػ��\n");
        }
        init_dagger(15);
        setup();
}

