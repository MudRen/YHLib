inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����ͨ��ũ�ң�����û��ʲô�����İ��衣ǽ�߰ڷ���һ
Щũ�ߣ�����ֻ���ıڽԿգ�����������ԣ�� 
LONG);

        set("exits", ([
                "south" : __DIR__"cun3",
        ]));
        set("objects", ([
                __DIR__"npc/cunfu": 2,
        ]));

        setup();
        replace_program(ROOM);
}
