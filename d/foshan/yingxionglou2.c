inherit ROOM;

void create()
{
	set("short", "Ӣ��¥");
	set("long", @LONG
Ӣ�۾�¥�����νྻ�����п������κ��ݣ�ʮ���Ǹ��̴�
�֡�������Ը��ɽ��ȫ����
LONG);
	set("objects", ([
	        __DIR__"npc/pang": 1,
	        __DIR__"npc/shou": 1,
	]));
	set("exits", ([
	        "down" : __DIR__"yingxionglou",
	]));
	setup();
	replace_program(ROOM);
}

