#include <ansi.h>
inherit ITEM;

#define QIPU    "/clone/item/xiaoao/ouxuepu"

void create()
{
        object ob;
        set_name(WHT "���õ����" NOR, ({ "shelf"}) );
        set_weight(5000000);
        set_max_encumbrance(800000);
        if (clonep())
        {
                set_default_object(__FILE__);
                ob = find_object(QIPU);
                if (! ob) ob = load_object(QIPU);
                if (! environment(ob))
                ob->move(this_object());
        } else
        {
                set("prep", "in");
                set("unit", "ֻ");
                set("long", WHT "һֻ���õ���ܣ����಻����Ҳ��֪�����������ˡ�\n" NOR);
                set("value", 1);
        }
}

int is_container()
{
        return 1;
}

