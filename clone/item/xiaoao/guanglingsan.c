#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(NOR + YEL "������ɢ���ס�" NOR, ({ "guangling san",
                 "guangling", "san" }));
        set_weight(300);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("no_sell", "����ɢ���㵱�Ҳ�ʶ������\n");
                set("long", NOR + YEL @LONG
����һ����Ϊ�оɵ����ף������ù���д�š�����
ɢ�����֡���˵��������������ʱ����Ȼ��ʧ����
ȴ��֪Ϊ�ν�����������֡�
LONG NOR);
                set("value", 1);
                set("material", "paper");
                set("skill", ([
                        "name"         : "guangling-san",
                        "exp_required" : 30000,
                        "jing_cost"    : 50,
                        "difficulty"   : 40,
                        "max_skill"    : 199,
                        "min_skill"    : 0,
                        "need"         : ([ "literate" : 200 ]),
                ]));
        }
}

