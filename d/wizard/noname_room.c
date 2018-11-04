// /d/wizard/guest_room.c

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIR "����������" NOR);
	set("long", @LONG
��������������Ը��׻���ʦ���ֲ���������ҿ�������
ô������������(post)��������ҽ����ܿ����������ԣ�����
�������Ծٱ��������id������������Ϊ���׻���ʦ��Ϊ����
������ȫ���ܡ�
                                ==�׻�Ӣ��ʷȫ����ʦ==
LONG );

	set("exits", ([
		"east": __DIR__"hall", 
                "west": __DIR__"wizard_room",              
        ]));

	set("no_fight", 1);

	setup();
	"/clone/board/noname_b"->foo();
}

int valid_leave(object me, string dir)
{
	if (dir == "west" && ! wizardp(me))
		return notify_fail("ֻ����ʦ���ܽ�ȥ��\n");

	return ::valid_leave(me, dir);
}


