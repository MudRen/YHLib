inherit ROOM;

void create()
{
        set("short",  "���չ�¥" );
        set("long", @LONG
����¥�ش����������ģ������������˶�������ͨ������
¥����һ���ӣ�������ƽ��������һ���˺���ȥ���������
�����ʣ��ϱ����ַǷ�����������������������
LONG);
        set("outdoors", "kunming");
        set("exits", ([
                "west" : __DIR__"jinmafang", 
                "east"  :__DIR__"bijifang",
                "south" :__DIR__"nandajie1",
                "north" :__DIR__"beidajie",
                "up"    :__DIR__"zhonglou",                           
        ]));

        set("objects", ([
                "/clone/npc/xunbu" : 1,
                "/d/beijing/npc/richman1" : 1,
        ]));                       
        setup();
        replace_program(ROOM);
}
