inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����Ǳ������ڵ�һ�����������ּ򵥣������ں����о�
����֮�á�
LONG);
        set("exits", ([
                "east"    : __DIR__"dxdian",
        ]));
        set("sleep_room", 1);
        set("no_clean_up", 0);
        set("no_fight", 1);
        setup();
        replace_program(ROOM);
}
