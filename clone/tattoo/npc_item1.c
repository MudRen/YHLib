#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(NOR + YEL "̴ľ�ź�" NOR, ({ "tanmu guhe", "tanmu", "guhe" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + YEL "����һ��̴ľ����У���������"
                            "�кܳ�����ʱ�ˡ�\n" NOR);
                set("unit", "��");
                set("value", 15000);
                set("material", "wood");
        }
}
