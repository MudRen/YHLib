inherit ROOM;

void create()
{
	set("short", "���ݳ�");
	set("long", @LONG
���ݳ��Ǳ����Ĵ�ǣ������Ǳ��ұ���֮�ء��������ڴ�פ
���ر����̲��������������ˣ����������𸽽�ɽ�ϵĲݿܡ���
��һ�Ӷӹٱ�����ȥȥ��һ��ɭ������������������������֮
һ����ɽ��
LONG );
	set("exits", ([
		"west"  : "/d/songshan/taishique",
		"east"  : __DIR__"shang_road1",
		"north" : "/d/beijing/road10",
		"south" : __DIR__"yidao3",
	]));
        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 3,
                "/clone/npc/walker" : 1,
        ]));
	set("outdoors", "ruzhou");
	setup();
	replace_program(ROOM);
}
