inherit ROOM;

void create()
{
        set("short", "���޺�");
        set("long", @LONG
���������޺��ߡ�˵�Ǻ�����ʵ��Ƭ���������󣬵���ʮ
���ն�����ͨ�����޺������
LONG );
        set("objects", ([
                CLASS_D("xingxiu") + "/tianlang" : 1,
        ]));
        set("exits", ([
             "southwest" : __DIR__"xxh2",
             "northwest" : __DIR__"xxh5",
        ]));
        set("outdoors", "xingxiu");
        setup();
        replace_program(ROOM);
}


