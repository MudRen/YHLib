#include <weapon.h>
#include <ansi.h>
 
inherit THROWING;
 
void create()
{
        set_name(HIC "�����" NOR, ({ "huilong bi", "huilong", "bi" }));
        set_weight(100);
        if (clonep()) 
                set_default_object(__FILE__); 
        else {
                set("long", HIC "һ֧��Ө��͸����ڣ����������һ��������\n" NOR);
                set("unit", "֧");
                set("value", 80000);
                set("no_sell", 1);
                set("material", "stone");
                set("base_unit", "֧");
                set("base_weight", 100);
                set("base_value", 1000);
        }
        set_amount(1);
        init_throwing(120);
        setup();
}
