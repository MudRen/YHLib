#include <weapon.h>
inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIR "�嶾���" NOR, ({ "wudu shenjian", "jian", "shenjian" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ű���������һֻ�������\n");
                set("value", 10000);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ���ͳ�һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�������䡣\n");
        }
        init_sword(70);
        setup();
}
