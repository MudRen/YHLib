inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ɽ�������ѵĶ��ڣ�����ɽ�������ڶ�ǰ�����ص�
Ѳ���ţ��ر�����ɭ�ϡ�
LONG);
        set("outdoors", "baituo");
        set("exits", ([
                "north" : __DIR__"dongnei",
                "south" : __DIR__"xiaolu4",
        ]));

        set("objects",([
                __DIR__"npc/shanzei2" : 2,
        ]));

        setup();
        replace_program(ROOM);
}
