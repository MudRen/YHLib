#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(WHT "�����" NOR, ({ "cangqiong jian", "cangqiong", "jian", "sword" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 3800000);
                set("material", "steel");
                set("long", HIW "\n������˾���������֮һ��\n" NOR);
                set("wield_msg", HIR "$N���ᶶ��$n" HIR "��ɲʱ����������һ��ɱ��ֱ��������\n" );
        }
        init_sword(210);
        setup();
}
