inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���������ڵĴ�������λ�е��ĸ�ɮ�ڸ������ۡ�������
�������ݵ䣬�������档
LONG);
        set("exits", ([
                "east"  : __DIR__"zoulang1",
                "west"  : __DIR__"zoulang2",
                "north" : __DIR__"cangjing",
                "south" : __DIR__"cangjingge",
        ]));
        setup();
        replace_program(ROOM);
}
