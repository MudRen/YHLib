#include <ansi.h>

inherit __DIR__"tattoo";

void create()
{
        set_name(NOR + WHT "ڤ������ͼ" NOR, ({ "lianyu tu", "lianyu", "tu" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�Źžɵ�ͼƬ���������Щ������");
                set("unit", "��");
                set("value", 16500);
                set("material", "paper");
                set("tattoo_long", "����ڤ��վ���������׹Ƕ�֮�ϣ�����ԩ��Χ������");
                set("can_tattoo", ({ "�ؿ�", "��", }));
                set("tattoo_type", ({ "����", "��" }));
                set("tattoo_str", 2);
                set("tattoo_dex", 2);
                set("tattoo_special", "hatred");
                set("tattoo_spcname", "ɱ������");
        }
}
