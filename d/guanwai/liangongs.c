// liangongs.c ������

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
���������������������������һЩ�����߳��õ�ľ�ˡ�
LONG );
        set("exits", ([
                "north" : __DIR__"liangong",
        ]));
        set("for_family", "�������");
        setup();
	replace_program(ROOM);
}

