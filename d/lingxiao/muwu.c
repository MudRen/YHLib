#include <room.h>

inherit ROOM;

void create()
{
        set("short", "ľ��");
        set("long", @LONG
���������ǵ����ڳ���Ѳ�߻�ɽ��������ÿ�춼��ѩɽ����
�������Ա��������ǰ�ȫ�徻��������ƾ�������������е���ͷ,
һ����С֮��Ҳ�������˵���
LONG );
        set("exits", ([
                "west" : __DIR__"sroad6",
        ]));

        set("objects", ([
                CLASS_D("lingxiao") + "/wangwanren" : 1,
        ]));

        create_door("west", "ľ��", "east", DOOR_CLOSED);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
} 

