#include <ansi.h>
#include <weapon.h>

inherit CLUB;

void create()
{
        set_name(HIW "�������ǧ��" NOR, ({ "qian jun", "ruyi gun","club","gun" }));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 2400000);
                set("material", "steel");
                set("long", HIW "\n�������ǧ���˾���������֮һ��\n" NOR);
                set("wield_msg", HIR "$N���ᶶ��$n" HIR "��ɲʱ����������һ��ɱ��ֱ��������\n" NOR);
        }
        init_club(160);
        setup();
}


