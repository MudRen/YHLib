inherit ROOM;

void create()
{
        set("short", "���޺�");
        set("long", @LONG
���������޺��ߡ�˵�Ǻ�����ʵ��Ƭ���������󣬵���ʮ
���ն�����ͨ�����޺������������һ�����̵�ʯͷ·��
LONG);
        set("objects", ([
                __DIR__"npc/haoshou" : 1,
        ]));
        set("exits", ([
             "southeast" : __DIR__"xxh2",
             "northeast" : __DIR__"xxh5",
             "west"      : __DIR__"xxh6",
        ]));
        set("outdoors", "xingxiu");
        setup();
        replace_program(ROOM);

}

