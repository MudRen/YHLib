#include <ansi.h>
#include <weapon.h>

inherit CLUB;

void create()
{
        set_name(HIC "�������롤�ƾ���" NOR, ({ "po jiuyu", "club", "gun", "shenzhen" }));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("value", 3400000);
                set("material", "steel");
                set("long", HIW "\n�������롤�ƾ����˾���������֮һ��\n" NOR);
                set("wield_msg", HIR "$N���ᶶ��$n" HIR "��ɲʱ����������һ��ɱ��ֱ��������\n" NOR);
        }
        init_club(220);
        setup();
}


