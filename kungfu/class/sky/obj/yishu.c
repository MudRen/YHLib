#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(WHT "��ɽ����" NOR, ({ "yishu", "shu", "book" }));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����ǵ��꡸�Ե�����ɽ����ǰ�����飬������������Ե�������ᡣ\n");
                set("value", 100);
                set("material", "paper");
                set("skill", ([
                        "name": "badao-daofa",        // name of the skill
                        "exp_required": 500000,      // minimum combat experience required
                        "jing_cost":    80,     // jing cost every time study this
                        "difficulty":   80,     // the base int to learn this skill
                        "max_skill":    150      // the maximum level you can learn
                ]) );
        }
}

