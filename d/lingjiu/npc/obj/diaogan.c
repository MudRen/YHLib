#include <weapon.h>
inherit CLUB;

void create()
{
        set_name("����", ({ "diao gan", "diao", "gan" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ľ�Ƶĵ��ͣ���������Ϊ���ء�\n");
                set("value", 50);
                set("material", "steel");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
                set("shaolin",1);
        }
        init_club(35);
        setup();
}

