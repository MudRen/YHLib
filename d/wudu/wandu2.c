#include <ansi.h> 
inherit ROOM;

string* npcs = ({
        "/clone/worm/xixuezhu",
        "/clone/worm/renmianzhu",
        "/clone/worm/tianwu",
        "/clone/worm/jiuweixie",
        "/clone/worm/shishixie",
        "/clone/worm/tieguxie",
        "/clone/worm/heiguafu",
        "/clone/worm/jinxianwugong",
});

void create()
{
        set("short", RED "�򶾿�" NOR);
        set("long", @LONG
������һ����Ȼ�γɵ�ʯ�������������󡣶��������������
��ʯ����ʱ���������δ��ˮ�������ڶ��У�����������ʪ�����Ժ�
Ȼ����һ�����С��������������ƺ����и�Сһ���֧����
LONG);

        set("exits", ([
                "south" : __DIR__"wandu3",
                "north" : __DIR__"wandu1",
        ]));
        set("objects", ([
                npcs[random(sizeof(npcs))] : 1,
                npcs[random(sizeof(npcs))] : 1,
        ]));
    

        setup();
        replace_program(ROOM);
}
