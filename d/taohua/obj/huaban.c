#include <weapon.h>
#include <ansi.h>
 
inherit THROWING;

void create()
{
        set_name(HIM "�һ���" NOR, ({ "flower leaf", "hua ban", "ban" }) );
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "���ʵ��һ����꣬���滹���⾧Ө��¶�顣\n" NOR);
                set("unit", "��");
                set("value", 0);
                set("base_unit", "Ƭ");
                set("base_weight", 1);
                set("base_value", 0);
                set("material", "wood");
                set("damage", 2);
        }
        set_amount(50);
        init_throwing(2);
        setup();
}
