#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL "�����" NOR, ({ "literate book4", "literate", "book4"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
            	set("unit", "��");
            	set("long", YEL "����һ���׷��ӵ����\n" NOR);
            	set("value", 1000);
                set("no_sell", "�⡭��ֵʲôǮ��\n");
            	set("material", "paper");
            	set("skill", ([
                	"name": "literate",
                	"jing_cost"  : 55,
                	"difficulty" : 35,
                	"max_skill"  : 119,
                	"min_skill"  : 100,
            	]));
        }
}
