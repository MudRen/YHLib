inherit ROOM;

void create()
{
	set("short", "С·");
        set("long", @LONG
������һ����ɽ��С·����������ɽ����û��Ҫ����С�ġ�
LONG);
	set("outdoors", "baituo");
	set("exits", ([
		"northeast" : __DIR__"xiaolu4",
		"southdown" : __DIR__"xiaolu2",
	]));
	set("objects",([
		__DIR__"npc/shanzei1" : 1,
	]));

	setup();
	replace_program(ROOM);
}
