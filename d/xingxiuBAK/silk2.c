inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
����һ����ԭ������֮����̵����������������ɽ����
����������º�����һ���������������ԭ��������ͨ������
LONG);

        set("exits", ([
                "east" : __DIR__"silk1",
                "west" : "/d/mingjiao/westroad1",
                "northwest" : __DIR__"silk3",
        ]));

        set("outdoors", "xiyu");

        setup();
        replace_program(ROOM);
}

