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
                "north" : __DIR__"caroad1",
                "south" : __DIR__"caroad3",
        ]));
        set("objects", ([
                "/d/beijing/npc/shusheng1" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
