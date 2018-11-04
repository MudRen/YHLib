#include <ansi.h>
#include <medical.h>

inherit MEDICAL_BOOK;

void create()
{
        set_name(HIM "���һ�ҩ��" NOR, ({ "taohua yaoli", "yaoli", "book", "shu" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", HIM "һ���¾ɵ���ᣬ������׭��д�С��һ�ҩ�����֡�\n\n" NOR);
                set("material", "paper");
                set("value", 1);
                set("no_sell", "�٣��Ȿ����Ҳ����Ǯ��");
                set("skill", ([
                        "name" : "taohua-yaoli",
                        "jing_cost" : 60,
                        "difficulty" : 40,
                        "max_skill" : 159,
                        "min_skill" : 30,
                ]));

                set("can_make", ([
                        "liuhe"    : 80,        // ���Ϸ���ɢ
                        "qingxin"  : 100,       // ���Ķ���ɢ
                        "zhending" : 150,       // ��Ԫ��ɢ
                        "dieda"    : 80,        // ����������
                        "huojin"   : 100,       // �����Ѫ��
                        "tongmai"  : 150,       // ����ͨ����
                        "jiedu"    : 100,       // ţ�ƽⶾ��
                        "shadan"   : 160,       // �����赨��
                        "jiuhua"   : 200,       // �Ż���¶��
                        "wuchang"  : 250,       // �޳���
                ]));
        }
        setup();
}
