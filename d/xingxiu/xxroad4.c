inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
������һ����ɽ�����˹����������᫵�С·�ϣ����ﺮ
���������������������׵����
LONG);
        set("exits", ([
            	"southdown" : __DIR__"tianroad3",
            	"north" : __DIR__"xxroad5",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xingxiu");
        setup();
        replace_program(ROOM);
}
