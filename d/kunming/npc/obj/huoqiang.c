#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name(HIY "���ǹ" NOR, ({"jin huoqiang", "jin", "huoqiang"}));
        set_weight(5000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("long", HIY "һ֧�ɻƽ����ɣ�������ϸ�Ļ�ǹ��\n" NOR);
                set("value", 25000);
                set("wield_msg", HIY "$N����һ֧���ɫ�Ļ�ǹ�������С�\n" NOR);
                set("unwield_msg", HIY "$N�����еĽ��ǹ���뻳�С�\n" NOR);
        }
        init_hammer(30);
        setup();
}
