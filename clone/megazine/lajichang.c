// Room: /u/wfoxd/lajichang.c

inherit ROOM;

void create()
{
	set("short", "�ٻ���");
	set("long", @LONG
����һ���ٻ��ң������������ٻ���Ʒ��
LONG	);
	set("exits", ([ /* sizeof() == 1 */
  		"north" : __DIR__"xiaohuayuan",
	]));

	setup();
	replace_program(ROOM);
}
