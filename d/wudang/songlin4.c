inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������������������գ�������ֻ�о�������ǰ�󵽴�
������Ӱ��������һ�����������ã�������ӫӫ���׹⡣�㾪
��֮�䣬һ�Ų��ڸ����������ϣ�
LONG);
        set("outdoors", "wudang");
        set("objects", ([
                __DIR__"npc/xiao_louluo": 1,
        ]));
        set("exits", ([
                "south" : __DIR__"songlin2",
        ]));
        setup();
        replace_program(ROOM);
}
