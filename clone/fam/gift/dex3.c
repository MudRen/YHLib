#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name(NOR + HIR "�����޼��ɵ�" NOR, ({ "wuji xiandan", "wuji",
                                                  "xiandan", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR "��˵�˵������칬�е���Ʒ�����˳��˿���ƽ������\n" NOR);
                set("base_unit", "��");
                set("base_value", 100000);
                set("base_weight", 50);
                set("only_do_effect", 1);
                set("gift_type", "dex");
                set("gift_name", "������");
                set("gift_point", 85);
                set("gift_msg", HIW "ͻȻ��ֻ��ȫ����ƮƮ�ģ��й����Ƽ���ĸо���\n" NOR);
        }
        setup();
}

