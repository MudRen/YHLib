#include <ansi.h>
inherit ITEM;

string* titles = ({
        YEL "�������ĵá�" NOR,
        YEL "����·�ĵá�" NOR,
        YEL "���ӹ��ĵá�" NOR,
        YEL "�������ĵá�" NOR,

});

void create()
{
        string name;
        name = titles[random(sizeof(titles))];

        set_name(name, ({ "literate book5", "literate", "book5" }));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", YEL "����һ����飬��Ƥ��д���ĵ�ѧ˵�ĸ��֡�\n");
                set("value", 2500);
                set("no_sell", "�⡭��ֵʲôǮ��\n");
                set("material", "paper");
                set("skill", ([
                	"name" : "literate",
                	"jing_cost"  : 60,
                	"difficulty" : 60,
                	"max_skill"  : 139,
                	"min_skill"  : 120,
                ]) );
        }
        setup();
        move("/d/gaochang/mishi2");
}
