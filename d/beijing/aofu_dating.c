inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","��������");
	set("long", @LONG
���������ݸ��Ĵ����������൱�Ŀ����������ܵ�ǽ���������˸�����
�˵��漣����������һ��������룬��Ŀ��࣬���Ż���ӵ��������ӣ�����
�Ǿ��ǵ�����һ�󳼣�������Ϊ�����޵�һ��ʿ���������ˡ�����������һ��
���ȣ�����ͨ�������ĺ�Ժ���ڡ�
LONG );
	set("exits", ([
		"north" :  __DIR__"aofu_zoulang2",
		"south" :  __DIR__"aofu_dayuan",
	]));
	set("objects", ([
		__DIR__"npc/aobai" : 1,
		__DIR__"npc/yahuan_a" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("ao bai", environment(me))) && dir == "north")
		return notify_fail("���������ȵ��������̵ģ���Ҫ���\n\n");
	return ::valid_leave(me, dir);
}
