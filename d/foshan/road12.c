inherit ROOM;

void create()
{
        set("short", "�ּ��");
        set("long", @LONG
������һ���ּ�С���������������ѡ�����ɽ��ï�ܣ���
�����棬����·�˾����˵ض��Ƿǳ���С�ġ�
LONG);
	set("objects", ([
	        "/clone/beast/dushe": 1,
	]));
	set("outdoors", "foshan");
	set("exits", ([
	        "northwest" : __DIR__"road10",
	]));
	setup();
	replace_program(ROOM);
}

