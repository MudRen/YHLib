#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name(HIY "�����Ԫ�ɵ�" NOR, ({ "zhuyuan xiandan", "zhuyuan",
                                            "xiandan", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "��˵�˵������칬�е���Ʒ�����˳��˿���ƽ��������\n" NOR);
                set("base_unit", "��");
                set("base_value", 100000);
                set("base_weight", 50);
                set("only_do_effect", 1);
                set("gift_type", "str");
                set("gift_name", "��������");
                set("gift_point", 85);
                set("gift_msg", HIY "ͻȻ����ֻ��˫�ۼ������ѣ�������������\n" NOR);
        }
        setup();
}

