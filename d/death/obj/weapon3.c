#include <ansi.h>
#include <weapon.h>

inherit CLUB;

void create()
{
        set_name(HIR"������" NOR, ({ "tianlei shendang","tianlei","shendang", "dang" }));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1200000);
                set("material", "steel");
                set("long", "һ���Ϲ���ľ������Ĺ��ӣ��˲���֮�����\n");
                set("wield_msg", "$N����$n�������У��������ݡ�\n");
        }
        init_club(120);
        setup();
}


