#include <ansi.h>

inherit ROOM;

int is_chat_room() { return 1; } 

void create()
{
	set("short",HIW "������Ϣ��" NOR);
	set("long", @LONG
�����ǡ���������־���ṩ����ҵ�������Ϣ�ң���������������������
����һ��С��԰��
LONG
	);

	set("exits", ([ 
                "down"  : __DIR__"thirdroom",
                "up"    : __DIR__"fiveroom",
                "south" : __DIR__"xiaohuayuan",
                "north" : __DIR__"lts",
        ]));

        set("objects",([ 
                "/clone/food/peanut":2, 
                "/clone/game/fxq":1, 
                "/d/taohua/obj/cha":2, 
        ])); 

        set("no_fight", 1);
	setup();
        replace_program(ROOM);
}
