#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIM "ˮ����" NOR, ({"shuimi tao", "shuimi", "tao"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "һ��ˮ�����ʵ�ˮ���ң���������һ�����޿��ˡ�\n" NOR);
                set("unit", "��");
                set("value", 80);
                set("food_remaining", 4);
                set("food_supply", 30);
        }
}
