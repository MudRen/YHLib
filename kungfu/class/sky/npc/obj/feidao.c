#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
        set_name(HIW "С��ɵ�" NOR, ({ "xiaoli feidao", "feidao" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 6000);
                set("base_unit", "��");
                set("base_weight", 300);
                set("base_value", 0);
                set("material", "iron");
                set("long", HIW "һ��������ͨ�ķɵ��������Ͽ��˸�СС�ġ���֡�\n" NOR);
                set("wield_msg", HIW "$N" HIW "�ֱ�΢΢һ���������Ѷ��˱����λεķɵ���\n" NOR);
                set("unwield_msg",HIW "$N" HIW "�ֱ�΢΢һ�������еķɵ��������Ų�����\n" NOR);
        }
        set_amount(1);
        init_throwing(300);
        setup();
}

