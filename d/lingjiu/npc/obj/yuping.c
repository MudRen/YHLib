#include <ansi.h>

inherit ITEM;

void create()
{
        object ob;
        set_name(HIW "��ƿ" NOR, ({ "yu ping" , "yu", "ping" }) );
        set_weight(150);
        set_max_encumbrance(100);
        if (clonep())
        {
                set_default_object(__FILE__);

                ob = new(__DIR__"jieyao");
                ob->move(this_object());

                ob = new(__DIR__"jieyao");
                ob->move(this_object());

                ob = new(__DIR__"jieyao");
                ob->move(this_object());
        } else
        {
                set("unit", "֧");
                set("prep", "in");
                set("long", HIW "һ֧������Ƶ���ƿ��ƿ�ϵ�ľ������Ϊ�žɡ�\n" NOR);
                set("value", 3000);
        }
}
