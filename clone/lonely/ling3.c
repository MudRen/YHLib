#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(NOR + YEL "ʥ����" NOR, ({ "shenghuo ling", "shenghuo", "ling" }));
        set_weight(1000);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("value", 10000);
                set("material", "steel");
                set("no_sell", "�����̵ģ�����������ҲֵǮ��");
                set("long", NOR + YEL "
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
                        "exp_required" : 1500000,
                        "jing_cost"    : 120,
                        "difficulty"   : 80,
                        "max_skill"    : 149,
                        "min_skill"    : 120,
                        "need"         : ([ "sanscrit" : 200 ]),
                ]));
        }
        init_sword(80);
        setup();
}
