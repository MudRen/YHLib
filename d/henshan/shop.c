inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
�����Ǻ����سǵ�һ��С�꣬��Щ�򵥵���ʳ��ר��׬��
Щ�ο͵�Ǯ��
LONG);
	set("exits", ([
		"north" : __DIR__"hengyang1",
		"up"    : __DIR__"huiyan",
	]));

	set("objects", ([
	        __DIR__"npc/xiaoer" : 1,
	]));

	setup();
	replace_program(ROOM);
}

