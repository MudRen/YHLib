#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(HIY "��Ƥ" NOR, ({ "bao pi", "bao", "pi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "�����۱���Ƥ�����ʼ��ͣ�Ƥë"
                            "����⻬֮����\n" NOR);
                set("base_unit", "��");
                set("base_value", 8000);
                set("base_weight", 450);
        }
        setup();
        set_amount(1);
}
