#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name(CYN "ڤ��������" NOR, ({ "mingwang chui","mingwang","chui", "hammer" }));
        set_weight(28000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 3800000);
                set("material", "steel");
                set("long", HIW "\nڤ���������˾���������֮һ��\n" NOR);
                set("wield_msg", HIR "$N���ᶶ��$n" HIR "��ɲʱ����������һ��ɱ��ֱ��������\n" NOR);
        }
        init_hammer(210);
        setup();
}


