inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����һƬï�ܵ����֣����ҵ���������б��ɽ���ϡ��������������������
������֦�½��ᣬ������ѹ�����ߺ�İ�ѩ����������ѩ�٣��������ߡ�
LONG );
        set("exits", ([
                "southeast" : __DIR__"xuedi1",
                "west"      : __DIR__"songlin1",
                "north"     : __DIR__"songlin1",
                "south"     : __DIR__"songlin1",
                "east"      : __DIR__"songlin2",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "guanwai");
        setup();
        replace_program(ROOM);
}
