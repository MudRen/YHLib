#include <ansi.h>
#include <weapon.h>

inherit CLUB;

void create()
{
        set_name(HIW "ʥ��ʿ�" NOR, ({ "chivalry lance", "chivalry", "lance" }));
        set_weight(30000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIW "����һ�����Ƶĳ�ꪣ������ޱȣ�����ԭ���Ѽ�����\n" NOR);
                set("value", 10000);
                set("material", "silver");
        }
        init_club(90);
        setup();
}

