#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(NOR + WHT "������" NOR, ({ "heilong bian", "heilong", "bian", "whip" }) );
        set_weight(1000);
        if (clonep())
                destruct(this_object());
        else {
                set("long", WHT "һ֧ͨ����ڵĳ��ޣ�����ȥ���Ǻܼ��͡�\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", "��ޡ��ⲻ��ʷ����ү�Ķ������㡭������ô�ˣ�");
                set("material", "steel");
                set("wield_msg", WHT "$N" WHT "������ȡ��һ����ڵĳ��ޣ���ջ����Ȧ�ӡ�\n" NOR);
                set("unwield_msg", WHT "$N" WHT "һ����ߣ������к������̺ã��Ż����䡣\n" NOR);
                set("stable", 100);
        }
        init_whip(80);
        setup();
}
