inherit ROOM;

void create()
{
        set("short", "��Ա����");
        set("long", @LONG
��������ϷԺ����Ա����Ϣ�ĵط����ü��Ŵ�ռ�˷���
�Ĵ�룬�����е�Ů���·����߰��㣬�����������е�Ů�ľ�
����һ��˯�������ǽ���м������ǵĻ���
LONG);

        set("exits", ([
                "south" : __DIR__"xiyuan",
        ]));
        set("objects", ([
        	"/d/beijing/npc/kid1" : 2,
        ]));

        setup();
        replace_program(ROOM);
}
