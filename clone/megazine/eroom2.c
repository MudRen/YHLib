// Room: /u/wfoxd/eroom2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ȥɽׯ���ߵ����ȡ�����Կ��������Ͼ����ޱȵĵ�̻���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"east" : __DIR__"proom",
  		"south" : __DIR__"eroom",
	]));

	setup();
	replace_program(ROOM);
}
