#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
�����Ǻ�ɽ��ɽ����һƬ���֣���˵���ﾭ����Ұ�޳�û��
LONG);

	set("objects",([
	      __DIR__"npc/hunter" : 1,	
	]));

	set("exits", ([
		"east"  :  __DIR__"shanlu6",
	]));

	set("outdoors","henshan");
	setup();
        replace_program(ROOM);
}
