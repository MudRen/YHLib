inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����һ����᫵�ɽ·����ӵ�������Ͳ�������ȥ�ˡ�ɽ
·�����Ӳݴ�����·��ʼԽ��Խ���ߡ�
LONG);
        set("exits", ([
                "north" : __DIR__"nroad6",
                "south" : __DIR__"nroad1",
        ]));
        set("objects",([
                "/clone/quarry/ying" : 1,
        ]));
        set("outdoors", "xuedao");
        setup();
        replace_program(ROOM);
}

