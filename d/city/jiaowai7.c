#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    	set("short", "�ݵ�");
    	set("long", @LONG
�������ݽ����һƬ���ݵأ���Ӣ�ͷף������裬��¶
Ϧ�⣬������Ƣ������̤��Զ���ʱ�⡣
LONG);
        set("outdoors", "city");
    	set("exits", ([
        	"east" : __DIR__"jiaowai6",
        	"west" : __DIR__"nanmen",
    	]));
    	set("no_clean_up", 0);
    	setup();

        replace_program(ROOM);
}
