#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(NOR + HIR "�׻𺮾�" NOR, ({"leihuo hanjing", "leihuo", "hanjing", "jing"}));
        set_weight(4500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR "�����֮�������۳ɵľ��壬����һ�����������\n" NOR);
                set("unit", "��");
                set("value", 10000);
                set("item_origin", 1);
                set("material_attrib", "stone");
                set("material_name", NOR + HIR "�׻𺮾�" NOR);
                set("can_make", ({ "��", "��", "��", "�̱�", "��", "��", "��" }));
                set("power_point", 70);
        }
}

int query_autoload()
{
        return 1;
}

