inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������Ҵ�
���������������һЩС��̯���ƺ���һ�����С��ϱ�ͨ�������ųǡ�
LONG );
        set("outdoors", "village");
        set("exits", ([
                "north" : __DIR__"hsroad2",
                "south" : "/d/luoyang/guandaon4",
        ]));
        set("objects", ([
                __DIR__"npc/girl" : 4,
        ]));

        setup();
        replace_program(ROOM);
}
