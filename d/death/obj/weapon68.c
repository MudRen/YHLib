#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(MAG "��������" NOR, ({ "longhuang jian", "longhuang", "jian", "sword" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 3100000);
                set("material", "steel");
                set("long", HIW "\n���������˾���������֮һ��\n" NOR);
                set("wield_msg", HIR "$N���ᶶ��$n" HIR "��ɲʱ����������һ��ɱ��ֱ��������\n" );
        }
        init_sword(160);
        setup();
}
