#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ٵ�");
	set("long", @LONG
����һ������������С����ǰ�Ų�Զ����һƬ���֣���֪
��ͨ��δ���
LONG );
       set("exits", ([
		"north" : __DIR__"shulin",
		"south" : __DIR__"guandao_2",
	]));
	set("outdoors", "xiangyang");
	setup();
	replace_program(ROOM);
}