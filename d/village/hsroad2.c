inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
������һ����ʯ����ϣ��ϱ���Լ�ɼ��������ǵĳ�ǽ������������
·�ֲ�ͨ��ɽ�
LONG);
        set("outdoors", "village");
        set("exits", ([
                "south"     : __DIR__"hsroad1",
                "northwest" : __DIR__"hsroad3",
                "northeast" : "/d/huashan/jzroad1",
        ]));

        setup();
        replace_program(ROOM);
}

