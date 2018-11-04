#include <ansi.h>
#include <medical.h>

inherit MEDICAL_BOOK;

void create()
{
        set_name(WHT "���䵱ҩ��" NOR, ({ "wudang yaoli", "yaoli", "book", "shu" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", WHT "һ���¾ɵ���ᣬ�����ò���д�С��䵱ҩ�����֡�\n\n" NOR);
                set("material", "paper");
                set("value", 1);
                set("no_sell", "�٣��Ȿ����Ҳ����Ǯ��");
                set("skill", ([
                        "name" : "wudang-yaoli",
                        "jing_cost" : 40,
                        "difficulty" : 50,
                        "max_skill" : 149,
                        "min_skill" : 50,
                ]));

                set("can_make", ([
                        "liuhe"    : 80,         // ���Ϸ���ɢ
                        "qingxin"  : 100,        // ���Ķ���ɢ
                        "zhending" : 150,        // ��Ԫ��ɢ
                        "dieda"    : 80,         // ����������
                        "huojin"   : 100,        // �����Ѫ��
                        "tongmai"  : 150,        // ����ͨ����
                        "jiedu"    : 100,        // ţ�ƽⶾ��
                        "baihu"    : 200,        // �׻�������
                        "baola"    : 220,        // ���Ʊ�����
                ]));
        }
        setup();
}
