#include <room.h>
inherit ROOM;

void create()
{
        set("short", "���ֶ�");
        set("long", @LONG
�ֽ��ϻ�����ֻ�����ҵ������ӣ�����������������С�𡣶���
������ϻ�����һ�顰®���Ƿ�ᡱ�������Ͽ̻�ͷ�裬�м�����
����Ĳ�ᣬ���ҷ������⣬���ͣ���������������������ɽ��·��
С·���������򶫡�
LONG);
        set("exits", ([
                "east" : __DIR__"cuiweiting",
                "west" : __DIR__"feilaifeng",
        ]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
