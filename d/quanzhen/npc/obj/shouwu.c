inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(NOR + WHT "������" NOR, ({ "he shouwu", "he", "shouwu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
	        set("long", NOR + WHT "����һ֧�ѳ����εĺ���"
                            "�ڣ�����������ҩ��\n" NOR);
        	set_weight(800);
                set("value", 10000);
	        set("unit", "֧");
        	set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{
        if ((int)me->query("max_jingli") < 100)
	{
        	write(HIW "�������һ֧�����ڣ�ֻ���þ�����֮����\n" NOR);
                me->improve_jingli(2 + random(1));
        } else
	{
                write(HIC "�������һ֧�����ڣ����Ǻ���ûʲô�á�\n" NOR);
        }
        destruct(this_object());
        me->unconcious();
        return 1;
}
