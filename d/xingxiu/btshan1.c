inherit ROOM;

void create()
{
        set("short", "����ɽׯ");
        set("long", @LONG
�����ǡ�������ŷ���������ĵط�������ʲô����Ҳû�С�
LONG);
        set("exits", ([ 
            	"eastdown" : __DIR__"btshan",
        ]));
        set("objects", ([
            	"/clone/beast/qingshe" : 2,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiu");

        setup();
        replace_program(ROOM);
}
