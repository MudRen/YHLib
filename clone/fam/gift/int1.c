#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name(NOR + HIY "���۵�" NOR, ({ "zenghui dan", "zenghui", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "����һ��ͨ���Ƶ�ҩ�裬��˵���˿�����ǿ���ԡ�\n" NOR);
                set("base_unit", "��");
                set("base_value", 10000);
                set("base_weight", 50);
                set("only_do_effect", 1);
                set("gift_type", "int");
                set("gift_name", "��������");
                set("gift_point", 40);
                set("gift_msg", HIG "ͻȻ����ֻ����̨��һƬ��������̩�ޱȡ�\n" NOR);
        }
        setup();
}

