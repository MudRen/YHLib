inherit ROOM;

void create()
{
        set("short",  "С����" );
        set("long", @LONG
�����������������ţ��׳�С���ţ�����������ɫ�˳���
���������οͣ����������ģ�Ҳ����Щ������ʿ��
LONG);
        set("outdoors", "kunming");

        set("exits", ([
                "west" : __DIR__"xroad1",
                "east" : __DIR__"jinmafang",
        ]));
        set("objects", ([
                "/d/beijing/npc/ducha" : 1,
                "/d/beijing/npc/caifan" : 1,
                "/d/city/npc/bing" : 4,
                "/clone/npc/walker" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
