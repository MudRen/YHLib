inherit ROOM;

void create()
{
        set("short", "���������");
        set("long", @LONG
������һ�����õ���ӣ��������Ѿ��������ܳ�һ������
�ˣ���Ժ���Ĵ��и�ϱڣ��Ӳݴ�����Ժ�ӵ�һ������������
������һ���ѿ츯�õ���ܡ�
LONG );
        set("exits", ([
            	"out"      : __DIR__"eastroad3",
        ]));

        set("objects", ([
            	__DIR__"obj/shelf" : 1,
        ]));

        set("no_clean_up", 0);
        setup();

        replace_program(ROOM);
}
