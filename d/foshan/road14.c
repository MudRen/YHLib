inherit ROOM;

void create()
{
	set("short", "�ּ��");
	set("long", @LONG
������һ���ּ�С���������������ѡ��������Ȫ�ݳǵ�
���ŵ��ţ������Ͽɴ����Ϲ㶫��
LONG);
	set("objects", ([
	        __DIR__"obj/hua3": 1,
	]));
	set("outdoors", "foshan");
	set("exits", ([
	        "east"      : "/d/quanzhou/westbridge",
	        "southwest" : __DIR__"road13",
	]));
	setup();
	replace_program(ROOM);
}

