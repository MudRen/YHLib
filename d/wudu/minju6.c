inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����ͨ��ũ�ң�����û��ʲô�����İ��衣ǽ�߰ڷ���һ
Щũ�ߣ�����ֻ���ıڽԿգ�����������ԣ�������ƺ���һ��СԺ�� 
LONG);

        set("exits", ([
                "northwest" : __DIR__"cun6",
                "south" : __DIR__"minju10",
        ]));
        set("objects", ([
                __DIR__"npc/girl": 1,
        ]));

        setup();
        replace_program(ROOM);
}
