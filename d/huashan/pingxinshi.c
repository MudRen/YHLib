inherit ROOM;

void create()
{
        set("short", "ƽ��ʯ");
        set("long", @LONG
�ٳ�Ͽ��ͷ����������������ϣ��м������ʯ��ǰ��һ����С���
��ʯ�����֡����˻�����ʯ�Ͽ��С�ƽ��ʯ�����֣�ʾ�������վ��Ѿ���
ȥ���ѽ���ƽ��֮;�ˡ���ʱ��������һ�档
LONG );
        set("exits", ([
            "westdown" : __DIR__"baichi",
            "eastup"   : __DIR__"laojun",
        ]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
        set("outdoors", "huashan" );

        setup();
        replace_program(ROOM);
}
