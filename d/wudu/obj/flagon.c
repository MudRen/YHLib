// flagon.c  �ƺ�

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("�ƺ�", ({"jiu hu", "hu", "flagon"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ������װ�վƵĴ�ƺ���\n");
                set("unit", "��");
                set("value", 100);
                set("max_liquid", 15);
        }

        set("liquid", ([
                "type": "alcohol",
                "name": "�վ�",
                "remaining": 15,
                "drunk_apply": 3,
                "slumber_effect": 100,
        ]));
}
