// Room: /u/wfoxd/xiaokf.c

inherit ROOM;

void create()
{
	set("short", "���ķ�ɽׯС�ͷ���");
	set("long", @LONG
�����ɽׯ��С�ͷ�������һ�㣬�Ǹ�һЩ������ɫס��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"north" : __DIR__"wroom",
	]));

	setup();
	replace_program(ROOM);
}
