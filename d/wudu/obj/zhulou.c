#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
        set_name("��¨", ({"zhu lou", "zhu", "lou"}));
        set_weight(300);
        set_max_encumbrance(15000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��С�ڴ�ǵ���¨����������Ų�ҩ��\n");
                set("wear_msg", "$N����¨���ڱ��ϡ�\n");
                set("remove_msg", "$N����¨�ӱ��Ϸ���������\n");
                set("value", 50);
                set("material", "bamboo");
                set("armor_prop/armor", 3);
        }
        setup();
}

int is_container() { return 1; }
