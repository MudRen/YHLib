#include <ansi.h>
 
inherit ITEM;

void create()
{
        set_name(HIY "������ɨҶ�ȷ���" NOR, ({ "xuanfeng paper", "xuanfeng", "paper", "shu", "book" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", HIY "��������ֽƬ������д�Ķ��������Ŀھ�Ҫּ��ȴ��\n"
                            "��ҩʦ���ױʣ��ּ��پ�ͦ�Σ���һҶ������д����\nĿ��"
                            "�ǡ�����ɨҶ�ȷ������֡�\n" NOR);
                set("value", 1);
                set("no_sell", "�Ȿ�������Լ����Űɡ�");
                set("material", "paper");
                set("skill", ([
                        "name"       : "xuanfeng-tui",
                        "jing_cost"  : 100,
                        "difficulty" : 30,
                        "max_skill"  : 119,
                        "min_skill"  : 0
                ]));
        }
}
