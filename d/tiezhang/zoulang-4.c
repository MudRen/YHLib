#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������һ�������ϡ������ƺ��и��ڰ���С�ݣ�����������һЩ������
LONG    );
        set("exits", ([ 
                "west" : __DIR__"zoulang-1",
                "north" : __DIR__"xxs",
        ]));

        create_door("north", "ľ��", "south", DOOR_CLOSED);

        set("no_clean_up", 0);

        setup();
}