// Room: /u/wfoxd/wroom.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ȥɽׯ���ߵ����ȡ�����Կ��������Ͼ����ޱȵĵ�̻���
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  		"north" : __DIR__"chuchangshi",
  		"south" : __DIR__"xiaokf",
  		"east" : __DIR__"ygc",
  		"west" : __DIR__"xiaohuayuan",
	]));

	setup();
	replace_program(ROOM);
}
