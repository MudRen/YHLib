#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(NOR + MAG "��ȹ" NOR, ({ "chang qun", "qun", }) );
        set("long",NOR + MAG "����һ����ʽ��ӱ�����������ĳ�ȹ��\n");
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 600);
        }
        setup();
}

