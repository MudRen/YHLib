inherit ROOM;

void create()
{
	set("short", "�����ǰ");
	set("long", @LONG
����һ����ۣ���ǰ����д��������������֣�����һ��
��ˮ������С����������������ʵ���������Եĺõط���
LONG);
	set("objects", ([
	        __DIR__"npc/xiaodaogu" : 2,
	]));
	set("outdoors", "dali");
	set("exits", ([
	        "north" : __DIR__"yuxuguan",
	        "south" : __DIR__"hudiequan",
	]));
	setup();
	replace_program(ROOM);
}

