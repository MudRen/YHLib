#include <weapon.h>
#include <music.h>
#include <ansi.h>

inherit SWORD;
inherit MI_QIN;

void create()
{
        set_name(YEL "̴ľ��" NOR,({ "tanmu qin", "tanmu", "qin" }) );
        set_weight(9000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��ͨ�����ϵ�̴ľ���Ƶ��١�\n" NOR);
                set("unit", "��");
                set("value", 5000);
                set("material", "wood");
                set("wield_msg", YEL "$N" YEL "�ӱ��󻺻�ȡ��һ��̴ľ�ٺϱ������С�\n" NOR);
                set("unwield_msg", YEL "$N" YEL "�����е�̴ľ�������������ŵ�����\n" NOR);
                set("stable", 10);
        }
        init_sword(20);
        setup();
}

void init()
{
        add_action("play_qin", "play");
}
