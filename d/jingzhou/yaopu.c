inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
������һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�
ҩ���ϵļ��ٸ�С������ɢ�������ġ���ҽ���Ӷ������ڲ輸
�ԣ����Ժ��Ų裬��Ҳ������һ�ۡ�һ��С���վ�ڹ�̨����
���Ź˿͡�
LONG);
	set("objects", ([
		__DIR__"npc/huatuo" : 1,
		__DIR__"npc/huoji" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"beidajie2",
	]));

	setup();
	replace_program(ROOM);
}

