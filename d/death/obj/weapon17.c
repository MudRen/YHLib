#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name(MAG "�����ȡ��ֻ�" NOR, ({ "lun hui", "qixingzhang", "zhang", "staff" }) );
        set_weight(18000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1600000);
                set("material", "steel");
                set("long", HIW "\n�����ȡ��ֻ��˾���������֮һ��\n" NOR);
                set("wield_msg", HIR "$N���ᶶ��$n" HIR "��ɲʱ����������һ��ɱ��ֱ��������\n" NOR);
        }
        init_staff(120);
        setup();
}

