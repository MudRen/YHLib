inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIW "��֮��������" NOR, ({"shenzhi hanjing", "shenzhi", "hanjing"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "�������������ܣ����˲��ҽӽ�������缫��֮ʥ�ӵ���������������\n" NOR);
                set("unit", "��");
                set("value", 12000);
                set("can_be_enchased", 1);
                set("magic/type", "cold");
                set("magic/power", 90 + random(11));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

