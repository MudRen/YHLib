#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIW "���½���" NOR, ({ "jin pao", "jin", "pao", "cloth" }));
        set("long", HIW "����һ��������̳����������Ļ������ۡ�\n" NOR);
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
                set("armor_prop/armor", 1);
                set("value", 10000);
                set("no_sell", "�ҵ��졭��������̵Ķ����㶼�ó�������");
        }
        setup();
}
