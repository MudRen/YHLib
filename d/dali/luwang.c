inherit ROOM;

void create()
{
	set("short", "³����");
	set("long", @LONG
���������Ჿ��³�������Ჿ��̨�ģ��������и�����Խ�ݡ�
����һ������ɽ���ϵ�С�򣬶���ͱ����Ǹ��ʵ�Ⱥɽ������������
�����ɼ���ׯ�ͳ���
LONG);
	set("outdoors", "dali");
	set("exits", ([
	        "west"  : __DIR__"feilihu",
	        "east"  : __DIR__"yulin",
	        "south" : __DIR__"shuitian",
	        "north" : __DIR__"zhulou3",
	]));
	set("objects", ([
                __DIR__"npc/tshangfan": 1,
                "/clone/npc/walker" : 1,
	]));
	setup();
	replace_program(ROOM);
}

