#include <ansi.h>;
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(HIY "����" NOR, ({ "tea" }));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "һ���豭������ʢ������Ũ���Ļ��衣\n" NOR);
                set("unit", "��");
                set("value", 0);
                set("max_liquid", 5);
        }
        set("liquid", ([
                "type": "water",
                "name": "����",
                "remaining": 5,
                "drunk_apply": 5,
        ]));
}
