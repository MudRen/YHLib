inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����������С·�ϣ�������;ɽ����Ӱ��������У���ʯ�߲���
�����е��ػ��泩�����볤�Ӵ˵ء����ϱ㵽�������ã����¾͵���
������
LONG);
        set("exits", ([
            "west"   : __DIR__"faxisi",
            "north"   : __DIR__"shanlu3",
            "eastdown" : __DIR__"shanlu5",
        ]));
        set("outdoors", "hangzhou");
        set("max_room", 4);
        setup();
        replace_program(ROOM);
}
