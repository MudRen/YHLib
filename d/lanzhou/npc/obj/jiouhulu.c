inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("�ƺ�«", ({"jiouhulu", "hulu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���ú�«�Ƴɵľƺ���\n");
		set("unit", "��");
		set("value", 200);
		set("max_liquid", 20);
	}
	set("liquid", ([
		"type": "water",
		"name": "�������--Ů����",
		"remaining": 10,
		"drunk_supply": 20,
	]));
}
