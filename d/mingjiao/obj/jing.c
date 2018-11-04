#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL "����٤����" NOR, ({ "lengjia jing", "jing", "book" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", YEL "����һ�������ľ��飬ֻ���Ͳ����ý��ܣ��䳤��\n"
                            "����Գ��֮�У���ҳ��Ȼ�������������д����\n"
                            "���������������֣���ȴ��һ��Ҳ��ʶ�á�\n" NOR);
                set("value", 10);
                set("material", "silk");
                set("skill", ([
                        "name":         "buddhism",
                        "exp_required": 1000,
                        "jing_cost":    10,
                        "difficulty":   10,
                        "max_skill":    50,
                        "min_skill":    0,
                        "need" : ([ "sanscrit" : 500 ]),
                ]) );

        }
}
