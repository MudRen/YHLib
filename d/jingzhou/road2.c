inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����ʯ�����������Լ���Կ������ݳǵĳ�ǽ����
����ȥ��ֻ��Ⱥɽ����������̣���֪ͨ�����
LONG);
        set("exits", ([
                "northeast" : __DIR__"road1",
                "southwest" : __DIR__"road3",
        ]));

        set("no_clean_up", 0);
        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

