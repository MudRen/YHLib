#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(NOR + HIG "��Ϫɽ����ͼ��" NOR, ({ "xishan xinglvtu",
                 "tu", "xishan", "xinglvtu" }));
        set_weight(600);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("no_sell", "�ҵ��죬�㡭��֪������ɶô��Ҳ��������\n");
                set("long", HIG @LONG
����һ����Ϊ�¾ɵ�ͼ�������Ͻ����š����η���
��Ϫɽ����ͼ��ʮ�֣�һ����ɽ�������ī����
�������۾�֮����ʵ�Ǿ���֮����������ɽɭȻ
���ʣ�����ֽ�ϵ�ͼ����Ҳ���˲����������˸�ɽ
��ֹ֮�С�
LONG NOR);
                set("value", 1);
                set("material", "paper");
                set("skill", ([
                        "name"         : "drawing",
                        "exp_required" : 10000,
                        "jing_cost"    : 60,
                        "difficulty"   : 30,
                        "max_skill"    : 199,
                        "min_skill"    : 100,
                        "need"         : ([ "literate" : 200 ]),
                ]));
        }
}

