inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������С��Ķ��֡��ϱ��и������̣����洫����������
�����������Ϸ��ǻ����ĸ�ڣ�����������С·����ɽ��
LONG);
        set("outdoors", "baituo");
        set("exits", ([
                "west"      : __DIR__"xijie",
                "east"      : __DIR__"gebi",
                "south"     : __DIR__"datiepu",
                "northeast" : __DIR__"xiaolu1",
        ]));
        set("objects",([
                __DIR__"npc/playboy" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
