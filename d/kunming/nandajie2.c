inherit ROOM;

void create()
{
        set("short",  "�ϴ��" );
        set("long", @LONG
��������������Ľֵ��ϣ������������ò����֣�����
��һ�ҿ͵꣬���Ǵ��ѡ��������ţ��Ա��ڸ�·����������
�洫����̸Ц�������϶���һ�Ҳ��̡�
LONG);
        set("outdoors", "kunming");
        set("exits", ([
                "south" : __DIR__"nanmen", 
                "north" : __DIR__"nandajie1",
                "west"  : __DIR__"kedian",
                "east"  : __DIR__"chapu",
        ]));
        set("objects", ([
                "/d/beijing/npc/girl2" : 1,
                "/clone/npc/walker" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
