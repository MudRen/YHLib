// bufa.c
inherit ITEM;

void create()
{
	set_name( "�̽����ױ�����",({ "sjm letter","letter" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","�����̽������ױ����ţ����顸��ʦ��ά����������\n");
		set("value", 100);
                set("no_sell", 1);
		set("material", "paper");

	}
}
