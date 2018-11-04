inherit ROOM;

void create()
{
	set("short", "衙门正厅");
	set("long", @LONG
只见堂上东西有两根楹住，挂着一幅对联，但是你无心细
看。正墙上悬挂一个横匾，上书“明镜高悬”四个金光闪闪的
大字。知府正坐在文案后批阅文书，师爷随侍在后。
LONG);
	set("exits", ([
		"north" : __DIR__"jzyamen",
		"south" : __DIR__"houyuan",
	]));
	set("objects", ([
		__DIR__"npc/jing" : 1,
		
	]));

	setup();
	replace_program(ROOM);
}

