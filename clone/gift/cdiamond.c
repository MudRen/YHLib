// cdiamond.c ��ʯ����

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIW "��ʯ����" NOR, ({ "chipped diamond" }) );
	set_weight(25);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIW "һ���������������������С"
                    "����ʯ������\n" NOR);
                set("value", 20000);
		set("unit", "��");
                set("armor_prop/per", 3);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
	}
        setup();
}

int query_autoload() { return 1; }
