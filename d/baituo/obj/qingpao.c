#include <ansi.h> 
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIG "��ɫ˿��" NOR, ({ "si pao", "cloth", "pao" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIG "���Ǽ��ʵ��������ɫ�λ�˿�ۣ��ر���Ů��������\n" NOR);
                set("material", "cloth");
                set("armor_prop/armor", 8);
                set("value", 100);
        }
        setup();
}
