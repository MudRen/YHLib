inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�����ڴ������������е�ʯ���ϡ�·�߳�ľ���죬΢��ϰ
ϰ��ʮ����ˬ��·����һ������͸����С����ˮ�����㣬ӳӰ
��䡣����ͨ���������������Ǹ���԰��
LONG);
        set("objects", ([
                "/clone/quarry/he": 1,
        ]));
        set("outdoors", "dali");
        set("exits", ([
                "east" : __DIR__"tingyuan",
                "west" : __DIR__"wfdating",
        ]));
        setup();
        replace_program(ROOM);
}
