#include <ansi.h>

inherit __DIR__"tattoo";

void create()
{
        set_name(NOR + WHT "�丸ͼ��" NOR, ({ "kuafu tu", "kuafu", "tu" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�Źžɵ�ͼƬ���������Щ������");
                set("unit", "��");
                set("value", 9000);
                set("material", "paper");
                set("tattoo_long", "�丸׷�յ�����");
                set("can_tattoo", ({ "�ؿ�", "��", "���", "�ұ�" }));
                set("tattoo_type", ({ "����", "��" }));
                set("tattoo_con", 1);
                set("tattoo_dex", 2);
        }
}
