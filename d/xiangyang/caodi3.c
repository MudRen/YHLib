inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
������������Ĳݵء��ɹű���������������İ���ȫ��
���ˣ��ɹű��۳���ȥ����Ϊ��������������������š�
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"south"  : __DIR__"northgate2",
		"north"  : "/d/luoyang/guandaos6",
	]));
	set("objects", ([
		__DIR__"npc/menggubing" : 2,
	]));
	setup();
	replace_program(ROOM);
}

