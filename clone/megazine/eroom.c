// Room: /u/wfoxd/eroom.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ȥɽׯ���ߵ����ȡ�����Կ��������Ͼ����ޱȵĵ�̻���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"north" : __DIR__"eroom2",
  		"west" : __DIR__"ygc",
	]));

	setup();
	replace_program(ROOM);
}
