#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name( "�ٸ��ý�",  ({ "chang jian", "sword", "jian" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���ٸ��������õĳ�����\n");
                set("value", 2000);
                set("material", "gold");
        }
        init_sword(15);
        setup();
}

