#include <ansi.h>

inherit __DIR__"tattoo";

void create()
{
        set_name(NOR + WHT "��������ͼ" NOR, ({ "wenlong tu", "wenlong", "tu" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�Źžɵ�ͼƬ���������Щ������");
                set("unit", "��");
                set("value", 16500);
                set("material", "paper");
                set("tattoo_long", "�����������໥���Ʋ�������������");
                set("can_tattoo", ({ "�ؿ�", "��", }));
                set("tattoo_type", ({ "����" }));
                set("tattoo_str", 4);
                set("tattoo_special", "power");
                set("tattoo_spcname", "������");
        }
}
