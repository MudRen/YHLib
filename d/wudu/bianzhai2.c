inherit ROOM;

void create()
{
        set("short", "��կ����");
        set("long", @LONG
���������置�ؽ磬ֻ����ɽ��ˮ�㣬�羰����ԭ����ͬ����
����·�ϣ���ʱ������������Ů��·����Ұ���ظ����裬��ʱ������
���泩����Ը���ϴ��硣
LONG);
        set("outdoors", "wudujiao");

        set("exits", ([
                "east" : __DIR__"bianzhai1",
                "south" : __DIR__"bianzhai3",
        ]));
        set("objects", ([
                 __DIR__"npc/youngboy": 1,
        ]));

        setup();
        replace_program(ROOM);
}

