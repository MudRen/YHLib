inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������һɽ·�ϣ�������һ����Сɽ����ң�������Ϸ�
��ѩɽ�ı�´��ɽǰ����ԼԼ������һ����Ժ��
LONG);
        set("exits", ([
                "west" : __DIR__"nroad3",
                "east" : __DIR__"nroad1",
        ]));
        set("objects", ([
                "/d/wudang/npc/guest" : 1,
        ]));
        set("outdoors", "xuedao");
        setup();
        replace_program(ROOM);
}

