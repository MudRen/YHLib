#include <ansi.h>
#include <music.h>

inherit ITEM;
inherit MI_QIN;

void create()
{
        set_name(NOR + RED "��β��" NOR, ({ "jiaowei qin", "jiaowei", "qin" }));
        set_weight(600);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "̨");
                set("long", RED "�ഫ����ǵ�����ļ��ӻ������ȳ��Ľ�ľ"
                            "���ɵ����٣��ٵ�\nβ���Կɼ�����ɫ��\n" NOR);
                set("value", 10000);
                set("material", "wood");
        }
        setup();
}

void init()
{
        add_action("play_qin", "play");
}
