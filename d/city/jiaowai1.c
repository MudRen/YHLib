#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    	set("short", "�ݵ�");
    	set("long", @LONG
�������ݽ����һƬ���ݵأ���Ӣ�ͷף������裬��¶
Ϧ�⣬������Ƣ�����Ǻ�ʱ�⡣ż�м���С��Ů���̤�࣬ݺ
����Ӱ�����ֶ��ˡ�
LONG);
        set("outdoors", "city");
    	set("exits", ([
        	"north" : __DIR__"dongmen",
        	"south" : __DIR__"jiaowai2",
    	]));

    	set("quarrys", ([
                "caihuashe" : 100000,
                "dushe"     : 50000,
                "lang"      : 20000,
    	]));

    	set("no_clean_up", 0);
    	setup();

        replace_program(ROOM);
}

