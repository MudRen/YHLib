inherit ROOM;

void create()
{
        set("short", "���̲");
        set("long", @LONG
��ǰ��һ���޼ʵĸ��̲��û��·�꣬Ҳû��һ�����ˣ���
�Եúܸߣ�Զɽ��ѩ����ӥ���裬������ãã���֮�ϣ����ƺ�
��·�ˡ�
LONG);
        set("exits", ([
                "east" : __DIR__"gebitan5",
                "west" : __DIR__"shanjiao", 
                "north" : __DIR__"gebitan5",
                "south" : __DIR__"gebitan4",
        ]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
        set("outdoor", "mingjiao");
        setup();
        replace_program(ROOM);
}
