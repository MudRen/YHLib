inherit ROOM;

void create()
{
	set("short", "��լ");
	set("long", @LONG
������������լ��ס��֪���ļҾ졣���˵��˾͸�ֹ���ˡ�
LONG );
	set("exits", ([
		"south" : __DIR__"ymzhengting",
	]));
	set("objects", ([
		__DIR__"npc/yuhuan" : 1,
	]));
	setup();
	replace_program(ROOM);
}

