#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
        set_name(HIM "������" NOR, ({ "chouwu shan", "chouwu", "shan" }));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIM "����һ��˿�����棬�ʻ滨�ݣ��趯"
                            "ʱѤ����ʵĳ����ȡ�\n" NOR);
                set("value", 1000);
                set("material", "wood");
                set("wield_msg", "$N����һ��$n�������\n");
                set("unwield_msg", "$N����$n���ջػ��\n");
        }
        init_dagger(15);
        setup();
}

