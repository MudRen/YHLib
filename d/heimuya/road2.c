inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
������һ����������Ļ���·�ϡ�������һ��С�߸ڣ���
���ն񣬿��öϾ��������������Կ���ƽ���ݳǡ�
LONG);
        set("outdoors", "heimuya");
        set("exits", ([
            	"south" : __DIR__"road1",
            	"east" : __DIR__"pingdingzhou",
        ]));
        set("objects", ([
                "/d/beijing/npc/tiaofu" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
