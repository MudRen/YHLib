// menshen.c

#include <ansi.h>
#include <room.h>

inherit ITEM;

void setup() {}

void create()
{
	set_name(HIM "����" NOR, ({ "men shen", "menshen" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
	        set("long", "����һ�Ż���������ɫ�����񣬳���"
                            "����������������������а��\n");
                set("unit", "��");
        }

        set("no_get", 1);
        setup();
}

void init()
{
        object env;
        object me;

        if (! objectp(env = environment()))
                return;

        if (! clonep(env) || base_name(env) != CHAT_ROOM)
                return;

        if (! stringp(env->query("owner_id")) ||
            ! stringp(env->query("startroom")))
                return;

        me = this_player();
        if (! interactive(me) || env->welcome(me))
                return;

        message_vision("������һ�������η�������Ҳ"
                       "�����ˣ���˵������ͭ��һ����"
                       "��$Nһ����÷��˳�ȥ��\n", me);
        me->move(env->query("startroom"));
        me->start_busy(3);
        message("vision", "ֻ�����һ����" + me->name() +
                "���˳�����������һ�����һ����ġ�\n",
                environment(me), ({ me }));
}
