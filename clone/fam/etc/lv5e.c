inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIG "ͨ���" NOR, ({"tongtian cao", "tongtian", "cao"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "һ�������ڼ���ɽ���ϵ�ͨ��Ө�̵�С�ݡ�\n" NOR);
                set("unit", "��");
                set("value", 15000);
        }
        setup();
}

int query_autoload()
{
        return 1;
}

