// /guanwai/songlin2.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����һƬï�ܵ����֣����ҵ���������б��ɽ���ϡ��������������������
������֦�½��ᣬ������ѹ�����ߺ�İ�ѩ����������ѩ�٣��������ߡ�
LONG );
        set("exits", ([
                "west"    : __DIR__"songlin4",
                "north"    : __DIR__"songlin3",
                "south"    : __DIR__"fengdi",
                "east"  : __DIR__"songlin2",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "guanwai");
        setup();
        replace_program(ROOM);
}
