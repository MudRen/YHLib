#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIY "�׻��Ʒ�" NOR, ({ "zhi fu", "zhi", "fu" }) );
        set("long",HIY "һ�������������Ʒ���ֻ�������������������ӡ�ż�\n"
                   "���֣����׻�Ӣ��ʷ����\n");
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

