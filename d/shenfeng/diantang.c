#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    	set("short", "����");
    	set("long", @LONG
�ߵ����֮�󣬼���һ����С�ĵ��ã������龰ȴ��Ϊ��
������ʮ�ߺ���һ�Ѷ��໥���ᣬ���Ǵ�ֱ������ʱ���е�
�������б��У��е�ȴ�ǿ��֡�������һ��Сʯ�š�
LONG);
        set("objects", ([
                __DIR__"obj/yudao" : random(2),
                __DIR__"obj/yujian" : random(2),
                __DIR__"obj/skeleton" : random(3) + 1,
	]));

        set("exits", ([ 
        	"south" : __DIR__"dadian",
        	"west" : __DIR__"yushi",
    	]));
    	create_door("west", WHT "Сʯ��" NOR, "east", DOOR_CLOSED);
    	setup();
    	replace_program(ROOM);
}
