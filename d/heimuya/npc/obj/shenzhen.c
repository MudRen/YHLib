#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
        set_name(WHT "��Ѫ����" NOR, ({ "heixue shenzhen", "heixue", "shenzhen", "zhen" }) );
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "Щ");
                set("value", 0);
                set("base_unit", "��");
                set("base_weight", 200);
                set("base_value", 0);
                set("material", "iron");
                set("long", WHT "����һЩ����ɫ��ϸ�����룬��Լ����\n" NOR);
        }
        set_amount(50);
        init_throwing(50);
        setup();
}
