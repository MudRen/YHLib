inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
������һ����ʯ����ϣ��˽�����������ֻ����ʱ������
����ҴҶ�����ԶԶ�����Ѿ����Կ����������ˡ�
LONG);
        set("outdoors", "lanzhou");

        set("exits", ([
                "north" : __DIR__"caroad7",
                "southeast" : "/d/xingxiu/xxroad2",
        ]));

        setup();
        replace_program(ROOM);
}
