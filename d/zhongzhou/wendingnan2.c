inherit ROOM;

void create()
{
	set("short", "�Ķ��Ͻ�");
	set("long", @LONG
���������Ķ��Ͻ֣����Ľֵ������˲�������һ������
���������һ�Ҳ�¥���ɽ��������㿴���ܾ����е㲻�Ծ���
LONG);
	set("no_clean_up", 0);
	set("objects", ([
  		__DIR__"npc/qiying" : 1,
	]));
	set("exits", ([
  		"east" : __DIR__"maodun",
  		"north" : __DIR__"wendingnan1",
  		"west" : __DIR__"chalou",
  		"south" : __DIR__"wendingnan3",
	]));

	set("outdoors", "zhongzhou");

	setup();
	replace_program(ROOM);
}
