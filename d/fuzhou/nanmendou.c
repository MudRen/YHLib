inherit ROOM;

void create()
{
        set("short", "���Ŷ�");
        set("long", @LONG
���Ŷ�����һ��޴���ţ�����Ҷï��Ũ���ڸ���Ķ����
�����ֿ��ڱ���ʵ��©�չ⡣�������³�������Ϊ���ʡ�
LONG);
        set("exits", ([
                "north"  : __DIR__"nandajie",
                "south"  : __DIR__"nanmen",
                "west"   : __DIR__"shiqiao",
                "east"   : __DIR__"xiaochang",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

