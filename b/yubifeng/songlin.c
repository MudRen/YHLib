// /guanwai/songlin1.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����һƬï�ܵ����֣����ҵ���������б��ɽ���ϡ��������������������
������֦�½��ᣬ������ѹ�����ߺ�İ�ѩ����������ѩ�٣��������ߡ�
LONG );
        set("exits", ([
                "west"    : __DIR__"baihe",
                "north"    : __DIR__"songlin1",
                "south"    : __DIR__"songlin1",
                "east"  : __DIR__"song2",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "guanwai");
        setup();
        replace_program(ROOM);
}
