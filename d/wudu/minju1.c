inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����ͨ��ũ�ң�����û��ʲô�����İ��衣ǽ�߰ڷ���һ
Щũ�ߣ�����ֻ���ıڽԿգ�����������ԣ�� 
LONG);

        set("exits", ([
                "north" : __DIR__"cun2",
        ]));
        set("objects", ([
                __DIR__"npc/cunmin": 1,
                __DIR__"npc/cunfu": 1,
        ]));

        setup();
        replace_program(ROOM);
}
