inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������书��Ķ��ţ���ǰ��ǽ���ʣ�ǽ�ϵļ��������
������������ȥ��������������ǽ�����������׹⣬�ƺ��Ǳ�
��������Ĺ⡣���������Ŷ����������֣��ſ�վ��һЩ�ٱ�
���ֱֳ��������������������ǡ�
LONG);
        set("outdoors", "wugong");
        set("exits", ([
                "east" : __DIR__"guandao2",
                "west" : __DIR__"dongjie",
        ]));
        set("objects", ([
                __DIR__"npc/bing" : 2,
                "/clone/npc/xunbu" : 1,
                "/d/beijing/npc/ducha" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
