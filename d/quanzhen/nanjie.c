inherit ROOM;

void create()
{
        set("short", "�Ͻ�");
        set("long", @LONG
�������书���Ͻ֣�˵�ǽ֣�������һ��С��ͬ���ѡ�·
��һ����Ҳû�С��ֵľ�ͷ��һ��С�š�������������������
����������ˡ�
LONG);
        set("outdoors", "wugong");
        set("exits", ([
                "north" : __DIR__"zhongxin",
                "southeast" : __DIR__"fu-cemen",
        ]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
