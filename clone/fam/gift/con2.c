#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name(NOR + WHT "�������ǵ�" NOR, ({ "xuanwu dan", "xuanwu", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "����һ�ż�Ӳ�ޱȺ�ɫ��ҩ����˵���˿�����ǿ���ǡ�\n" NOR);
                set("base_unit", "��");
                set("base_value", 50000);
                set("base_weight", 50);
                set("only_do_effect", 1);
                set("gift_type", "con");
                set("gift_name", "�������");
                set("gift_point", 65);
                set("gift_msg", HIM "ͻȻ�������������ͣ�����漴��ƽ����������\n" NOR);
        }
        setup();
}

