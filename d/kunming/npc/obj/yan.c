inherit ITEM;

void create()
{
	set_name("ˮ��", ({"shui yan", "shui", "yan"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ��ˮ��˿��\n");
		set("unit", "��");
		set("value", 10);
    	}
}
