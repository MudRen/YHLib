// By rcwiz

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
    set_name(HIR "��ɫ����" NOR, ({"pao", "cloth", "chang pao"}) );
    set_weight(1500);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	set("female_only", 1);
        set("unit", "��");
		set("long", "���Ǽ��ʵ�����ĺ�ɫ���ۣ����ϻ����Ż��ء�\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}
