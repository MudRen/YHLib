#include <ansi.h>
#include <armor.h>

inherit BOOTS; 

void create()
{
        set_name(HIG "��ݽ�" NOR, ({ "shen caojie", "shen", "caojie" }));
        set_weight(100);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", HIG "�����Ħ��ʦһέ�ɽ�ʱ�����Ĳ�Ь��\n" NOR);
                set("wear_msg", HIG "$N" HIG "��һ����ݽ������䡣\n" NOR);
                set("remove_msg", HIG "$N" HIG "����ݽ�����ȡ�£��Żذ�"
                                  "�ҡ�\n" NOR);
                set("no_sell", "����ɶ����������ô��");
                set("value", 100000);
                set("material", "silk");
                set("armor_type", "feet");
                set("armor_prop/dodge", 50);
                set("armor_prop/armor", 50);
                set("stable", 100);
        }
        setup();
}
