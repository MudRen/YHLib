inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
����һ����ʯ������������ͨ�������������ݡ�������
Լ���Կ��������ǵĳ�ǽ����������Сɽ��
LONG );
        set("exits", ([
                "east" : __DIR__"xxroad1",
                "northwest" : "/d/lanzhou/caroad8",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "lanzhou");
        setup();
        replace_program(ROOM);
}

