inherit ROOM;

void create()
{
	set("short", "����ɽ·");
	set("long", @LONG
�����ڶ��ϵ�һɽ������ɽ�ϡ�����Ӷ��洵�������ż�
�ֺ��⡣�ϱ߾��������ĺ���Ȫ���ˡ�
LONG);
	set("exits", ([
                "northdown" : __DIR__"qzroad4",
                "south" : __DIR__"beimen",
	]));
        set("objects", ([
		"/clone/quarry/tu" : 2
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

