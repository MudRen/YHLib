#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name(HIY "����˿������" NOR, ({ "shi yue", "shenjiaosi", "suo", "whip" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 3200000);
                set("material", "steel");
                set("long", HIW "\n����˿�������˾���������֮һ��\n" NOR);
                set("wield_msg", HIR "$N���ᶶ��$n" HIR "��ɲʱ����������һ��ɱ��ֱ��������\n" );
        }
        init_whip(180);
        setup();
}
