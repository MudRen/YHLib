inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
СϪ���ɽ·����Ϫ��һ��Сʯ�š�Ϫ��ũ��С������Ϸ���֡�
�����Ȥ���㲻����Ȼ��̾��һʱ������Զ�ܽ���֮�⡣���ϱ㵽��
�����ã����¾��������á�
LONG);
        set("exits", ([
            "south"   : __DIR__"shanlu4",
            "northdown" : __DIR__"fajinsi",
        ]));
        set("objects", ([
            __DIR__"npc/boy" : 3,
        ]));
        set("outdoors", "hangzhou");
        set("max_room", 4);
        setup();
        replace_program(ROOM);
}
