inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����ͨ��ũ�ң�����û��ʲô�����İ��衣ǽ�߰ڷ���һ
Щũ�ߣ�����ֻ���ıڽԿգ�����������ԣ�� 
LONG);

        set("exits", ([
                "south" : __DIR__"cun4",
                "west" : __DIR__"minju8",
        ]));
        set("objects", ([
                __DIR__"npc/cuilan": 1,
        ]));

        setup();
        replace_program(ROOM);
}
