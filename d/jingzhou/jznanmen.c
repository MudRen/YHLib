inherit ROOM;

void create()
{
        set("short", "��������" );
        set("long", @LONG
���������ݵ����ţ������������Ǿ���Ҫ�أ���˳�ǽ��
ʵ�ޱȣ���¥�߸��������ɴ����ϣ���ȥ���ϵ�·�������Ǳ�
ɽ��·Զ���ܲ����ߣ���ɵö��ע��һЩ��
LONG);
        set("objects", ([
                "/d/city/npc/bing" : 4,
                "/d/beijing/npc/ducha" : 1,
                "/clone/npc/walker" : 1,
        ]));
        set("exits", ([
                "north" :__DIR__"nandajie2",
                "south" :__DIR__"nanshilu",
        ]));

        set("outdoors", "jingzhou");

        setup();
        replace_program(ROOM);
}

