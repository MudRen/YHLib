inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
������һ����ɽ��С·��ɽ·��Χ����Ƨ����������ӰҲ
û�С��������Ƕ��֣���������һ��صء�
LONG);
        set("outdoors", "baituo");
        set("exits", ([
                "northup"   : __DIR__"xiaolu2",
                "southwest" : __DIR__"dongjie",
                "northeast" : __DIR__"fende",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
