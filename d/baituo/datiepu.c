inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǰ���ɽׯ�����һ�Ҵ����̣���ʱ�����洫������
���˵�����������æ�Ŵ������Ʊ����������������͡�
LONG);
        set("exits", ([
                "north" : __DIR__"dongjie",
        ]));
        set("objects", ([
                __DIR__"npc/smith" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
