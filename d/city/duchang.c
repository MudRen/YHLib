inherit ROOM;

void create()
{
	set("short", "�ĳ�");
	set("long", @LONG
�����Ƕĳ��Ĵ��ã����ܵķ����ﴫ����ߺ������ĶĲ�
��������ĳ���ģ���㲻�Ϻܴ󣬵��ĵ�����ȴ����ȫ������
Ҳ�ǳ��ܵ���
LONG );
	set("objects", ([
		CLASS_D("shenlong") + "/pang" : 1,
                "/d/beijing/npc/duke" : 2,
                "/d/beijing/npc/haoke1" : 2,
	]));
	set("exits", ([
		"west" : __DIR__"daxiao",
		"up"   : __DIR__"duchang2",
		"north": __DIR__"bet",
		"east" : __DIR__"nandajie1",
	]));
	setup();
        replace_program(ROOM);
}

