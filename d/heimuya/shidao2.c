inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
һ·�����½̽��ڰ������ܣ���������ɽ��������һ��ˮ
̲֮ǰ��������һ��ʯ��ͨ��ˮ̲��
LONG);
        set("outdoors", "heimuya");
        set("exits", ([
            	"northdown" : __DIR__"xingxingtan",
            	"south" : __DIR__"shidao1",
        ]));
        set("objects", ([
            	__DIR__"npc/dizi3" : 2,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
