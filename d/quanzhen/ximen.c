inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������书������ţ���ǰ��ǽ���ʣ�ǽ�ϵļ��������
������������ȥ��������������ǽ�����������׹⣬�ƺ��Ǳ�
��������Ĺ⡣���������������������֣��ſ�վ��һЩ�ٱ�
�����������������ǡ��������򱱾�������ɽ���ˡ�
LONG);
        set("outdoors", "wugong");
        set("exits", ([
                "east" : __DIR__"xijie",
                "northeast" : __DIR__"shanlu1",
        ]));

        set("objects", ([
                __DIR__"npc/bing" : 2,
                "/clone/npc/xunbu" : 1,
                "/d/beijing/npc/ducha" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
