inherit ROOM;

void create()
{
        set("short", "�鷿");
        set("long", @LONG
������ǽ���ƽʱ���ڿ���ĵط������䲻��ֻ��������һ��
�鰸�����߷��˼����飬�����ǽ������������ġ�
LONG);

        set("exits", ([
                "south" : __DIR__"dating",
        ]));

        set("objects", ([
                 __DIR__"obj/book2": 1,
        ]));

        setup();
        replace_program(ROOM);
}

