#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(CYN "����ȭ��ܸ" NOR, ({ "miji", "book" }));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������С�ᣬ��������˲��پ����ȭ����\n");
                set("value", 0);
                set("material", "paper");
                set("skill", ([
                        "name": "tiexian-quan",        // name of the skill
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost":    20,     // jing cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                        "max_skill":    150      // the maximum level you can learn
                ]) );
        }
}
