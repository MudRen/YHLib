#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(WHT "����ʯ����" NOR, ({ "ping feng", "ping", "feng" }) );
        set_weight(500000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", WHT "һ������ʯ�����磬�������Ȼ��"
                            "������������\n" NOR);
                set("value", 5000000);
        }
}
