// qhcwan.c  �໨����

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("ȱ�ڵ��໨����", ({"qinghua ciwan", "wan", "ciwan"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��ȱ�˿ڵĴִ��롣\n");
                set("unit", "��");
                set("value", 100);
                set("max_liquid", 15);
        }
        set("liquid", ([
                "type": "alcohol",
                "name": "��ˮ",
                "remaining": 15,
                "drunk_apply": 3,
        ]));
}
