inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������������������գ�������ֻ�о�������ǰ�󵽴�
������Ӱ��������һ�����������ã�������ӫӫ���׹⡣�㾪
��֮�䣬һ�Ų��ڸ����������ϣ�
LONG);
        set("objects", ([
                CLASS_D("wudang") + "/famu" : 1,
        ]));
        set("outdoors", "wudang");
        set("exits", ([
                "north"  : __DIR__"slxl2",
                "south"  : __DIR__"songlin3",
        ]));
        setup();
        replace_program(ROOM);
}
