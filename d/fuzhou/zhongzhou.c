// Room: /d/fuzhou/zhongzhou.c
// Date: May 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ź�Խ����������ƽ��������ˮ�����֡�����Ϊһ
С��������ˮ���˼ҡ�
LONG );
	set("exits", ([
		"north" : __DIR__"nanmen",
                "south" : __DIR__"puxian",
	]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}

