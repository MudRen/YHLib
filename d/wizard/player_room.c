// /d/wizard/guest_room.c

#include <room.h>
#include <ansi.h>

inherit ROOM;

int is_chat_room() { return 1; }

void create()
{
	set("short", HIG "��ҽ�����" NOR);
	set("long", @LONG
��������ʦ����ҽ����Ǽ����ĵط�����������������
������Ҳ������������(post)���㽫���ܵ�����Զ�뽭����û
������Ҳû����ɱ��ף�����ˣ�

                                ==�׻�Ӣ��ʷȫ����ʦ==
LONG );

	set("exits", ([
		"northwest": __DIR__"guest_room",               
        ]));

	set("no_fight", 1);

	setup();
	"/clone/board/heroplayer_b"->foo();
        replace_program(ROOM);
}

