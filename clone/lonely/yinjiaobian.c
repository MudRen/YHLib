#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(HIW "���Ա�" NOR, ({ "yinjiao bian", "yinjiao", "bian", "whip" }) );
        set_weight(1000);
        if (clonep())
                destruct(this_object());
        else {
                set("long", HIW "һ�����������ĳ��ޣ����������˵��̣����Ǽ��͡�\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", HIW "$N" HIW "������ȡ��һ�����������ĳ��ޣ���ջ����Ȧ�ӡ�\n" NOR);
                set("unwield_msg", HIW "$N" HIW "һ����ߣ����������Ա��̺ã��Ż����䡣\n" NOR);
                set("stable", 100);
        }
        init_whip(120);
        setup();
}
