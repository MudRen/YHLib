#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name(NOR + CYN "��˿" HIY "����" NOR, ({ "zhensi baojia", "zhensi", "baojia" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", NOR + CYN "����һ�����������ף����ֳ�"
                            "�أ�����֮�º������ۡ�\n" NOR);
                set("no_sell", "����������ֵǮô��");
                set("value", 100000);
                set("material", "silk");
                set("armor_prop/armor", 200);
                set("stable", 100);
        }
        setup();
        move("/d/beijing/aofu_mishi");
}
