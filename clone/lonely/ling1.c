#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(NOR + CYN "ʥ����" NOR, ({ "shenghuo ling", "shenghuo", "ling" }));
        set_weight(1000);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("value", 10000);
                set("material", "steel");
                set("no_sell", "�����̵ģ�����������ҲֵǮ��");
                set("long", NOR + CYN "
����һ�����������ĺ��ƣ�����ȥ�ǽ���������ʵ�ȴ�Ǽ�Ӳ
�ޱȡ��������ƾ�����͸���������������л�����ڣ�ʵ����
����ӳ�⣬��ɫ��á����Ͽ̵��в��ٲ�˹�ģ������ƺ�����
ѧ�йأ�������£�������Ҫ��ϸ�ж�һ�����ܹ�����\n" NOR);
                set("wield_msg", HIR "$N" HIR "��������һƬ�����"
                                 "�����������С�\n" NOR);
                set("unwield_msg", HIR "$N" HIR "����һ�����ѽ�ʥ��"
                                 "���������䡣\n" NOR);
                set("skill", ([
                        "name"         : "shenghuo-ling",
                        "exp_required" : 1000000,
                        "jing_cost"    : 80,
                        "difficulty"   : 50,
                        "max_skill"    : 49,
                        "min_skill"    : 0,
                        "need"         : ([ "sanscrit" : 150 ]),
                ]));
        }
        init_sword(80);
        setup();
}
