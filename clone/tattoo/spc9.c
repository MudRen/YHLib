#include <ansi.h>

inherit __DIR__"tattoo";

void create()
{
        set_name(NOR + WHT "��������ͼ" NOR, ({ "tianzun tu", "tianzun", "tu" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�Źžɵ�ͼƬ���������Щ������");
                set("unit", "��");
                set("value", 16500);
                set("material", "paper");
                set("tattoo_long", "�����������ڰ˱������ϣ�������ϼ���ƣ��ƻ�����");
                set("can_tattoo", ({ "�ؿ�", "��", }));
                set("tattoo_type", ({ "����", "����" }));
                set("tattoo_int", 2);
                set("tattoo_con", 2);
                set("tattoo_special", "divine");
                set("tattoo_spcname", "�ƾ�����");
        }
}
