#include <ansi.h>

#include <weapon.h>

inherit CLUB;

void create()
{
        set_name(HIR"���컭�" NOR, ({ "fangtian huaji","huaji","ji" }));
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500000);
                set("material", "steel");
                set("long", "һ���������Ƶķ��컭ꪣ���˵�����������������ù���������\n");
                set("wield_msg", "$N����$n�������У��������ݡ�\n");
        }
        init_club(75);
        setup();
}


