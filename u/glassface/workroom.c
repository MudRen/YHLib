inherit ROOM;

void create()
{
        set("short", "ڤ��ռ�");
        set("long", @LONG
������ڤ��ռ䡣�ÿտ��ĵط���һƬ��ãã��ʲôҲû�С�
LONG );
        set("exits", ([
                "out"  : "/d/wizard/guest_room",
        ]));
        set("valid_startroom", 1);
        set("sleep_room", 1);
        setup();
        replace_program(ROOM);
}

