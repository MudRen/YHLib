inherit ROOM;

void create()
{
        set("short", "�᷿");
        set("long", @LONG
���Ǿ������֮Ů��������Ĺ뷿������һ���Ǹ����µ�
��ױ���������һ���ͭ����һЩ��֬ˮ�ۡ�
LONG);
        set("exits", ([
               "west"    : __DIR__"changlang3",
        ]));

        set("objects", ([
                __DIR__"npc/lve" : 1,
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
