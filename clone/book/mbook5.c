#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL "��ǧ����" NOR, ({ "medical book5", "medical", "book5" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", YEL "ǧ������ҽѧ���䣬�����˸���������֢�����Ʒ�����\n" NOR);
                set("value", 3000);
                set("no_sell", "�⡭��ֵʲôǮ��\n");
                set("material", "paper");
                set("skill",
                ([
                        "name" : "medical",
                        "jing_cost"  : 60,
                        "difficulty" : 50,
                        "max_skill"  : 149,
                        "min_skill"  : 120,
                ]) );
        }
}
