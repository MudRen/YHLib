#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(NOR + WHT "���콣" NOR, ({ "yitian jian", "yitian", "jian", "sword" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIY "�������������������������Ƶ����콣��\n" NOR);
                set("value", 500);
                set("material", "wood");
                set("wield_msg", HIM "$N" HIM "��ৡ��ĳ��$n" HIM "����ʱ��"
                                 "��һ���������ζ��\n��ϸһ����ԭ���������"
                                 "������ľͷ�Ƴɵġ�\n" NOR);
        }
        init_sword(10);
        setup();
}
