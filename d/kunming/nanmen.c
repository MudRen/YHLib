inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����������������ţ��߸ߵĳ�¥��д�Ŵ�����������
�֣��ɴ���ȥ�����ǵ���ˣ��������ŵ��˺��٣�ֻ��Щ����
��ʱ�������ʵ������������
LONG);
        set("outdoors", "kunming");

        set("exits", ([
                "south" : __DIR__"htroad1",
                "north" : __DIR__"nandajie2",
        ]));
        set("objects", ([
                "/d/beijing/npc/ducha" : 1,
                "/d/city/npc/bing" : 4,
        ]));
        setup();
        replace_program(ROOM);
}
