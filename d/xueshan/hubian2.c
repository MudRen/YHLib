inherit ROOM;

void create()
{
        set("short", "����С·");
        set("long", @LONG
����ʥ���ߵ�С·������Խ������������ż���а�ɫˮ
���Ӻ���ˮ������ȦȦ������
LONG );
        set("outdoors", "xuedao");
        set("exits", ([
                "east" : __DIR__"hubian3",
                "west" : __DIR__"hubian1",
        ]));
        setup();
        replace_program(ROOM);
}
