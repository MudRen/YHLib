// Room: /d/fuzhou/ximen.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����Ǹ������š������������ɴ���ԭ��
LONG );
	set("exits", ([
                "east" : __DIR__"ximendajie",
                "west" : __DIR__"fzroad11",
	]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}

