#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(NOR + WHT "��Ƥ��Ƭ" NOR, ({ "sui pian8", "suipian8", "pian8" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "����һ����Ƥ��Ƭ��������в�ȱ��ȫ"
                            "�ĺ�������������\n" NOR);
                set("unit", "��");
                set("value", 10);
                set("material", "paper");
        }
}

int query_autoload()
{
        return 1;
}

