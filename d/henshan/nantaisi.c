inherit ROOM;

void create()
{
        set("short", "��̨��");
        set("long", @LONG
��̨��Ϊ�������滳�õĵ���ʯͷϣǨ�ĵ�������������
������ʯͷ����Ĺ����������е�������ͨ�ģ�Ȫ�����ˣ���
���׷ɣ�ɽ�紵��ʱ��ҶϤ�������ȥ����
LONG);
        set("exits", ([
                "northdown"  : __DIR__"shanlu9",
        ]));

        set("objects", ([
                __DIR__"npc/xiangke" : 4,
        ]));                    

        set("outdoors", "henshan");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

