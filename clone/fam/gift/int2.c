#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name(HIG "�������" NOR, ({ "qinglong dan", "qinglong", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "����һ�Ŵ�����͸��ҩ�裬��˵���˿�����ǿ���ԡ�\n" NOR);
                set("base_unit", "��");
                set("base_value", 50000);
                set("base_weight", 50);
                set("only_do_effect", 1);
                set("gift_type", "int");
                set("gift_name", "��������");
                set("gift_point", 65);
                set("gift_msg", HIG "ͻȻ����ֻ����̨��һƬ��������̩�ޱȡ�\n" NOR);
        }
        setup();
}

