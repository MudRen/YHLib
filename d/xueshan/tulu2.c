inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
����һ�������۵���·��ȴ�����Ӵ���������ԭ�ıؾ�֮
·�����ߵ��Ĵ�����ϡ�ɼ�����������ͨ��ѩɽ�¡�
LONG );
        set("outdoors", "xuedao");
        set("exits", ([
                "east" : __DIR__"tulu1",
                "north" : __DIR__"tulu3",
                "west" : __DIR__"kedian",
        ]));
        setup();
        replace_program(ROOM);
}
