#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(NOR + WHT "�Ʋ���" NOR, ({ "cloth" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "����һ������������Ʋ��¡�\n" NOR);
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

