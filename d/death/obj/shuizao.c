#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(GRN "ˮ��" NOR, ({ "shui zao", "shui", "zao"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "һ�������ڱ�ˮ��̶����ͺ�ˮ�塣\n" NOR);
                set("unit", "��");
                set("value", 0);
                set("no_get", "�����Ű���һ�£����������ٹ̣����Ȼû�ζ���\n");
        }
}
