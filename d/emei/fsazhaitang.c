#include <room.h>
inherit ROOM;

void create()
{
        set("short", "ի��");
        set("long", @LONG
������Ƕ��Ҹ����ֵ�ի�á������ֱ����󣬵����ھ���
�Ӵ������ֵĵ��ӣ�ի�õ�Ҳ��С��ֻ�����ڰ����˳����Ĳ�
���ͳ��ʣ���λСʦ̫������æµ�Ų�����ի�����ϰ��˼���
����������������Լ���Ѽ����ζ��ʳ��������һ���š�
LONG);
        set("exits", ([
                "east"  : __DIR__"lingwenge",
                "north" : __DIR__"fsaxiuxishi",
        ]));
        create_door("north", "��", "south", DOOR_CLOSED);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
