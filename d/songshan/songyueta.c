
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
��������Ϊ����ʽש�����ߴ�ʮ���ɣ�����ʮ���棬����
�˷����ţ�ʮ���������ɲ�����ս����������ס�
LONG );
	set("exits", ([
		"east" : __DIR__"songyuesi",
	]));
	set("objects", ([
		__DIR__"npc/ding" :1,
	]));
	set("outdoors", "songshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

