// Room: /u/wfoxd/wroom2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ȥɽׯ���ߵ����ȡ�����Կ��������Ͼ����ޱȵĵ�̻���
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  		"east" : __DIR__"xiaohuayuan",
	]));

	setup();
	replace_program(ROOM);
}
