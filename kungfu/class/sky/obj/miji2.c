#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC "�ļ�����" NOR, ({ "jianfa miji", "book", "miji" }));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������С�ᣬ����������ļ������İ¾���\n");
                set("value", 30);
                set("material", "paper");
                set("skill", ([
                        "name": "siji-jianfa",        // name of the skill
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost":    50,     // jing cost every time study this
                        "difficulty":   50,     // the base int to learn this skill
                        "max_skill":    150      // the maximum level you can learn
                ]) );
        }
}

