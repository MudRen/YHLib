#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW "С������" NOR, ({ "laxiang teddy", "laxiang","teddy" }));
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long",
                 "���ǹ�Ĺ�ɵ��Ĵ����ˡ��˼�����������������С��(teddy)������\n"
                 "���Դ������Ͽ�����Ӣ������������������������棬��Ŀ���ʣ�ò���˰���\n");
		set("value", 1);
		set("material", "wood");
set("no_get",1);
set("amount",30);
}
setup();
}
