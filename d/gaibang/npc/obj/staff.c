#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name(NOR + GRN "���" NOR, ({ "zhu bang", "zhu", "bang" }));
        set_weight(1500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", GRN "����һ����Ϊ�ƾɵ������������Ϊ����ʹ�á�\n" NOR);
                set("unit", "��");
                set("material", "wood");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        init_staff(5);
        setup();
}
