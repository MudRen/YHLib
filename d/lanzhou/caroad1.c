inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������
������ҴҶ��������������һЩС��̯�����в�Զ�Ϳ��Ե�
�������ˣ��ϱ�ͨ��������
LONG);
        set("outdoors", "lanzhou");

        set("exits", ([
                "north" : __DIR__"nanmen",
                "south" : __DIR__"caroad2",
        ]));
        set("objects", ([
                "/d/beijing/npc/tiaofu" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
