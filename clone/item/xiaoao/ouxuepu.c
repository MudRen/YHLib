#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR "��ŻѪ�ס�" NOR, ({ "ouxue pu", "pu", "ouxue" }));
        set_weight(600);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("no_sell", "�٣��ⶫ��ҲֵǮ��\n");

                set("long", HIR @LONG
����һ�����Ƶ���֣������˹������ٸ�������ɽ
֮´��һ����������ɱ�ô�ܵ���֡�ȫ��һ��ʮ
���ţ�ɱ�þ��Ķ��ǡ���˵���ٸ����֮�ʵ�ʱŻ
Ѫ��������˳�֮ΪŻѪ�ס�
LONG NOR);
                set("value", 1);
                set("material", "paper");
                set("skill", ([
                        "name"         : "chess",
                        "exp_required" : 10000,
                        "jing_cost"    : 60,
                        "difficulty"   : 30,
                        "max_skill"    : 199,
                        "min_skill"    : 100,
                        "need"         : ([ "literate" : 200 ]),
                ]));
        }
}

