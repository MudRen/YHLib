#include <ansi.h>
#include <weapon.h>

inherit XSWORD;

void create()
{
        set_name(NOR + GRN "������" NOR, ({"lvyu dongxiao", "lvyu", "dongxiao", "xiao"}));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "֧");
                set("long", GRN "һ֧�������ɵĶ������ȥ��Ө��������"
                            "���˾�������������\n" NOR);
                set("value", 800000);
                set("no_sell", 1);
                set("material", "stone");
                set("wield_msg", GRN "$N" GRN "����һ�ӣ������Ѷ���һ֧��Ө�������������\n" NOR);
                set("unwield_msg", GRN "$N" GRN "����������һת��գ�ۼ���Ȼ����Ӱ�١�\n" NOR);
                set("stable", 100);
        }
        init_xsword(100);
        setup();
}
