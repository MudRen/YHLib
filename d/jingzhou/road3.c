inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����ʯ�������ͨ�����ݡ�������ȥ��ֻ��һ��
��ɽ���ɹŰأ�һƬ��÷羰��
LONG);
        set("exits", ([
                "northeast" : __DIR__"road2",
                "southwest" : __DIR__"road4",
        ]));

        set("no_clean_up", 0);
        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

