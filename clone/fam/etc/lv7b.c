inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(YEL "Ϣ��" NOR, ({"xi rang", "xi", "rang"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", YEL "��˵�Ϲ�ʱ�ڴ�����ˮ��ʹ�õ�����������\n" NOR);
                set("unit", "��");
                set("value", 50000);
        }
        setup();
}

int query_autoload()
{
        return 1;
}

