inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ
���ϵļ��ٸ�С������ɢ�������ġ�һ��С���վ�ڹ�̨����
���Ź˿͡���̨������һ�ŷ��ƵĹ�档
LONG);
	set("objects", ([
		__DIR__"npc/huoji" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"dongdajie2",
	]));
	setup();
	replace_program(ROOM);
}
