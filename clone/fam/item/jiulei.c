#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(NOR + HIM "��������ɴ" NOR, ({"xuanyin sha", "xuanyin", "sha"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "��������ɴ����Ȼ������ë��ȴ�Ǽ���������\n" NOR);
                set("unit", "��");
                set("value", 9000);
                set("item_origin", 1);
                set("material_attrib", "stone");
                set("material_name", NOR + HIM "��������ɴ" NOR);
                set("can_make", ({ "����", "ս��", "����", "����", "ѥ��", "��" }));
                set("power_point", 60);
        }
}

int query_autoload()
{
        return 1;
}

