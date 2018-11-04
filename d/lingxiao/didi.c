#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", "�ص�");
        set("long", @LONG 
���ﰴ���ƶ��ԣ���������صף����Ǵ�ѩɽ��ɽ��֮���ˡ�
�������س�ʪ��������һ��ŨŨ������ζ��ǽ����Ȼ���ż�֧��
�ѣ��յ����������õġ�һ���������������龯��Ľ�ʿ������
��һ�Ⱦ޴��ʯ��(men)�ԡ�
LONG);
        set("no_clean_up", 0);

        set("exits", ([
                "up" : __DIR__"laolang",
        ]));
        set("objects", ([ 
                __DIR__"npc/shi" : 1,
        ])); 
        set("item_desc", ([
            	"men" : WHT "һ�Ⱥ���ʯ�ţ�����ǧ��֮�ء������Ӻ�����(push)����\n" NOR
        ]) );

        setup(); 
}

void init()
{
        add_action("do_push", "push");
}

int do_push(string arg)
{
    	object me = this_player();

    	message_vision(HIY "ֻ��$N" HIY "��������������������һ"
                       "�����˾���ʯ����ȥ��\n" NOR, me);

    	if (me->query("max_neili") < 500)
    	{
       		message_vision(HIR "����$N" HIR "���˸�������ʯ��ȴ"
                               "��˿������\n" NOR, me);
       		return 1;
    	}
    	message_vision(HIC "��ʱֻ������������������Ŧ����֮��������"
                       "ʯ�ž��������ˡ�\n" NOR, me);
    	set("exits/enter", __DIR__"dilao");

    	remove_call_out("close");
    	call_out("close", 5, this_object());

    	return 1;
}

void close_out()
{
    	if (query("exits/enter")) delete("exits/enter");
}

void close(object room)
{
    	message("vision", HIW "ֻ���������˴��һ������С���˵����㲻�������͸�үү���ɣ���\n"
                          "�������䣬һ�󾢷������ʯ�ű����һ�¹��ˡ�\n" NOR, room);
    	room->delete("exits/enter");
}
