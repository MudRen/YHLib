#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
        set_name( WHT "�̹���" NOR,  ({ "pangu kai", "kai", "armor" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ������������ף���������̹ŵ�ͷ��\n");
                set("value", 100000);
                set("material", "cloth");
                set("armor_prop/armor", 200);
        }
        setup();
}

