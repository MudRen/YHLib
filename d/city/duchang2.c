inherit ROOM;

void create()
{
	set("short", "�ĳ�");
	set("long", @LONG
�����Ƕĳ��Ķ�¥������������ͨ��ͬ�ķ��䡣���ܵ�
�ķ��ﴫ����ߺ������ĶĲ������ĳ���ģ���㲻�ϴ󣬵���
������ȴ����ȫ������Ҳ�ǳ��ܵ�����������ϵĸ��и�ɫ
���˼�����һ��
LONG );
	set("exits", ([
		"east"  : __DIR__ "eproom",
		"west"  : __DIR__ "wproom",
		"south" : __DIR__ "sproom",
		"north" : __DIR__ "nproom",
		"down"  : __DIR__"duchang",
	]));
        set("objects", ([
                "/d/beijing/npc/duke" : 2,
                "/d/beijing/npc/dipi" : 1,
        ]));
	setup();
	replace_program(ROOM);
}

