inherit ROOM;

void create()
{
	set("short", "С·");
        set("long", @LONG
������һ����ɽ��С·��ɽ·��Χ����Ƨ����������ӰҲ
û�С���Χ����ɽ�����˳�û����·���С�Ľ�����
LONG);
	set("outdoors", "baituo");
	set("exits", ([
		"northup"   : __DIR__"xiaolu3",
		"southdown" : __DIR__"xiaolu1",
	]));
	set("objects", ([
		__DIR__"npc/man" : 1,
	]));

	setup();
	replace_program(ROOM);
}
