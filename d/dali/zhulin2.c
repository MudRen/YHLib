inherit ROOM;

void create()
{
	set("short","�����");
	set("long",@LONG
����һ��Ƭï�ܵ����֣�������ɽ���Ǹ�ï�ܵ���Ҷ�֣�������
�ࡣ�о����̨�������������������ס����£���׽�á�¹��С�ޣ�
�������������ɽ��׽��Щ�����ޡ�
LONG);
	set("objects", ([
	   	__DIR__"npc/lieshou" : 2,
	]));

	set("outdoors", "dali");
	set("exits",([
	        "north" : __DIR__"hexi",
	        "west"  : "/d/wudu/cun8",
	]));
	setup();
	replace_program(ROOM);
}

