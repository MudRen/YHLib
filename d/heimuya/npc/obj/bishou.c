#include <ansi.h>
#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name(HIC "����ذ" NOR, ({"yueya bi", "yueya", "bi", "dagger"}));
        set_weight(800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIC "һ��������ϸ������ذ�ס�\n" NOR);
                set("value", 10000);
                set("material", "stone");
        }
        init_dagger(35);
        setup();
}
