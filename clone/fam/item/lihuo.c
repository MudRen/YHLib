#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC "��" HIR "��" HIC "��" HIW "��" HIC "��" NOR,
                ({"lihuo yu", "lihuo", "yu"}));
        set_weight(3400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIC "���˲�����������һ�����ȣ���һ��ȴ�溮�������Զ���ˮ���\n" NOR);
                set("unit", "��");
                set("value", 30000);
                set("item_origin", 1);
                set("material_attrib", "stone");
                set("material_name", HIC "��" HIR "��" HIC "��" HIW "��" HIC "��" NOR);
                set("can_make", "all");
                set("not_make", ({ "����", "ս��", "����", "����", "ѥ��", "��" }));
                set("power_point", 90);
        }
}

int query_autoload()
{
        return 1;
}

