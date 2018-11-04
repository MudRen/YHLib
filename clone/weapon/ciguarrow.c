// arrow.c
 
#include <weapon.h>
#include <ansi.h>

inherit THROWING;

int is_arrow() { return 1; }
 
void create()
{
	set_name(HIR "�̹Ǽ�" NOR, ({ "arrow", "jian" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIR "һ��ϸ��������������൱�����Ƶ�ʮ�����͡�\n" NOR);
		set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 150);
                set("base_value", 500);
                set("wound_percent", 90);
        }

        set_amount(1);
        init_throwing(400);
        setup();

        set("no_wield", "�ⲻ������װ���ġ�\n");
}
