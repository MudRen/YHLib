#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name(WHT "��ͷ" NOR, ({ "chu tou", "chu", "tou" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", WHT "����һ�ѳ�ͷ����ͨ���յ��ճ���ũ��Ʒ��\n" NOR);
                set("value", 50);
                set("material", "steel");
                set("wield_msg", WHT "$N" WHT "�ó�һ�ѳ�ͷ�������С�\n" NOR);
                set("unwield_msg", WHT "$N" WHT "�����еĳ�ͷ���ڼ��ϡ�\n" NOR);
        }
        init_hammer(4);
        setup();
}
