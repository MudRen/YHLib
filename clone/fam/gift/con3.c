#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name(NOR + YEL "ϴ�������ɵ�" NOR, ({ "xisui xiandan", "xisui",
                                                  "xiandan", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", YEL "��˵�˵������칬�е���Ʒ�����˳��˿���ƽ�����ǡ�\n" NOR);
                set("base_unit", "��");
                set("base_value", 100000);
                set("base_weight", 50);
                set("only_do_effect", 1);
                set("gift_type", "con");
                set("gift_name", "�������");
                set("gift_point", 85);
                set("gift_msg", HIM "ͻȻ��������������ͣ�����漴��ƽ����������\n" NOR);
        }
        setup();
}
