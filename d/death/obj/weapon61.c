#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(CYN "��ԯ��" NOR, ({ "xuanyuan jian", "xuanyuan", "jian", "sword" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 4000000);
                set("material", "steel");
                set("long", HIW "\n��ԯ���˾���������֮һ��\n" NOR);
                set("wield_msg", HIR "$N���ᶶ��$n" HIR "��ɲʱ����������һ��ɱ��ֱ��������\n" );
        }
        init_sword(220);
        setup();
}
