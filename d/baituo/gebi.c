inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�������ٽ�ɳĮ�ĸ��̲���������̡�������һ���޼ʵ�
��ɳĮ�����������Կ���һ��С��
LONG);
        set("outdoors", "baituo");
        set("no_clean_up", 0);
        set("exits", ([
                "east" : "/d/xingxiu/shamo10",
                "west" : __DIR__"dongjie",
        ]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
