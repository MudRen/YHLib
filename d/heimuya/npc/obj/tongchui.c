#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name(YEL "ͭ��" NOR, ({ "tong chui", "tong", "chui", "hammer" }));
        set_weight(15000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", YEL "����һ������ͭ����Ĵ󴸣��Եü��ǳ��ء�\n" NOR);
                set("value", 3000);
                set("material", "steel");
                set("wield_msg", "$N���һ�ӣ��ճ�һ�Գ��ص�$n��\n");
                set("unwield_msg", "$N�����е�$n�����ջء�\n");
        }
        init_hammer(40);
        setup();
}
