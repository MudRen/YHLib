inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "��ڤ��");
	set("long", @LONG
������ڤ���ˣ���������Ⱥ��Χ�ƣ�ɽʯ��ӳ��ǰ����Զ
���м���С��(room)��ż��ɽ¹׷����Ϸ������������������
����������Դһ�㡣ԶԶ������ڤ���ϰ�ѩһƬ������������
���ܣ������Ŀ�������
LONG );
	set("exits", ([
		"southup"    : __DIR__"shanlu3",
		"northwest"  : __DIR__"shanlu4",
                "enter"      : __DIR__"xiaowu",
	]));

        set("objects", ([
                "/kungfu/class/xuanming/lu" : 1,
        ]));

        set("item_desc", ([
                "room"  : NOR + YEL "һ���ª��é���ݣ�������������Ϣ������\n" NOR,
        ]));

	set("outdoors", "xuanming");
	setup();
	replace_program(ROOM);
}
