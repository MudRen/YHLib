inherit ROOM;

void create()
{
        set("short",  "������" );
        set("long", @LONG
������һ���ɾ������ȣ������濴ȥ���������͵���԰��
�ķ羰��ֻ�����ּ�ɽ��ʯ���滨��ݣ��������֮���ɡ�
LONG);
        set("exits", ([
                "west"   :__DIR__"xizoulang1",
                "east"   :__DIR__"wangfu1"
        ]));
        set("objects", ([
                "/d/zhongzhou/npc/jiading" : 2,
        ]));
        setup();
        replace_program(ROOM);         
}
