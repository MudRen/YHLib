#include <ansi.h>

inherit __DIR__"tattoo";

void create()
{
        set_name(NOR + WHT "���ʥͼ" NOR, ({ "wanfo tu", "wanfo", "tu" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�Źžɵ�ͼƬ���������Щ������");
                set("unit", "��");
                set("value", 16500);
                set("material", "paper");
                set("tattoo_long", "����ɮ�˳��ݷ��棬���ɢ������ʥׯ��");
                set("can_tattoo", ({ "�ؿ�", "��", }));
                set("tattoo_type", ({ "����" }));
                set("tattoo_con", 4);
                set("tattoo_special", "health");
                set("tattoo_spcname", "����Ǭ��");
        }
}
