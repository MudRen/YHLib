#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���Ŵ���");
	set("long", @LONG
���������Ŵ��ţ�������ľ���Ž����ر��š����ྲ����
���رܡ������ӷַ���ͷʯʨ�ӵ��Աߡ�ǰ����һ����ģ���
Ȼ�ǹ�С����ԩ�õġ�������������ǰѲ�ߡ�
LONG );
	set("exits", ([
		"south" : __DIR__"xidajie1",
		"north" : __DIR__"ymzhengting",
	]));
	set("objects", ([
		__DIR__"npc/yayi" : 4,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("ya yi", environment(me)))
           && dir == "north")
		return notify_fail(CYN "���������ȵ����������䡭��\n" NOR);

	return ::valid_leave(me, dir);
}
