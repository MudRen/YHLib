inherit ROOM;

void create()
{
        set("short", "�ප");
        set("long", @LONG
������һ��СС�Ĳප������������ױ̨���ϱ����ҵİ�
����ЩŮ�˵���Ʒ��
LONG);
        set("exits", ([
                "east" : __DIR__"dongnei",
        ]));
        set("objects", ([
                __DIR__"npc/jinhua" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
