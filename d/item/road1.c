// road1.c С��

inherit ROOM;

void create()
{
        object ob;

	set("short", "С��");
	set("long", @LONG
����һ�����ѵ�С������������ͨ��ɽ�·���Ϲ⻬ƽʵ��������
����������������������ԼԼ���Կ�����ʯ�̾͵Ĺٵ���
LONG );

	set("exits", ([
                "west"   : "/d/suzhou/road5",
                "eastup" : __DIR__"road2",
	]));

        set("objects", ([
                __DIR__"npc/zhang" : 1,
        ]));

	set("outdoors", "suzhou");
	setup();
        replace_program(ROOM);
}
