#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "����ħ����" NOR, ({ "laxiang bingo", "laxiang","bingo" }));
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long",
	         "�����䵱�ɵ��Ĵ����ˡ���ȱ����-��˫��������ħ(bingo)������\n"
	         "��Ȼ�����˳���... �е�Բ�ס���ˣ�����������������ǿ��Եġ�\n");
		set("value", 1);
		set("material", "wood");
set("no_get",1);
set("amount",30);
}
setup();
}
