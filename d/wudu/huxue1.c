inherit ROOM;

void create()
{
        set("short", "��Ѩ");
        set("long", @LONG
�����Ǹ���������������Ҷ���������ζ�˱ǣ��洦����
��ʣ���޹ǡ���ֻ�������ݵĴ��ϻ������ڶ���������ɹ̫����
LONG);

        set("exits", ([
                "south" : __DIR__"huxue2",
                "out" : __DIR__"milin7",
        ]));
        set("objects", ([
                "/clone/quarry/laohu" : 2,
        ]));

        setup();
        replace_program(ROOM);
}
