#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(HIG "�̺�����" NOR, ({ "bihai canjue", "bihai", "blade", "dao" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1700000);
                set("material", "steel");
                set("long", HIW "\n�̺������˾���������֮һ��\n" NOR);
                set("wield_msg", HIR "$N���ᶶ��$n" HIR "��ɲʱ����������һ��ɱ��ֱ��������\n" );
        }
        init_blade(140);
        setup();
}
