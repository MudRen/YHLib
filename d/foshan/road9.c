inherit ROOM;

void create()
{
        set("short", "�ּ��");
        set("long", @LONG
������һ���ּ�С���������������ѡ�����ɽ��ï�ܣ���
�����棬����·�˾����˵ض��Ƿǳ���С�ġ�
LONG);
	set("objects", ([
	   	__DIR__"obj/hua2": 1,
	]));
	set("outdoors", "foshan");
	set("exits", ([
	    	"west" : __DIR__"road8",
	    	"east" : __DIR__"road10",
	]));
	setup();
	replace_program(ROOM);
}

