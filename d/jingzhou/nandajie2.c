inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
������һ�������Ľֵ��ϣ����ϱ���ͷ���졣�ϱ����ϳ�
�ţ�����ͨ�������ģ�������һ�ҹ˿��ڶྣ�ݵı����⣬��
���Ǿ������֣����������Ǿ���Ҫ�أ����Ա��������ͻ����
LONG);
        set("outdoors", "jingzhou");
	set("exits", ([
                "east" : __DIR__"lcmen",
                "south" : __DIR__"jznanmen",
                "west" : __DIR__"bqkumen",
		"north" : __DIR__"nandajie1",
		"westdown" : __DIR__"lydao4",
	]));
        set("objects", ([
                "/d/beijing/npc/old1" : 1,
                "/d/beijing/npc/boy2" : 1,
        ]));
        setup();
        replace_program(ROOM);
}