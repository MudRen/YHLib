#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(NOR + WHT "����������" NOR, ({ "shuaiyi tie", "tie", "shuaiyi" }));
        set_weight(600);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("no_sell", "�ҵ��죬�㡭��֪������ɶô��Ҳ��������\n");
                set("long", WHT @LONG
������Ƴ���������������������ϵĲ���󿪴�
�أ�����һλ���ָ���չ���Ṧ���ܸ߷��ͣ���Ȼ
�ж�Ѹ�ݣ�ȴ��ʧ���ŵķ��¡���βд������ϸ�
�˲���ͼ�£�����������Ƿ�ͬС�ɡ�
LONG NOR);
                set("value", 1);
                set("material", "paper");
                set("skill", ([
                        "name"         : "calligraphy",
                        "exp_required" : 10000,
                        "jing_cost"    : 60,
                        "difficulty"   : 30,
                        "max_skill"    : 199,
                        "min_skill"    : 100,
                        "need"         : ([ "literate" : 200 ]),
                ]));
        }
}

