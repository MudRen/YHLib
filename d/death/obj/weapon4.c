#include <ansi.h>
#include <weapon.h>

inherit CLUB;

void create()
{
        set_name(WHT "���������Ű" NOR, ({ "gui nue","club","gun", "xuantian gun" }));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 3000000);
                set("material", "steel");
                set("long", HIW "\n���������Ű�˾���������֮һ��\n" NOR);
                set("wield_msg", HIR "$N���ᶶ��$n" HIR "��ɲʱ����������һ��ɱ��ֱ��������\n" NOR);
        }
        init_club(200);
        setup();
}


