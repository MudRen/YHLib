#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(HIR "�����ز�ն" NOR, ({ "dizang zhan", "dizang", "zhan", "blade", "dao" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 4500000);
                set("material", "steel");
                set("long", HIW "\n�����ز�ն�˾���������֮һ��\n" NOR);
                set("wield_msg", HIR "$N���ᶶ��$n" HIR "��ɲʱ����������һ��ɱ��ֱ��������\n" );
        }
        init_blade(230);
        setup();
}
