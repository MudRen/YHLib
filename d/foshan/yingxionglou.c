inherit ROOM;

void create()
{
	set("short", "Ӣ��¥");
	set("long", @LONG
Ӣ��¥���Ƿ�ɽ������ϰ��졹�����ϵļ�ҵ����¥����
�νྻ�����п������κ��ݣ�ʮ���Ǹ��̴�֡���ɽ�ش���ͨ
Ҫ�أ�����Է����˻��治�١�
LONG);
	set("objects", ([
	        __DIR__"npc/fengqi": 1,
	]));
	set("exits", ([
	        "north" : __DIR__"street4",
	        "south" : __DIR__"majiu",
	        "up"    : __DIR__"yingxionglou2",
	]));
	setup();
	replace_program(ROOM);
}

