inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����ڷ�ɽ������һָ�Ĵ󻧣���ҵļҶ���ǣ���ǹ���
�����һ��İ���ֻ������͵����һ����ֺ�ب������·��
һ������������Ĵ��¥��������д�š�Ӣ��¥�����������
�֣����߳��Ŵ�������¥�ﵶ����죬�����������������·
���м��ձ������̣����洫����������������
LONG);
	set("objects", ([
	        "/clone/quarry/gou2" : 2,
	        __DIR__"npc/zhongxiaoer" : 1,
	        __DIR__"npc/zhongsisao"  : 1,
	]));
	set("outdoors", "foshan");
	set("exits", ([
	        "north" : __DIR__"youtiaopu",
	        "south" : __DIR__"yingxionglou",
	        "west"  : __DIR__"street3",
	        "east"  : __DIR__"street5",
	]));
	setup();
	replace_program(ROOM);
}

