#include <ansi.h>
 
inherit ITEM;

void create()
{
        set_name(NOR + YEL "ʮ��ľż" NOR, ({ "18 muou", "18", "muou" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", NOR + YEL "
����һ��Сľ�У����е����޻�������������ľż�������ϲ
�ò�������ʹ�����ᣬ�������ŭ����ȺͿ��ף�����һ��ͬ��
ľż�������Ų�ͩ�ͣ��������ߣ�ȴ��Ѩ��λ�á����ľż��
�����ɣ���Ŀ��������������һ�ŷǳ��������ѧ��\n" NOR);
                set("value", 100000);
                set("no_sell", "��ҵĺ������ˣ����Ҳ������Ǯ��");
                set("material", "wood");
                set("skill", ([
                        "name"         : "luohan-fumogong",
                        "exp_required" : 500000,
                        "jing_cost"    : 150,
                        "difficulty"   : 100,
                        "max_skill"    : 179,
                        "min_skill"    : 0
                ]));
        }
}
