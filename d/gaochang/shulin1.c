inherit ROOM;

void create()
{
        set("short", "�߲��Թ�");
        set("long", @LONG
������������ĳ�������ǰ����������������Թ�֮
�ڲ����㼣ָ�����㲻֪��Ҫ������·�ߡ�����ϸ����������
���׺�ǰ������·�϶��е������㼣��
LONG);

        set("exits", ([
                "west" : __DIR__"shulin" + (random(10) + 2),
                "east" : __DIR__"shulin2",
                "north" : __DIR__"shulin" + (random(10) + 2),
                "south" : "/d/shenfeng/caoyuan7",
        ]));

        set("outdoors", "gaochang");
        set("objects", ([
                __DIR__"npc/ghost" : 3,
        ]));
        setup();
        replace_program(ROOM);
}

