//create by rcwiz 2003

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "��������");
	set("long", @LONG
���������ţ��������Ϸ����ż����������֡���ǽ�����ż��Źٸ�
��ʾ��һ��·����ͨ�������ڤ�塣
LONG );
	set("exits", ([
		"west"      : "/d/xuanminggu/xiaolu1",
		"southeast" : __DIR__"biaoqiyin",
	]));
	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}

