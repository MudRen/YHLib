#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
        set_name(HIW "��������" NOR, ({ "bingpo zhen", "bingpo", "zhen" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "����һ��ϸ�������룬���͸����������\n" NOR);
                set("unit", "Щ");
                set("base_unit", "��");
                set("base_weight", 500);
                set("base_value", 0);
                set("material", "iron");
        }

        set_temp("daub/poison", ([
                "id"     : "xiao longnv",
                "remain" : 1200,
                "level"  : 100,
                "name"   : "������",
        ]));
        set_temp("daub/poison_type", "hanbingdu");
        set_temp("daub/who_name", "��Ī��");
        set_temp("daub/who_id", "li mochou");

        set_amount(50);
        init_throwing(80);
        setup();
}
