inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
��ɽ�Թ������ɡ����¡����ڲ��������Ĵ��򣬶˵�����
���︷�����ܷ�����һ����ֺ�ب�������ϱ������ţ�ͨ����
�������߳����ſ�����ɴ���ԭ��
LONG);
	set("objects", ([
	        "/d/city/npc/liumangtou": 1,
	]));
	set("outdoors", "foshan");
	set("exits", ([
	        "north" : __DIR__"northgate",
	        "south" : __DIR__"southgate",
	        "west"  : __DIR__"street2",
	        "east"  : __DIR__"street4",
	]));
	setup();
	replace_program(ROOM);
}

