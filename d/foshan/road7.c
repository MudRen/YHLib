inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
������һ���ּ�С���������������ѡ����������������
ɽ������ͨ�������
LONG);
	set("objects", ([
	   	__DIR__"obj/shuzhi": 1,
	]));
	set("outdoors", "foshan");
	set("exits", ([
	    	"west" : __DIR__"road6",
	    	"east" : __DIR__"westgate",
	]));
	setup();
	replace_program(ROOM);
}

