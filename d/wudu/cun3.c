inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
����С���ʯ��·�ϣ����Զ�������ʯ���ɵķ��ݡ������ﾲ��
�ĵģ����������ˣ�ż������һ�������С� 
LONG );
        set("outdoors", "wudujiao");

        set("exits", ([
                "east" : __DIR__"cun4",
                "west" : __DIR__"cun2",
                "north" : __DIR__"minju2",
        ]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));

        setup();
}
