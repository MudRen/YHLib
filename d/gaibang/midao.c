#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("ؤ���ܵ�", ({ "midao" }));
        set_weight(200000);
        set_max_encumbrance(1000000);
        if (clonep())
        {
                set_default_object(__FILE__);
                call_out("destruct_me", 10);
        } else
        {
                set("value", 1);
                set("long", "����ؤ�Ｋ�����ܵĵ���ͨ��������ؤ�Ｘ������Ѫ��ɡ�\n");
                set("unit", "��");
                set("no_get", "��֪������ɶô������Ҳ�뿹������\n");
        }
        setup();
}

void destruct_me()
{
        destruct(this_object());
}
