#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
        set_name(HIC "�����" NOR, ({ "yufeng zhen", "yufeng", "zhen" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIC "����һ��ϸ�������룬ɢ���ŵ��������㡣\n" NOR);
                set("unit", "Щ");
                set("base_unit", "��");
                set("base_weight", 500);
                set("base_value", 0);
                set("material", "iron");
        }

        set_temp("daub/poison", ([
                "id"     : "xiao longnv",
                "remain" : 1000,
                "level"  : 80,
                "name"   : "��䶾",
        ]));
        set_temp("daub/poison_type", "yufengdu");
        set_temp("daub/who_name", "С��Ů");
        set_temp("daub/who_id", "xiao longnv");

        set_amount(50);
        init_throwing(50);
        setup();
}
