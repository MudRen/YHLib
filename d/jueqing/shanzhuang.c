#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����ɽׯ");
        set("long", @LONG
�˴����Ǿ���ɽׯ������ɽׯ��ӳ�ڴд����ľ֮�£���
�������鲼���������ˡ�ʱ�����˵Ļ���Ʈ��������������
����֮�������˲����Ŀ�������
LONG);
        set("outdoors", "jueqing");
        set("exits", ([
               "enter" : __DIR__"dating",
               "south" : __DIR__"shiban",
        ]));

        set("objects", ([
                __DIR__"npc/dizi1" : 4,
                __DIR__"npc/dizi2" : 4,
                CLASS_D("jueqing") + "/fan" : 1,
        ]));  

        set("no_clean_up", 0);

        setup();
}

int valid_leave(object me, string dir)
{
        object guard;

        if (dir != "enter"
           || ! objectp(guard = present("fan yiweng", this_object())))
                return ::valid_leave(me, dir);

        return guard->permit_pass(me, dir);
}

