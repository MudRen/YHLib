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
	        "southwest" : __DIR__"road3",
	        "southeast" : __DIR__"road5",
	]));
	setup();
	replace_program(ROOM);
}
