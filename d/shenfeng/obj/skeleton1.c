#include <ansi.h>
inherit ITEM;

#define ZHUJIAN    "/clone/lonely/book/zhujian2"

void create()
{
	set_name("��Ǭ�ĺ���", ({ "Skeleton", "skeleton", "����" }));
        set_weight(500);
        if (clonep())
        	set_default_object(__FILE__);
    	else {
        	set("unit", "��");
                set("long", "�⸱�����Ѿ���������ܾ��ˡ�\n");
        	set("value", 1);
        	set("no_get", "�ⶫ��һ����ɢ�����Ǳ��ɣ�\n");
    	}
}

void init()
{
        add_action("do_move", "move");
}

int do_move(string arg)
{
        object me, ob;
        me = this_player();

        if (! arg || ! id(arg))
                return 0;

        ob = find_object(ZHUJIAN);
        if (! ob) ob = load_object(ZHUJIAN);

        if (! environment(ob))
        {
        	ob->move(environment(me));
                message_vision(HIC "\n$N" HIC "С������ؽ������ƿ���������"
                               "���Ȼ����һ�����\n" NOR, me);
                return 1;
        } else
                message_vision(HIY "$N" HIY "С������ؽ������ƿ�������ʲô"
                               "Ҳû���֡�\n" NOR, me);
        return 1;
}
