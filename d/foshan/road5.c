inherit ROOM;

void create()
{
        set("short", "�ּ��");
        set("long", @LONG
������һ���ּ�С���������������ѡ�����ɽ��ï�ܣ���
�����棬����·�˾����˵ض��Ƿǳ���С�ġ�
LONG);
	set("outdoors", "foshan");
	set("exits", ([
	        "east"      : __DIR__"road6",
	        "northwest" : __DIR__"road4",
	]));
	setup();
	replace_program(ROOM);
}

