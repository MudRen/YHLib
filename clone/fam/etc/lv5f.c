inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIW "��������" NOR, ({"jibei hanyu", "jibei", "hanyu", "yu"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "�������꺮��������ɣ�ɢ����ѩһ��Ĺ���\n" NOR);
                set("unit", "��");
                set("value", 15000);
        }
        
        setup();
        move("/d/lingxiao/yudong");
}

int query_autoload()
{
        return 1;
}

