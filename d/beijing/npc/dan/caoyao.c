// caoyao.c

#include <ansi.h>

inherit ITEM;

void create() 
{
        set_name(HIG "��֪����ҩ" NOR, ({"cao yao", "yao", "cao"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������������еĲ�֪���Ĳ�ҩ��һ���˶������ϳ��Ӳݡ�\n");
        }
        setup();
}
