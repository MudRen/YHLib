#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(NOR + MAG "��˹���̷̽�" NOR, ({ "bosi cloth", "bosi", "cloth" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", NOR + MAG "����һ����˹�����ܶ�Ľ̷���\n" NOR);
                set("value", 300);
                set("material", "silk");
                set("armor_prop/armor", 2);
        }
        setup();
}

