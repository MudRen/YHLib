inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
������һ������·�ϡ�������ɽ���ؽ磬������Զ�ͽ���
�ӱ��ˡ��������ﲻ��̫ƽʱ�ڣ����ǿ���߰ɡ�
LONG );
        set("outdoors", "heimuya");
        set("exits", ([
                "north" : __DIR__"road1",
                "south" : __DIR__"dukou1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
