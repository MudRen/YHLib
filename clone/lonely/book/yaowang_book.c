#include <ansi.h>
#include <medical.h>

inherit MEDICAL_BOOK;

void create()
{
        set_name(RED "��ҩ����ƪ��" NOR, ({ "yaowang shenpian", "yaowang",
                                            "shenpian", "pian", "book" }));
        set_weight(600);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("no_sell",1);
                set("long", RED "һ���������鼮�������Ȼд�š�ҩ����ƪ���ĸ��֡�\n" NOR);
                set("value", 800000);
                set("no_sell", 1);
                set("material", "paper");
                set("skill", ([
                        "name":         "yaowang-shenxin",
                        "exp_required": 250000,
                        "jing_cost" :   50,
                        "difficulty":   50,
                        "max_skill":    249,
                        "min_skill":    100
                ]));

                set("can_make", ([
                        "liuhe" : 80,           // ���Ϸ���ɢ
                        "qingxin" : 100,        // ���Ķ���ɢ
                        "zhending": 150,        // ��Ԫ��ɢ
                        "dieda" : 80,           // ����������
                        "huojin" : 100,         // �����Ѫ��
                        "tongmai" : 150,        // ����ͨ����
                        "jiedu" : 100,          // ţ�ƽⶾ��
                        "jiuhua" : 200,         // �Ż���¶��
                        "wuchang" : 250,        // �޳���
                ]));

        }
}
