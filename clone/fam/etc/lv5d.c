inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIM "�õ�����" NOR, ({"huandi shenzhu", "huandi", "shenzhu", "zhu"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
         	set("long", HIM "���溱���ı��飬������������ɫ��â��\n" NOR);
                set("unit", "��");
                set("value", 15000);
                set("can_be_enchased", 1);
                set("magic/type", "fire");
                set("magic/power", 35 + random(16));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

