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
        set("exits",([
                "north" : __DIR__"songlin4",
                "south" : __DIR__"slxl2",
        ]));
        setup();
        replace_program(ROOM);
}
