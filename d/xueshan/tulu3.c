inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
����һ�������۵���·�����������Զ�������߲�������
��һ��Ƭ����ˮ�⴦������������ʥ����
LONG);
        set("outdoors", "xuedao");
        set("exits", ([
                "south" : __DIR__"tulu2",
                "north" : __DIR__"shenghu",
        ]));
        setup();
}
