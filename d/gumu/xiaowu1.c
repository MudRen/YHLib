
inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
���߽���һ��С�ݣ������С������һ��С���Ų��±��
�����ˡ����Ϻ����м���������������Ĵֲ�����ϴ�ĸɸɾ�
����
LONG
        );

        set("exits", ([
                "northwest" : __DIR__"xiuxishi",
                "east" : __DIR__"xiaoting",
        ]));

        set("objects", ([
                __DIR__"obj/fengmi" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
