#include <ansi.h>

inherit __DIR__"tattoo";

void create()
{
        set_name(NOR + WHT "��β��ͼ��" NOR, ({ "yanweidie tu", "yanweidie", "tu" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�Źžɵ�ͼƬ���������Щ������");
                set("unit", "��");
                set("value", 1500);
                set("material", "paper");
                set("tattoo_long", "һֻ��β��");
                set("can_tattoo", ({ "����" }));
                set("tattoo_type", ({ "��ò" }));
                set("tattoo_per", 3);
        }
}
