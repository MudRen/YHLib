// hulu.c 

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("��«", ({"hulu", "hu"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���ú�«�Ƴɵ�ˮ����\n");
                set("unit", "��");
                set("value", 100);
                set("max_liquid", 10);
        }
        set("liquid", ([
                "type": "water",
                "name": "��ˮ",
                "remaining": 10,
                "drunk_supply": 10,
        ]));
}
