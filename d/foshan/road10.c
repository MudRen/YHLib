inherit ROOM;

void create()
{
	set("short", "�ּ��");
	set("long", @LONG
������һ���ּ�С���������������ѡ�����ɽ��ï�ܣ���
�����棬����·�˾����˵ض��Ƿǳ���С�ġ�
LONG);
	set("objects", ([
	        __DIR__"obj/hua3": 1,
	]));
	set("outdoors", "foshan");
	set("exits", ([
	        "northeast" : __DIR__"road11",
	        "southeast" : __DIR__"road12",
	        "west"      : __DIR__"road9",
	]));
	setup();
	replace_program(ROOM);
}

