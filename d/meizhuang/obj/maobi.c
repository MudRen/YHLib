#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
        set_name(WHT "ë��" NOR, ({ "mao bi", "bi", "mao" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("long", "һ֧��ͨ��ë�ʣ��������˳���������Ϊ��Ѩ�ı�����\n");
                set("value", 200);
                set("material", "steel");
                set("wield_msg", "$N�Ӷ����ͳ�һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�Żض��\n");
        }
        init_dagger(15, 0);
        setup();
}
