#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(HIW "����" NOR, ({ "jian qi", "jian", "qi" }));
        set_weight(1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIW "����һ�����������ɵĽ�����\n" NOR);
                set("value", 0);
                set("no_drop", "������������������ɣ�����ܹ�������\n");
                set("material", "air");
                set("power", 1000);
        }
        init_sword(query("power"));
        setup();
}
