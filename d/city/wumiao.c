#include <room.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���������������������������������Ϸ������������顰���Һ�
ɽ���ĺ��ҡ����������Ƕ�š����ұ������ĸ����֡����˵��ˣ���������
�����Ϲ��Ͼ���������ݡ��Ա��ƺ���һ�����š�
LONG );
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_sleep_room", 1);

        set("valid_startroom", 1);
	set("objects", ([
		__DIR__"obj/box" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"beidajie2",
		"up"   : __DIR__"wumiao2",
                "down" : "/d/wizard/herodoor"
	]));
	setup();

        replace_program(ROOM);
}