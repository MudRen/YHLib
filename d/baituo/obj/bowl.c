inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("���ڴ���", ({ "da wan", "wan", "bowl" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "����һֻ��ʢˮ�Ĵִɴ��롣\n");
                set("value", 0);
                set("max_liquid", 6);
        }

        set("liquid", ([
                "type" : "water",
                "name" : "��ˮ",
                "remaining"   : 10,
                "drunk_apply" : 10,
        ]));
}
