#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(HIW "����Ƥ" NOR, ({ "yinlang pi", "yinlang", "pi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "���ǵ�Ƥë����ë�߼ѣ���Ϊ�������ǳ�"
                            "֮����\n" NOR);
                set("base_unit", "��");
                set("base_value", 12000);
                set("base_weight", 300);
        }
        setup();
        set_amount(1);
}
