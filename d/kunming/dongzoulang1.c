inherit ROOM;

void create()
{
        set("short",  "������" );
        set("long", @LONG
������һ���ɾ������ȣ������濴ȥ���������͵���԰��
�ķ羰��ֻ�����ּ�ɽ��ʯ���滨��ݣ��������֮���ɡ�
LONG);
        set("exits", ([
                "west"   :__DIR__"dongzoulang",
                "east"   :__DIR__"xiangfan"
        ]));
        set("objects", ([
                "/d/zhongzhou/npc/jiading" : 1,
        ]));
        setup();
        replace_program(ROOM);         
}
