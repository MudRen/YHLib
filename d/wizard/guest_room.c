
#include <room.h>
#include <ansi.h>

inherit ROOM;

int is_chat_room() { return 1; }

void create()
{
	set("short", HIY "��ʦ�����" NOR);
	set("long", @LONG
��������ʦ����ҽ����ĵط�������������Ժ���ʦ����
���ԣ��޾�������
LONG );

	set("exits", ([
		"west": __DIR__"hall",
		"southeast"  : __DIR__"player_room",
                "northeast"  : __DIR__"develop_room",
                "east"       : __DIR__"bug_room"
        ]));

	set("no_fight", 1);

	setup();
        replace_program(ROOM);
}
