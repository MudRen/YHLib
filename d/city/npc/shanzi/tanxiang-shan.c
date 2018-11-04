#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
        set_name(NOR + YEL "̴����" NOR, ({ "tanxiang shan", "tanxiang", "shan" }));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", NOR + YEL "����һ������̴ľ���Ƶ�"
                            "��ľ�ȣ��ҷ������\n" NOR);
                set("value", 3000);
                set("material", "wood");
                set("wield_msg", "$N����һ��$n�������\n");
                set("unwield_msg", "$N����$n���ջػ��\n");
        }
        init_dagger(15);
        setup();
}

