#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����ɽ·�ϣ�ֻ������Ⱥ��������ǰ��Ⱥɽ������������
��������
LONG );
       set("exits", ([
		"northup" : "/d/jueqing/shanjiao",
		"southwest" : __DIR__"shulin",
	]));
	set("outdoors", "xiangyang");
	setup();
	replace_program(ROOM);
}