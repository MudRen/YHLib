inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIW "���Ǳ���" NOR, ({"bipo bingjing", "bipo", "bingjing"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "��Ө��͸�ĺ����������̹ǣ�����缫Ʒ��\n" NOR);
                set("unit", "��");
                set("value", 12000);
                set("can_be_enchased", 1);
                set("magic/type", "cold");
                set("magic/power", 55 + random(16));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

