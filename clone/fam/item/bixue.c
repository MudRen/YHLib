#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(NOR + RED "��Ѫʯ" NOR, ({"bixue shi", "bixue", "shi"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", RED "��Ӳ�����ı�Ѫʯ��ʯ������ӡ��Ѫɫ���ơ�\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("item_origin", 1);
                set("material_attrib", "stone");
                set("material_name", NOR + RED "��Ѫʯ" NOR);
                set("can_make", ({ "����" }));
                set("power_point", 50);
        }
}

int query_autoload()
{
        return 1;
}

