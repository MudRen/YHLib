inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("ţƤ�ƴ�", ({"jiudai", "wineskin", "skin"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ�ƵĴ�ƴ������װ�ðˡ������ľơ�\n");
		set("unit", "��");
		set("value", 100);
		set("max_liquid", 15);
	}
	set("liquid", ([
		"type": "alcohol",
		"name": "Ů����",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
