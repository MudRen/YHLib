#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name(RED "�����" NOR, ({ "qilin bian", "qilin", "bian", "whip" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 650000);
                set("material", "steel");
        }
        init_whip(70);
        setup();
}
