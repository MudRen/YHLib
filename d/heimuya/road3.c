inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
������һ����������Ļ���·�ϡ�������ȥ���������Կ�
��ƽ���ݡ������������ǿ쵽�ˡ�
LONG);
        set("outdoors", "heimuya");
        set("exits", ([
                "east" : "/d/beijing/ximenwai",
                "west" : __DIR__"pingdingzhou",
        ]));
        setup();
        replace_program(ROOM);
}
