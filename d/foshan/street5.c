inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
��ɽ��ֶ������������������ţ�����һ�¸�ǽ��ǽ��
���Ƿ����Ͽ��ġ�Ӣ�۵䵱�����ǳ�����עĿ��
LONG);
	set("objects", ([
	        "/clone/quarry/gou2" : 1,
	        __DIR__"npc/jiading" : 2,
	]));
	set("outdoors", "foshan");
	set("exits", ([
	        "south" : __DIR__"dangpu",
	        "west"  : __DIR__"street4",
	        "east"  : __DIR__"eastgate",
	]));
	setup();
	replace_program(ROOM);
}

