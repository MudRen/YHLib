#include <ansi.h>

inherit ROOM;

int is_chat_room() { return 1; } 

void create()
{
        set("short",HIG "������" NOR);
	set("long", @LONG
�����Ƿ���ġ������á�������Դ�����Ľ�����񿴳������
���˶��صķ��
LONG
	);

	set("exits", ([ 
                        "out" : __DIR__"fiveroom",
        ]));

        set("sleep_room",1);   
	setup();
}
